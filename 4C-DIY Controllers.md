# 4C. DIY Controllers
**(The really intricate path)**

DIY Controllers are challenging, not solely due to their intricacy, but due to the multitude of options and configurations available. This is also their advantage.

## GPIO vs HID Host vs Passthrough Host

The **GPIO** option makes things simpler. You connect inputs to your adapter and program them. However if you choose to use your adapter-controller for
anything non-Steel Battalion anything else it will require reprogramming.

The **HID Host** option is more complicated since it requires a separate microcontroller, you are creating a controller and then adapting it, same as with an Adapted Controller. This allows you to create custom controllers that can be used for Steel Battalion and on PC on whim. The advantage of the DIY option is that you are defining the HID protocol yourself and makes it easier for the adapter to read it.

The **SBC Passthrough Host** options is something I developed with SBCFirm2040-lite with help from Quant's code. U You have 2 or more GPIO controllers plugged into the RP2040 which acts as hub. You can also use an actual Steel Battalion Controller provided you have the usb adapter.

  
## DIY-GPIO Set-Up
<img width="607" height="405" alt="hidcrop direct" src="https://github.com/user-attachments/assets/c260270d-04dc-4729-8e29-54ca32ac81b1" />

DIY Inputs into an adapter.
**Hardware**<br/>
* One microcontroller (Teensy 4.1, HID Arduino, RP2040)
* Additional parts for creating your controller (switches, potentiometers, sensors, etc)
* Your microcontroller needs to have at least 14 digital pins and 7 analogue pins. If you need to use an additional microcontroller, you can either consider 
using I2C SCL and SDA lines, or using the DIY-SBC Passthrough set-up.

## DIY-HID Host Set-Up:
<img width="607" height="405" alt="hidcrop hid copy" src="https://github.com/user-attachments/assets/6db7aab0-1c86-403c-8354-b885c373c27c" />

DIY Controllers read by an adapter.
**Hardware**<br/>
* Adapter: One microcontroller (Teensy 4.1 with host or RP2040 with host)
* Custom HID Devices: At least one additional microcontroller (RP2040 or HID Arduino)
* Additional parts for creating your controller (switches, potentiometers, sensors, etc)
* Powered USB HUB (only required if you want to attach more than one device)

## DIY-SBC Passthrough Host Set-Up
<img width="607" height="405" alt="hidcrop sbchub" src="https://github.com/user-attachments/assets/83b24e33-bbb3-4991-bcb8-77555f6188b5" />

Emulated Steel Battalion Devices put into a HUB connected to an adapter. The Xbox cannot natively read USB-Hubs

**Hardware**<br/>
* Two or more DIY-GPIO Devices you've made
* One microcontroller (RP2040 with host cable/board running SBCFirm2040-lite)
* Powered USB HUB (since you are connecting more than one device)




## Necessary Inputs and the Microcontroller
Going back to [section 2](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/3-Controller%20Inputs.md), we can see the table that illustrates the inputs we need.

|Total |Analogue Inputs|Digital Inputs|
|---|---|---|
| Full Recreation|8| 62
| Simple Recreation|7|38
| Notes|| 


So how do we get that many digital inputs into one board? By using a matrix. You can turn 14 microcontroller pins into 49 inputs using a 7x7 keyboard matrix. Therefore, in theory you only need a board that has 14 digital pins and 7 analogue pins for a Simple Recreation of the controller.

Deciding on your adapter board becomes a bit clearer. Your goal is now

  1. Create a matrix of 7x7 (49 keys) and map each input, either directly doing Steel Battalion Inputs or detecting each key of a keyboard layout
  2. Mapping 7-8 analog inputs

**Teensy 4.1**<br/>
Teensy 4.1 has more than enough GPIO pins to handle all the Steel Battalion's inputs. It has 55 GPIO, 18 of which are analogue.

**Earlier Teensy Boards**<br/>
The earlier Teensy boards (1-3.6) cannot run ogx360_t4, but like the other microcontrollers they are also options for HID, they will typically have enough Digital and Analog Pins

However:
* When making an HID Joystick **I do not recommend using the teensyduino or QMK**  for configuration, This is because they force the Teensy into devices with Mouse+Keyboard+Joystick endpoints, making them much more difficult for the adapters to read without more configuration, you will have to remove the endpoints from the library manually. QMK reduces the endpoints to 2 (Keyboard and Joystick)
* Keyboards made with QMK are an option however.


**RP2040**<br/>
The RP2040 boards will typically have enough digital pins, usually 26 or more, but only have 3-4 analogue pins (An exception to this is ESP32-PICO-KIT-1 which has 18 analogue pins.
). 
Therefore to handle the remaining inputs you will need to either:
* Use the USB HOST to bring in another HID device
* Add another microcontroller and connect to the first via i2c
* Use a multiplexer or shift register

**Arduino**<br/>
There are many HID arduinos. Typically they will have 14 to 20 or more digital pins. At minimum it will have 6 analogue pins, but some have more such as the Arduino Leonardo which has 12.

If a single arduino board lacks enough GPIO pins, your choices are:
* Add another microcontroller and connect to the first via i2c
* Use a multiplexer or shift register

You then have a choice between separating the blocks into 2 or more micro controllers and using a HUB to bring them together or consolidating into one micro controller.

For the **GPIO Option** per [section 4A](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4A-Controller%20Adapters.md), I recommend either a: 
* Teensy 4.1 with og360_t4
* Raspberry Pi (RP2040) board running SBCFirm2040-lite, having additional analog inputs via an expansion board.
* An HID Arduino (with at least 14 digital pins and 7-8 Analog pins) running OGXBOX-PAD

For the **HID Host Option** or **SBC Passthrough Host** I recommend 1 or 2 HID Arduinos with either Teensy 4.1 or RP2040 as the adapter board. 


[QMK firmware](https://qmk.fm/) reduces the endpoints to 2 (Keyboard and Joystick) while MMJoy...

  * The earlier Teensy boards if adapted with QMK or other Keyboard firmware are acceptable.



## HID Firmware

**Joystick**<br/>
* Arduino Joystick Libraries
* [MMJoy](https://github.com/MMjoy)
* 

* Arduino Keyboard Libraries
* [QMK firmware](https://qmk.fm/) reduces the endpoints to 2 (Keyboard and Joystick) while MMJoy...


As a pr


## Understanding GPIO Inputs and Firmware.


## 3D Printable Joysticks

## Keyboard Matrix and Mounting



### Links

https://github.com/gsmrana/USB-HID-Analyzer/releases/tag/v1.0.0

https://www.freebsddiary.org/APC/usb_hid_usages.php

