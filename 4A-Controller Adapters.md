# 4A. Controller Adapters
(**The Hard Part**)

Here is a run-down of your options for controller adapters and firmware, and the specific hardware.

# Hardware

### Xbox Bridge Cable
You will need a cable that allows you to connect USB devices to the Xbox.  If you have done softmodding or hard modding before, you will likely have some experience with this.

|Hardware|Usage|Where to Buy|Price|
|---|---|---|---|
|USB-Female to Xbox Cable|Allows interfacing with the Original Xbox, also used for softmodding| [Ebay](https://www.ebay.com/itm/127869049454), [Amazon](https://www.amazon.com/dp/B076HHZ41Z?lv=shuf&channelId=500&plpRedirect=mhFallback) among other places, you can also build one if you have a spare Xbox breakaway cable and a female USB port| Around 5-11 USD|

**Notes:**
- In an upcoming section section you will choose hardware for the adapter board
  - If the adapter board uses USB-C you can use an Xbox to USB-C Cable.
  - If the adapter board uses Micro USB you can use an Xbox to Micro USB Cable.
  - etc

### USB Hub

A powered USB hub will be needed if you want to connect more than one device to the adapter board host. 
|Hardware|Usage|Where to Buy|Price|
|---|---|---|---|
|USB Hub|Connects multiple devices to one device, power adapter ensures that it will not draw too much voltage from the adapter board | [Ebay](https://www.ebay.com/itm/334645888588?_skw=powered+usb+hub&itmmeta=01KZV57C33Q88G3AG75GB9JZ8K&hash=item4dea73064c%3Ag%3AnHkAAOSw4TxjhH7O&itmprp=enc%3AAQALAAAA0GfYFPkwiKCW4ZNSs2u11xBFIgVGBtXS5wgwN4pyL7MXjRDfFIAGwkYnN2nvH1ie4GqBubRWete0jUF0Y7T3eaG5Bhiht%2BrRE4qSLcnKbDpUlWfg5GtL6E3AzxSM7Mmtt6iPctwDBgFzD0hstEHe9el%2B%2ByRt5bjj2qzX818UcQIKMJBklrM9FdhHkvLi%2FQAGcgRCuMlniqCaJM%2FuA1Gb5%2FtqM1f5sVS6Xpk%2BsbAmkdeBn3ZPmxICIbtRF7wexiyMZW7ljH56IcS4znFNPAny1Dw%3D%7Ctkp%3ABk9SR6TCneX-Zw&var=543780669152)| Around 12-19 USD but more expensive ones exists|

## Adapter Board
The main part of the adapter.

**Adapter Board Microcontrollers**

|Hardware|Relevant Firmware|Where to Buy|Price|Notes|
|---|---|---|---|---|
|Teensy 4.1|[ogx360_t4](https://github.com/Ryzee119/ogx360_t4/)|Ebay, Sparkfun | 27-30 USD| Uses Micro USB, has mSD card slot,  <br>powerful development platform. 
|RP2040|[OGX-Mini-2026](https://github.com/MegaCadeDev/OGX-Mini-2026), [SBCFirm2040-lite](https://github.com/quizerno/SBCFirm2040-lite)|Ebay, Sparkfun, Adafruit| 4-30 USD|Many options (see below)
|USB-HID Arduino|[OGXBOX-PAD](https://github.com/eolvera85/OGXBOX-PAD), [SimpleXboxControllerAdapter](https://github.com/jimnarey/SimpleXboxControllerAdapter/tree/master)|Ebay, Sparkfun, Adafruit| 4-30 USD| Many options (see below), This is primarily the GPIO option because Arduinos require separate boards to host USB devices
|USB Host Cable (Female USB A)||Ebay, Sparkfun or other online electronics stores| 3-8 USD| Needed to take in the Custom Controller inputs on the Teensy or the RP2040. Some of the RP2040 boards (such as the Adafruit Feather) come with a USB Host built in and therefore do not require this cable
|Micro USB/Mini USB/USB-C/ to USB-A Cable||Everywhere|1-15 USD|Needed to connect the platform to the computer, as stated above the Teeny 4.1 uses Micro USB, RP2040s and Arduinos have Micro USB and USB-C options. Some Arduinos use Mini USB

**Which Board and Firmware Should I Choose?** <br />
Your choice of board and firmware should ultimately be dependent on your end goal, using pre-existing USB Controllers and/or using GPIO and adding more features. See more specifics on the boards [here.](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/Other%20Guides%20and%20FIles/Microcontroller%20Data.md)

|Hardware|Pros|Cons|
|---|---|---|
|Teensy 4.1| Very Powerful, lots of GPIO pins <br />|Expensive|
|RP2040|Inexpensive, lots of options including Wi-fi, Blutooth and integrated USB Host | Only 3-4 Analogue GPIO, requires I2C GPIO expanders or analog multiplexers to add more|
|Arduino|Inexpensive, simple to program, lots of options|Needs separate board for USB host|

|Firmware|Pros|Cons|Supported Devices|Prebuilt SBC Configurations|
|---|---|---|---|---|
|[ogx360_t4](https://github.com/Ryzee119/ogx360_t4/)|[USBHost_t36 drivers](https://github.com/PaulStoffregen/USBHost_t36), lots of supported devices|Lacking documentation| Keyboard, Mouse, HID Joysticks, Xbox 360 Controller, USB Hubs |  Keyboard+Mouse, HOTAS Gunfighter
|[SBCFirm2040-lite](https://github.com/quizerno/SBCFirm2040-lite)|Simple, some supported devices| Currently WIP, only tested with PICO| Keyboard, Mouse, USB hubs, DS4 Controller, GPIO, working on support for other devices | Pending
|[OGXBOX-PAD](https://github.com/eolvera85/OGXBOX-PAD)|Simple, great for GPIO|Firmware not built with host in mind|None, uses GPIO instead|N/A
|[OGX-Mini-2026](https://github.com/MegaCadeDev/OGX-Mini-2026)|Many host drivers|No keyboard support yet, no hub support, no native GPIO, adding your own configurations might be time consuming| Many Controllers |Xbox 360 Controller with Chatpad
|[SimpleXboxControllerAdapter](https://github.com/jimnarey/SimpleXboxControllerAdapter/tree/master)|Some host libraries|need to buy separate hostboard, Steel Battalion implementation not fully documented| Gamepads| Xbox 360 Controller with Chatpad



## Wiring and Firmware Building
* [For instructions on ogx360_t4 go to section 4A-I](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4A-I-ogx360_t4.md)
* [For instructions on SBCFirm2040-lite go to section 4A-II](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4A-II-SBCFirm2040-lite.md)
* [For instructions on OGXBOX-PAD go to section 4A-III](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4A-II-OGXBOX-PAD.md)
* [For instructions on OGX-Mini-2026 go to section 4A-IV](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4A-IV-OGX-MINI-2026.md)

## Board Options
More data on the microcontrollers [here.](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/Other%20Guides%20and%20FIles/Microcontroller%20Data.md)

**Teensy**
* Teensy 4.1

**RP2040**
* Pi Pico
* Pi Pico 2
* Pi Pico W
* Pi Pico 2 W
* RP2354, Pico/ESP32
* Adafruit Feather
* Arduino Nano RP2040 Connect

**Arduino**
* Adafruit Circuit Playground 32u4
* Arduino Esplora
* Arduino Industrial 101
* Arduino Leonardo
* Arduino Leonardo ETH
* Arduino Micro
* Arduino Robot Control / Motor
* Arduino Yún
* Arduino Yún Mini
* LilyPad Arduino USB
* Linino One

## Other controller firmwares

**RP2040**
* [HID Remapper](https://github.com/jfedor2/hid-remapper) - Keyboard remapper with some controller support, but does not have prebuilt configurations.
* [GP2040-CE](https://github.com/OpenStickCommunity/GP2040-CE) - Similar to OGX mini, does have keyboard support, GPIO support, but does not have prebuilt configurations and web configurator does not support steel battalion, Steel Battalion is included in the libraries.
* [Joypad-os](https://github.com/joypad-ai/joypad-os) - Steel Battalion not yet implemented.

**Arduino or R2040**
* [GIMX](https://github.com/matlo/GIMX) - Similar to OGX-Mini but no longer supported and the wiki is prone to crashing

**ESP32**
* [Talon](https://github.com/Team-Resurgent/Talon)
