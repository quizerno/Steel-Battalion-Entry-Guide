# 4C. DIY Controllers
**(The really intricate path)**

DIY Controllers are challenging, not solely due to their intricacy, but due to the multitude of options and configurations available. This however, is also their advantage.

## GPIO vs HID

The GPIO option makes things simpler. You connect inputs to your adapter and program them. However if you choose to use your adapter for
anything non-Steel Battalion anything else it will require reprogramming.

The HID option is more complicated since it requires a separate microcontroller. But it allows you to create custom controllers that can be used for Steel Battalion and on PC on whim.
As with the Adapted Controllers, understanding the the HID codes is important to getting your DIY Controller to work with Steel Battalion. The advantage of the DIY option is that you are defining the HID firmware and makes it easier for the adapter to read it.

For both options arduino and RP2040 libraries for joysticks are quite simple to understand.
  
## Necessary Inputs and the Microcontroller
Going back to [section 2](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/3-Controller%20Inputs.md), we can see the table that illustrates the inputs we need.

|Total |Analogue Inputs|Digital Inputs|
|---|---|---|
| Full Recreation|8| 62
| Simple Recreation|7|38
| Notes|| 


So how do we get that many digital inputs into one board? By using a matrix. You can turn 14 microcontroller pins into 49 inputs using a 7x7 keyboard matrix. Therefore, in theory you only need a board that has 14 digital pins and 7 analogue pins for a Simple Recreation of the controller.

Deciding on your adapter board becomes a bit clearer. Your goal is now

  1. Create a matrix of 7x7 (49 keys) and map each input, either directly or detecting each key of a keyboard layout
  2. Mapping 7-8 analog inputs

**Teensy 4.1**<br/>
Teensy 4.1 has more than enough GPIO pins to handle all the Steel Battalion's inputs. It has 55 GPIO, 18 of which are analogue.

**RP2040**<br/>
The RP2040 boards will typically have enough digital pins, usually 26 or more, but only have 3-4 analogue pins (An exception to this is ESP32-PICO-KIT-1 which has 18 analogue pins.
). 
Therefore to handle the remaining inputs you will need to either:
* Use the USB HOST to bring in another HID device
* Add another microcontroller and connect to the first via i2c
* Use a multiplexer or shift register

**Arduino**<br/>
There are many arduinos. Typically they will have 14 to 20 or more digital pins. At minimum it will have 6 analogue pins, but some have more such as the Arduino Leonardo which has 12.

If a single arduino board lacks enough GPIO pins, your choices are:
* Add another microcontroller and connect to the first via i2c
* Use a multiplexer or shift register

You then have a choice between separating the blocks into 2 or more micro controllers and using a HUB to bring them together or consolidating into one micro controller.

For the **GPIO Option** per [section 4A](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4A-Controller%20Adapters.md), I recommend either a: 
* Teensy 4.1 with og360_t4
* Raspberry Pi (RP2040) board running SBCFirm2040-lite, having additional analog inputs via an expansion board.
* An HID Arduino (with at least 14 digital pins and 7-8 Analog pins) running OGXBOX-PAD

For the **HID Option** I recommend 1 or 2 HID Arduinos with either Teensy 4.1 or RP2040 as the adapter board. 

The earlier Teensy boards are also options for HID, however **I do not recommend using the teensyduino** libraries for the core configuration.
This is because they force the Teensy into devices with Mouse+Keyboard+Joystick endpoints, making them much more difficult for the adapter to read. 
[QMK firmware](https://qmk.fm/) reduces the endpoints to 2 (Keyboard and Joystick) while MMJoy...



## DIY-HID Set-Up:
<img width="607" height="405" alt="hidcrop hid copy" src="https://github.com/user-attachments/assets/6db7aab0-1c86-403c-8354-b885c373c27c" />

DIY Controllers read by an adapter.
**Hardware**<br/>
* Adapter: One microcontroller (Teensy 4.1 with host or RP2040 with host)
* Custom HID Devices: At least one additional microcontroller (RP2040 or HID Arduino)
* Additional parts for creating your controller (switches, potentiometers, sensors, etc)
* Powered USB HUB (only required if you want to attach more than one device)


## DIY-GPIO Set-Up
<img width="607" height="405" alt="hidcrop direct" src="https://github.com/user-attachments/assets/c260270d-04dc-4729-8e29-54ca32ac81b1" />

DIY Inputs into an adapter.
**Hardware**<br/>
* One microcontroller (Teensy 4.1, HID Arduino, RP2040)
* Additional parts for creating your controller (switches, potentiometers, sensors, etc)
* Your microcontroller needs to have at least 14 digital pins and 7 analogue pins. If you need to use an additional microcontroller, you can either consider 
using I2C SCL and SDA lines, or using the DIY-SBC HUB set-up.

## DIY-SBC HUB Set-Up
<img width="607" height="405" alt="hidcrop sbchub" src="https://github.com/user-attachments/assets/83b24e33-bbb3-4991-bcb8-77555f6188b5" />

Emulated Steel Battalion Devices put into a HUB connected to an adapter. The Xbox cannot natively read USB-Hubs

**Hardware**<br/>
* Any DIY-GPIO Devices you've made
* One microcontroller (RP2040 with host cable/board running SBCFirm2040-lite)
* Powered USB HUB (since you are connecting more than one device)





## Understanding HID Codes and Firmware


If you want something that requires less coding, you can consider [MMJoy](https://github.com/MMjoy) which is a custom firmware that you can upload to arduinos.

As a pr


## Understanding GPIO Inputs and Firmware.


## 3D Printable Joysticks

## Keyboard Matrix and Mounting



### Links

https://github.com/gsmrana/USB-HID-Analyzer/releases/tag/v1.0.0

https://www.freebsddiary.org/APC/usb_hid_usages.php

