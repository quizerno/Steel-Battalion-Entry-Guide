#include <Arduino.h>
#include <tusb.h>
#include <USBHost_t36.h>
#include <printf.h>
#include "usbd_top.h"


//edited with HOTAS configuration
//rename this file to main.cpp before you build

//Forward declarations
#if (XID_DUKE >= 1)
void duke_init(KeyboardController *kb, MouseController *m, JoystickController *joy);
void duke_task(uint8_t type_index, KeyboardController *kb, MouseController *m, JoystickController *joy);
#endif

#if (XID_STEELBATTALION >= 1)
void steelbattalion_init(KeyboardController *kb, MouseController *m, JoystickController *gunfighter, JoystickController *stecsjoy);
void steelbattalion_task(uint8_t type_index, KeyboardController *kb, MouseController *m, JoystickController *gunfighter, JoystickController *stecsjoy);
#endif

#if (XID_XREMOTE >= 1)
void xremote_init(KeyboardController *kb, MouseController *m, JoystickController *joy);
void xremote_task(uint8_t type_index, KeyboardController *kb, MouseController *m, JoystickController *joy);
#endif

#if (MSC_XMU >= 1)
void xmu_init(void);
void xmu_task(uint8_t type_index);
#endif

//USB Host Interface
USBHost usbh;
USBHub hub1(usbh);
USBHIDParser hid(usbh), hid2(usbh), hid3(usbh);
KeyboardController keyboard(usbh);
MouseController mouse(usbh);

// Local filtered joystick class: only claim devices that match a specific VID/PID.
// This ensures each JoystickController instance attaches only to its assigned device at enumeration time.
class FilteredJoystick : public JoystickController {
  public:
    FilteredJoystick(USBHost &host, uint16_t vid, uint16_t pid)
      : JoystickController(host), want_vid(vid), want_pid(pid) {}
  protected:
    virtual bool claim(Device_t *dev, int type, const uint8_t *descriptors, uint32_t len) override {
      if (dev == nullptr) return false;
      if ((dev->idVendor != want_vid) || (dev->idProduct != want_pid)) return false;
      return JoystickController::claim(dev, type, descriptors, len);
    }
  private:
    uint16_t want_vid;
    uint16_t want_pid;
};

// Instantiate filtered joystick controllers bound to specific VID/PID pairs (enumeration-only matching)
FilteredJoystick gunfighter(usbh, 0x231D, 0x0125); // Gunfighter
FilteredJoystick stecsjoy(usbh, 0x231D, 0x0136);   // STECS
// JoystickController stecsjoy(usbh);
RawHIDController raw_hid(usbh), raw_hid2(usbh), raw_hid3(usbh);
// RawHIDController raw_hid2(usbh);

void _putchar(char character)
{
    Serial1.write(character);
    Serial1.flush();
}

void usbd_isr(void)
{
    tud_int_handler(0);
}

void setup()
{
    Serial1.begin(115200);
    printf("ogx360_t4 Starting!\n");

    //Set onboard LED to output
    pinMode(LED_BUILTIN, OUTPUT);

#if (XID_DUKE >= 1)
    duke_init(&keyboard, &mouse);
#endif

#if (XID_STEELBATTALION >= 1)
    steelbattalion_init(&keyboard, &mouse, &gunfighter, &stecsjoy);
#endif

#if (XID_XREMOTE >= 1)
    xremote_init(&keyboard, &mouse,);
#endif

#if (MSC_XMU >= 1)
    xmu_init();
#endif

    //USB Device Interface Init
    NVIC_DISABLE_IRQ(IRQ_USB1);
    USB1_USBCMD |= USB_USBCMD_RST;
    while (USB1_USBCMD & USB_USBCMD_RST);
    NVIC_CLEAR_PENDING(IRQ_USB1);
    delay(10);
    attachInterruptVector(IRQ_USB1, &usbd_isr);
    NVIC_ENABLE_IRQ(IRQ_USB1);
    tusb_init();
     //Force Full Speed Only
    USB1_PORTSC1 = USB_PORTSC1_PFSC;
    printf("USB Device Stack Initialised\r\n");

    //USB Host Interface Init
    usbh.begin();
    printf("USB Host Stack Initialised\r\n");
}

void loop()
{
    tud_task();
    usbh.Task(); // Process USB host events and device enumeration

#if (XID_DUKE >= 1)
    duke_task(0, &keyboard, &mouse);
#endif

#if (XID_STEELBATTALION >= 1)
    steelbattalion_task(0, &keyboard, &mouse, &gunfighter, &stecsjoy);
#endif

#if (XID_XREMOTE >= 1)
    xremote_task(0, &keyboard, &mouse, &joy);
#endif

#if (MSC_XMU >= 1)
    xmu_task(0);
#endif
}
