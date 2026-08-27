# 3B. OGX-MINI-2026
[OGX-Mini-2026](https://github.com/MegaCadeDev/OGX-Mini-2026
) is a fork of the original [OGX-Mini](https://github.com/wiredopposite/OGX-Mini
), it allows modern controllers to interact with older consoles. It includes the tinyUSB xid library for Steel Battalion.

It unfortunately does not have keyboard support since it lacks a driver, and also does not have USB Hub support. But it does have drivers for quite a few joysticks and other HID devices.

## Soldering the Host Cable to the RP2040
This will be dependent on your board. The original repository has some [examples of the wiring.
](https://github.com/MegaCadeDev/OGX-Mini-2026/tree/master/hardware).




## Building the firmware
Build in Linux or WSL, using these instructions.

```
git clone --recurse-submodules https://github.com/MegaCadeDev/OGX-Mini-2026
cd OXG-Mini-2026/Firmware/external
git clone --recurse-submodules https://github.com/RaspberryPi/pico-sdk
mkdir ../RP2040/build
cd ../RP2040/build
cmake -DOGXM_BOARD=[BOARD OPTION] -DOGXM_FIXED_DRIVER=[CONTROLLER OPTION] -DCMAKE_BUILD_TYPE=[Debug or Release] ..
make 
```
In the field [BOARD OPTION], substitute which board you have and want to build for.

```
BOARDS=(
  "PI_PICO:Pi Pico"
  "PI_PICO2:Pi Pico 2"
  "PI_PICOW:Pi Pico W"
  "PI_PICO2W:Pi Pico 2 W"
  "RP2040_ZERO:Waveshare RP2040-Zero"
  "RP2350_ZERO:Waveshare RP2350-Zero"
  "RP2350_USB_A:Waveshare RP2350-USB-A"
  "RP2040_XIAO:Seeed Studio XIAO RP2040"
  "RP2354:RP2354 (RP2350 + Pi Radio Module 2 — BT + PIO USB host GP0/GP1)"
  "ADAFRUIT_FEATHER:Adafruit Feather USB Host"
  "EXTERNAL_4CH_I2C:External 4CH I2C"
  "ESP32_BLUEPAD32_I2C:ESP32 Bluepad32 I2C"
  "ESP32_BLUERETRO_I2C:ESP32 BlueRetro I2C"
)
```
In [CONTROLLER OPTION], substitute which controller you wish to use. If you do not use this option, it will result in a combo mode where the you have to use a button combination to switch to Xbox input mode.

```
FIXED_DRIVERS=(
  "XINPUT:Xbox 360 (XInput)"
  "XBOXOG:Original Xbox (Gamepad)"
  "XBOXOG_SB:Steel Battalion Controller";
  "XBOXOG_XR:Original Xbox (Remote)";
  "PS3:PlayStation 3"
  "SWITCH:Nintendo Switch Pro"
  "WIIU:Wii U (GameCube Adapter)"
  "WII:Wii (Wiimote)"
  "PS1PS2:PlayStation 1/2 (GPIO)"
  "GAMECUBE:GameCube (GPIO)"
  "DREAMCAST:Dreamcast (GPIO)"
  "N64:Nintendo 64 (GPIO)"
  "DINPUT:DInput"
  "PS4:PlayStation 4 (DualShock 4 USB)"
  "STEAM:SteamOS / Bazzite (DualSense + touchpad mouse)"
  "PSCLASSIC:PlayStation Classic"
  "WEBAPP:Web App"
```

The last field, [Debug or Release], put "Release"

In my case I wanted to build for the Pico, Fixed for Steel Battalion Controller Driver, in release mode.

```
cmake -DOGXM_BOARD=PI_PICO -DOGXM_FIXED_DRIVER=XBOXOG_SB -DCMAKE_BUILD_TYPE=Release ..
```
Press then type 
```
make
```
and press enter. Verify that firmware file (.uf2) was created.

## Flashing the Firmware
Holding down on the BOOT SELECT button, plug the RP2040 board into the computer. This will connect the board in flash mode.
Simply drag and drop the uf2 file to the board.

## Default Configuration
By default, OGX-MINI's configuration defaults to this control scheme using the Xbox 360+Chatpad
<img width="975" height="965" alt="image" src="https://github.com/user-attachments/assets/7d95fc88-7829-45cb-86cd-088762b4ac45" />


## Other Configurations
Development of OGX-Mini-2026 is currently in a state of limbo, so adding new different devices must be done independently. For the devices it does provide however you can attempt to match code to Steel Battalion's configuration. The bindings are located in [device driver folder for the original Xbox](https://github.com/MegaCadeDev/OGX-Mini-2026/blob/master/Firmware/RP2040/src/USBDevice/DeviceDriver/XboxOG/XboxOG_SB.cpp).
