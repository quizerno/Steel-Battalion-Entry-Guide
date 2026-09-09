# 4C. DIY Controllers
**(The really intricate path)**

DIY Controllers are difficult, not solely due to their intricacy, but due to the multitude of options and configurations available.

Per [section 4A](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4A-Controller%20Adapters.md), I recommend either a 
* Teensy 4.1 with og360_t4
* Raspberry Pi (RP2040) board running SBCFirm2040-lite, having additional analog inputs via an expansion board.
* An HID Arduino (with at least 14 digital pins and 7-8 Analog pins) running OGXBOX-PAD
  
## Necessary Inputs
Going back to [section 2](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/3-Controller%20Inputs.md), we can see the table that illustrates the inputs we need.

|Total |Analogue Inputs|Digital Inputs|
|---|---|---|
| Full Recreation|8| 62
| Simple Recreation|7|38
| Notes|| 


So how do we get that many digital inputs into one board? By using a matrix. You can turn 14 microcontroller pins into 49 inputs using a 7x7 keyboard matrix. Therefore, in theory you only need a board that has 14 digital pins and 7 analogue pins for a Simple Recreation of the controller.

Deciding on your adapter board becomes a bit clearer. Your options are now

  1. Create a matrix of 49 keys and map each input, either directly or detecting each key of a keyboard layout
  2. Mapping 7-8 analog inputs

**Teensy 4.1**<br/>
Teensy 4.1 has more than enough GPIO pins to handle all the Steel Battalion's inputs. It has 55 GPIO, 18 of which are analogue.

**RP2040**<br/>
The RP2040 has enough digital pins, but only has 3-4 analogue pins. Therefore you will need to either:
* Use the USB to bring in another HID device
* Add another microcontroller and add it via i2c
* Use a multiplexer or shift register

**Arduino**<br/>
There are many arduinos


You then have a choice between separating the blocks into 2 or more micro controllers and using a HUB to bring them together or consolidating into one micro controller.



## DIY-HID Set-Up:
<img width="607" height="405" alt="hidcrop hid copy" src="https://github.com/user-attachments/assets/6db7aab0-1c86-403c-8354-b885c373c27c" />

**Hardware**<br/>
* Adapter: One microcontroller (Teensy 4.1 with host or RP2040 with host)
* Custom HID Devices: At least one additional microcontroller (RP2040 or HID Arduino)
* Additional parts for creating your controller (switches, potentiometers, sensors, etc)
* Powered USB HUB (only required if you want to attach more than one device)


## DIY-GPIO Set-Up
<img width="607" height="405" alt="hidcrop direct" src="https://github.com/user-attachments/assets/c260270d-04dc-4729-8e29-54ca32ac81b1" />

**Hardware**<br/>
* One microcontroller (Teensy 4.1, HID Arduino, RP2040)
* Additional parts for creating your controller (switches, potentiometers, sensors, etc)

Your microcontroller needs to have at least 14 digital pins and 7 analogue pins. If you need to use an additional microcontroller, you can either consider 
using I2C SCL and SDA lines, or using the DIY-SBC HUB set-up.




## DIY-SBC HUB Set-Up
<img width="607" height="405" alt="hidcrop sbchub" src="https://github.com/user-attachments/assets/83b24e33-bbb3-4991-bcb8-77555f6188b5" />

**Hardware**<br/>
* Any DIY-GPIO Devices you've made
* One microcontroller (Teensy 4.1 with host or RP2040 with host)
* Powered USB HUB (since you are connecting more than one device)


## Hybrid Set-Up







## Understanding HID codes

Most USB devices have specific usages.




### Links

https://github.com/gsmrana/USB-HID-Analyzer/releases/tag/v1.0.0

https://www.freebsddiary.org/APC/usb_hid_usages.php

