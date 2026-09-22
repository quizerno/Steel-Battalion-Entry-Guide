#include <Arduino.h>
#include <tusb.h>
#include <USBHost_t36.h>
#include "xid.h"

//Steel Battalion HOTAS Input Configuration for ogx360_t4
//Provided by Gnomp
//For building, you must
//1. Rename this file to steelbattalion.cpp and put it in the src folder
//2. You MUST also include the altered main.cpp file

//USB Device Interface
static USB_SteelBattalion_InReport_t sb_data;
static USB_SteelBattalion_OutReport_t sb_feedback;
static uint8_t kcode[256];

static void key_pressed_cb(uint8_t keycode)
{
    TU_LOG1("Key pressed %u\r\n", keycode);
    kcode[keycode] = 0xFF;
}

static void key_released_cb(uint8_t keycode)
{
    TU_LOG1("Key released %u\r\n", keycode);
    kcode[keycode] = 0x00;
}

static uint8_t is_key_pressed(uint16_t k, uint8_t clear)
{
    uint8_t key = k & 0xFF;
    uint8_t pressed = kcode[key];

    //If clear, the input will be cleared. This allows event based handling
    if (clear)
        kcode[key] = 0x00;

    return pressed;
}

int32_t map_axis_to_sight_change(int axis_val, int center, int deadzone, int min_val, int max_val, int min_out, int max_out) {
    int32_t delta = axis_val - center;

    if (abs(delta) < deadzone) {
        return 0;
    }

    if (delta > 0) {
        // Map positive range
        int32_t mapped_val = map(delta, deadzone, max_val - center, min_out, max_out);
        return constrain(mapped_val, min_out, max_out);
    } else {
        // Map negative range
        int32_t mapped_val = map(delta, -(max_val - center), -deadzone, -max_out, -min_out);
        return constrain(mapped_val, -max_out, -min_out);
    }
}

void steelbattalion_init(KeyboardController *kb, MouseController *m, JoystickController *gunfighter, JoystickController *stecsjoy)
{
    memset(&sb_data, 0x00, sizeof(sb_data));
    sb_data.bLength = sizeof(sb_data);
    sb_data.gearLever = 7;
    kb->attachRawPress(key_pressed_cb);
    kb->attachRawRelease(key_released_cb);
}

void steelbattalion_task(uint8_t type_index, KeyboardController *kb, MouseController *m, JoystickController *gunfighter, JoystickController *stecsjoy)
{
    static uint32_t prev_stecs_buttons = 0;
    uint8_t index = xid_get_index_by_type(type_index, XID_TYPE_STEELBATTALION);

    if (xid_send_report_ready(index))
    {
        sb_data.dButtons[0]   = 0x0000;
        sb_data.dButtons[1]   = 0x0000;
        sb_data.dButtons[2]  &= 0xFFFC; //Need to only clear the two LSBs. The other bits are the toggle switches
        sb_data.rotationLever = 0x0000;
        sb_data.sightChangeX  = 0x0000;
        sb_data.sightChangeY  = 0x0000;
        sb_data.rightPedal    = 0x0000;
        sb_data.middlePedal   = 0x0000;
        sb_data.leftPedal     = 0x0000;

        // if (m->available())
        // {
        //     int32_t x, y;
        //     x = sb_data.aimingX + m->getMouseX() * 100;
        //     y = sb_data.aimingY + m->getMouseY() * 100;
        //     if (x < 13000) x = 13000;
        //     if (x > 51000) x = 51000;
        //     if (y < 13000) y = 13000;
        //     if (y > 51050) y = 51050;
        //     sb_data.aimingX = x;
        //     sb_data.aimingY = y;
        //     //TU_LOG1("X: %i Y: %i, mX: %i, mY: %i\r\n", sb_data.aimingX, sb_data.aimingY, m->getMouseX(), m->getMouseY());
        //     m->mouseDataClear();
        // }

        // if (sb_data.aimingX > 50000)          sb_data.sightChangeX = 8000;
        // if (sb_data.aimingX < 14000)          sb_data.sightChangeX = -8000;
        // if (sb_data.aimingY > 50000)          sb_data.sightChangeY = 8000;
        // if (sb_data.aimingY < 14000)          sb_data.sightChangeY = -8000;

        uint32_t current_stecs_buttons = stecsjoy->getButtons();
        if ((current_stecs_buttons & (1 << 12)) && !(prev_stecs_buttons & (1 << 12)))  sb_data.gearLever -= (sb_data.gearLever > 7) ? 1 : 0;
        if ((current_stecs_buttons & (1 << 11)) && !(prev_stecs_buttons & (1 << 11)))  sb_data.gearLever += (sb_data.gearLever < 13) ? 1 : 0;
        prev_stecs_buttons = current_stecs_buttons;        

        if (is_key_pressed(KEY_W, 0))         sb_data.rightPedal  = 0xFFFF;
        if (is_key_pressed(KEY_S, 0))         sb_data.middlePedal = 0xFFFF;
        if (is_key_pressed(KEY_SPACE, 0))     sb_data.leftPedal = 0xFFFF;
        if (is_key_pressed(KEY_A, 0))         sb_data.rotationLever = INT16_MIN;
        if (is_key_pressed(KEY_D, 0))         sb_data.rotationLever = INT16_MAX;

        if (is_key_pressed(KEY_Q, 1))         sb_data.gearLever -= (sb_data.gearLever > 7) ? 1 : 0;
        if (is_key_pressed(KEY_E, 1))         sb_data.gearLever += (sb_data.gearLever < 13) ? 1 : 0;

        if (is_key_pressed(KEY_R, 0))         sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_WEAPONCONMAGAZINE;
        if (is_key_pressed(KEY_F, 0))         sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_EXTINGUISHER;
        if (is_key_pressed(KEY_TAB, 0))       sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_CHAFF;
        if (is_key_pressed(KEY_C, 0))         sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_WASHING;
        if (is_key_pressed(KEY_F1, 0))        sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_FUNCTIONF1;
        if (is_key_pressed(KEY_F2, 0))        sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_FUNCTIONF2;
        if (is_key_pressed(KEY_F3, 0))        sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_FUNCTIONF3;
        if (is_key_pressed(KEY_F4, 0))        sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_FUNCTIONTANKDETACH;
        if (is_key_pressed(KEY_F5, 0))        sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_FUNCTIONOVERRIDE;
        if (is_key_pressed(KEY_F6, 0))        sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_FUNCTIONNIGHTSCOPE;
        if (is_key_pressed(KEY_F7, 0))        sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_FUNCTIONFSS;
        if (is_key_pressed(KEY_F8, 0))        sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_FUNCTIONMANIPULATOR;
        if (is_key_pressed(KEY_F9, 0))        sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_FUNCTIONLINECOLORCHANGE;

        if (is_key_pressed(KEY_6, 0))     sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_COMM1;
        if (is_key_pressed(KEY_7, 0))     sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_COMM2;
        if (is_key_pressed(KEY_8, 0))     sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_COMM3;
        if (is_key_pressed(KEY_9, 0))     sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_COMM4;
        if (is_key_pressed(KEY_0, 0))     sb_data.dButtons[2] |= CXBX_SBC_GAMEPAD_W2_COMM5;
    
        if (is_key_pressed(KEY_1, 1))     sb_data.dButtons[2] ^= CXBX_SBC_GAMEPAD_W2_TOGGLEOXYGENSUPPLY;
        if (is_key_pressed(KEY_2, 1))     sb_data.dButtons[2] ^= CXBX_SBC_GAMEPAD_W2_TOGGLEFILTERCONTROL;
        if (is_key_pressed(KEY_3, 1))     sb_data.dButtons[2] ^= CXBX_SBC_GAMEPAD_W2_TOGGLEFUELFLOWRATE;
        if (is_key_pressed(KEY_4, 1))     sb_data.dButtons[2] ^= CXBX_SBC_GAMEPAD_W2_TOGGLEBUFFREMATERIAL;
        if (is_key_pressed(KEY_5, 1))     sb_data.dButtons[2] ^= CXBX_SBC_GAMEPAD_W2_TOGGLEVTLOCATION;
        //if (is_key_pressed(KEY_RIGHT, 1)) sb_data.dButtons[2] |=  0xFFFC; //All toggles on
        //if (is_key_pressed(KEY_LEFT, 1))  sb_data.dButtons[2] &= ~0xFFFC; //All tolgges off
        if (is_key_pressed(HID_KEY_KEYPAD_0, 1))  sb_data.dButtons[2] &= ~0xFFFC; //All tolgges off            
        if (is_key_pressed(KEY_LEFT, 0))  sb_data.sightChangeX = INT16_MIN;
        if (is_key_pressed(KEY_RIGHT, 0)) sb_data.sightChangeX = INT16_MAX;
        if (is_key_pressed(KEY_UP, 0))    sb_data.sightChangeY = INT16_MIN;
        if (is_key_pressed(KEY_DOWN, 0))  sb_data.sightChangeY = INT16_MAX;
\
        if (is_key_pressed(KEY_ESC, 0))       sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_EJECT;
        if (is_key_pressed(KEY_BACKSPACE, 0)) sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_EJECT;
        if (is_key_pressed(KEY_H, 0))         sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_COCKPITHATCH;
        if (is_key_pressed(KEY_BACKSLASH, 0)) sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_IGNITION;
        if (is_key_pressed(KEY_ENTER, 0))     sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_START;

        if (is_key_pressed(KEY_M, 0))         sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_MULTIMONOPENCLOSE;
        if (is_key_pressed(KEY_COMMA, 0))     sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_MAINMONZOOMOUT;
        if (is_key_pressed(KEY_PERIOD, 0))    sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_MAINMONZOOMIN;
        if (is_key_pressed(KEY_B, 0))         sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_MULTIMONMODESELECT;
        if (is_key_pressed(KEY_N, 0))         sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_MULTIMONSUBMONITOR;
        if (is_key_pressed(KEY_Z, 0))         sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_MULTIMONMAPZOOMINOUT;

        if (m->getWheel() > 0)                sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_WEAPONCONMAIN;
        if (m->getWheel() < 0)                sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_WEAPONCONSUB;


        if (m->getButtons() & (1 << 0))       sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_RIGHTJOYMAINWEAPON;
        if (m->getButtons() & (1 << 1))       sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_RIGHTJOYFIRE;
        if (m->getButtons() & (1 << 2))       sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_RIGHTJOYLOCKON;
        if (is_key_pressed(KEY_X, 0))         sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_RIGHTJOYLOCKON;


        if (gunfighter->available())
        {
            // Read X and Y axis from the joystick
            int32_t stickX = gunfighter->getAxis(0);
            int32_t stickY = gunfighter->getAxis(1);

            // Map the joystick's axis values (assuming a 0-4095 range) to the game's absolute aiming coordinates.
            // The Y-axis is inverted to match standard screen coordinates (up is a lower value).
            int32_t x = map(stickX, 0, 4095, 6000, 51000);
            int32_t y = map(stickY, 0, 4095, 51050, 6000); // Inverted Y-axis

            // Assign the calculated absolute position to the aiming data
            sb_data.aimingX = x;
            sb_data.aimingY = y;
            
            gunfighter->joystickDataClear();
        }

            //VKB DEVICE MAPPINGS
            //Gunfighter
            if (gunfighter->getButtons() & (1 << 0))       sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_RIGHTJOYMAINWEAPON;
            if (gunfighter->getButtons() & (1 << 2))       sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_RIGHTJOYFIRE;
            if (gunfighter->getButtons() & (1 << 14))      sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_RIGHTJOYLOCKON;
            if (gunfighter->getButtons() & (1 << 7))        sb_data.dButtons[2] |= CXBX_SBC_GAMEPAD_W2_LEFTJOYSIGHTCHANGE;

            if (gunfighter->getButtons() & (1 << 5))        sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_WEAPONCONMAIN;
            if (gunfighter->getButtons() & (1 << 4))        sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_WEAPONCONSUB;

            if (gunfighter->getButtons() & (1 << 13))        sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_CHAFF;
            if (gunfighter->getButtons() & (1 << 21))        sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_FUNCTIONFSS;
            if (gunfighter->getButtons() & (1 << 3))        sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_WEAPONCONMAGAZINE;
            if (gunfighter->getButtons() & (1 << 9))        sb_data.dButtons[1] |= CXBX_SBC_GAMEPAD_W1_FUNCTIONOVERRIDE;

            if (gunfighter->getAxis(2) <= 750)               sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_MAINMONZOOMIN;
            if (gunfighter->getAxis(2) >= 1300)               sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_MAINMONZOOMOUT;
                       

            // Set middle pedal if axis 7 exceeds threshold
            if (gunfighter->getAxis(7) > 100)              sb_data.middlePedal = 0xFFFF;

            sb_data.sightChangeX = map_axis_to_sight_change(gunfighter->getAxis(6), 1024, 100, 0, 2047, 0, 32767);
            sb_data.sightChangeY = map_axis_to_sight_change(gunfighter->getAxis(5), 1024, 100, 0, 2047, 0, 32767);

            


            //STECS
            if (stecsjoy->getButtons() & (1 << 8))     sb_data.leftPedal = 0xFFFF;


            if (stecsjoy->getButtons() & (1 << 1))     sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_EJECT;
            if (stecsjoy->getButtons() & (1 << 28))     sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_COCKPITHATCH;
            if (stecsjoy->getButtons() & (1 << 0))     sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_IGNITION;
            if (stecsjoy->getButtons() & (1 << 2))     sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_START;  
            
            if (stecsjoy->getButtons() & (1 << 26))      sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_MULTIMONOPENCLOSE;
            if (stecsjoy->getButtons() & (1 << 24))     sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_MULTIMONMODESELECT;
            if (stecsjoy->getButtons() & (1 << 23))     sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_MULTIMONSUBMONITOR;
            if (stecsjoy->getButtons() & (1 << 9))     sb_data.dButtons[0] |= CXBX_SBC_GAMEPAD_W0_MULTIMONMAPZOOMINOUT;            
            
            
            // Map STECS throttle (axis 2) to right pedal for acceleration.
            // The axis range is assumed to be 0-4095.
            // The output range is 0x0000 to 0xFF00 as per the struct definition.
            uint16_t throttle_val = map(stecsjoy->getAxis(2), 0, 4095, 0, 0xFF00);
            sb_data.rightPedal = throttle_val;

            int32_t rotation_val = stecsjoy->getAxis(0);
            const int32_t center = 2048;
            const int32_t deadzone = 200;
            if (abs(rotation_val - center) > deadzone)
            {
                sb_data.rotationLever = map(rotation_val, 0, 4095, -32767, 32767);
            }

            // Map STECS abs_RY (axis 4) to the tuner dial.
            // The axis range is 0-1023, and the tuner dial range is 0-15.
            int32_t tuner_val = stecsjoy->getAxis(4);
            sb_data.tunerDial = map(tuner_val, 0, 1023, 0, 15);


        


        if (!xid_send_report(index, &sb_data, sizeof(sb_data)))
        {
            TU_LOG1("[USBD] Error sending OUT report\r\n");
        }
    }

    if (xid_get_report(index, &sb_feedback, sizeof(sb_feedback)))
    {
        static uint32_t print_timer = 0;

        if (millis() - print_timer > 100)
        {
#if (0)
        printf( "%c[2J", 27); //Clear terminal
        printf( "%c[H", 27);  //Set cursor to home
        printf("CockpitHatch:   %02x EmergeEject:   %02x\r\n", (sb_feedback.CockpitHatch_EmergencyEject >> 4) & 0x0F,
                                                               (sb_feedback.CockpitHatch_EmergencyEject >> 0) & 0x0F);

        printf("Start:          %02x Ignition:      %02x\r\n", (sb_feedback.Start_Ignition >> 4) & 0x0F,
                                                               (sb_feedback.Start_Ignition >> 0) & 0x0F);

        printf("MapZoomInOut:   %02x OpenClose:     %02x\r\n", (sb_feedback.MapZoomInOut_OpenClose >> 4) & 0x0F,
                                                               (sb_feedback.MapZoomInOut_OpenClose >> 0) & 0x0F);

        printf("SubMonModeSel:  %02x ModeSelect:    %02x\r\n", (sb_feedback.SubMonitorModeSelect_ModeSelect >> 4) & 0x0F,
                                                               (sb_feedback.SubMonitorModeSelect_ModeSelect >> 0) & 0x0F);
        
        printf("MainMonZoomOut: %02x MainMonZoomIn: %02x\r\n", (sb_feedback.MainMonitorZoomOut_MainMonitorZoomIn >> 4) & 0x0F,
                                                               (sb_feedback.MainMonitorZoomOut_MainMonitorZoomIn >> 0) & 0x0F);

        printf("Manipulator:    %02x FSS:           %02x\r\n", (sb_feedback.Manipulator_ForecastShootingSystem >> 4) & 0x0F,
                                                               (sb_feedback.Manipulator_ForecastShootingSystem >> 0) & 0x0F);

        printf("Washing:        %02x LineColChange: %02x\r\n", (sb_feedback.Washing_LineColorChange >> 4) & 0x0F,
                                                               (sb_feedback.Washing_LineColorChange >> 0) & 0x0F);

        printf("Chaff:          %02x Extinguisher:  %02x\r\n", (sb_feedback.Chaff_Extinguisher >> 4) & 0x0F,
                                                               (sb_feedback.Chaff_Extinguisher >> 0) & 0x0F);

        printf("Override:       %02x TankDetach:    %02x\r\n", (sb_feedback.Override_TankDetach >> 4) & 0x0F,
                                                               (sb_feedback.Override_TankDetach >> 0) & 0x0F);

        printf("F1:             %02x NightScope:    %02x\r\n", (sb_feedback.F1_NightScope >> 4) & 0x0F,
                                                               (sb_feedback.F1_NightScope >> 0) & 0x0F);

        printf("F3:             %02x F2:            %02x\r\n", (sb_feedback.F3_F2 >> 4) & 0x0F,
                                                               (sb_feedback.F3_F2 >> 0) & 0x0F);

        printf("SubWeaponCtrl:  %02x MainWeapCtrl:  %02x\r\n", (sb_feedback.SubWeaponControl_MainWeaponControl >> 4) & 0x0F,
                                                               (sb_feedback.SubWeaponControl_MainWeaponControl >> 0) & 0x0F);

        printf("Comm1:          %02x MagChange:     %02x\r\n", (sb_feedback.Comm1_MagazineChange >> 4) & 0x0F,
                                                               (sb_feedback.Comm1_MagazineChange >> 0) & 0x0F);

        printf("Comm3:          %02x Comm2:         %02x\r\n", (sb_feedback.Comm3_Comm2 >> 4) & 0x0F,
                                                               (sb_feedback.Comm3_Comm2 >> 0) & 0x0F);

        printf("Comm5:          %02x Comm4:         %02x\r\n", (sb_feedback.Comm5_Comm4 >> 4) & 0x0F,
                                                               (sb_feedback.Comm5_Comm4 >> 0) & 0x0F);

        printf("GearR:          %02x Not used:      %02x\r\n", (sb_feedback.GearR_ >> 4) & 0x0F,
                                                               (sb_feedback.GearR_ >> 0) & 0x0F);

        printf("Gear1:          %02x GearN:         %02x\r\n", (sb_feedback.Gear1_GearN >> 4) & 0x0F,
                                                               (sb_feedback.Gear1_GearN >> 0) & 0x0F);

        printf("Gear3:          %02x Gear2:         %02x\r\n", (sb_feedback.Gear3_Gear2 >> 4) & 0x0F,
                                                               (sb_feedback.Gear3_Gear2 >> 0) & 0x0F);

        printf("Gear5:          %02x Gear4:         %02x\r\n", (sb_feedback.Gear5_Gear4 >> 4) & 0x0F,
                                                               (sb_feedback.Gear5_Gear4 >> 0) & 0x0F);
#endif
        print_timer = millis();
        }
    }
}
