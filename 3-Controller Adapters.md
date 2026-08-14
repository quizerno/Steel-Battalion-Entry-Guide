# 3. Controller Adapters
(**Playing on Xbox Without An Original Controller**)

If you plan on playing on emulator, you can skip this section.
But if you want to play on Xbox or are curious about tinkering, read on.


**Skills you need**
- Knowledge of programming: Coding is not strictly necessary unless you want to do more complex control options.
- Mild understanding of linux commands
- Basic soldering: you will need to solder 4 points. If you're planning on building a controller from scratch you will be need to solder a lot.
- Patience: this can be difficult


## How this works

<img width="1152" height="360" alt="image" src="https://github.com/user-attachments/assets/44a67dc0-539d-45d2-8aa5-a849d6a9ef41" />

The inputs are read from your **custom controller** into your **adapter board** which outputs Steel Battalion inputs to the Xbox Controller 
Through this rube-goldberg finaggling of connections, you can play Steel Battalion with a control set-up of your choosing. 
Note that Xbox modding is not required for the controller to work, but you will need the Female USB Cable Adapter to connect to it.

# Hardware

## Connection Cables 


**Xbox USB Bridge Cable**
To , you will need a cable that allows you to connect USB devices to the Xbox.  If you have done softmodding or hard modding before, you will likely have some experience with this.

|Hardware|Usage|Where to Buy|Price|
|---|---|---|---|
|USB-Female to Xbox Cable|Allows interfacing with the Original Xbox, also used for softmodding| [Ebay](https://www.ebay.com/itm/127869049454), [Amazon](https://www.amazon.com/dp/B076HHZ41Z?lv=shuf&channelId=500&plpRedirect=mhFallback) among other places, you can also build one if you have a spare Xbox breakaway cable and a female USB port| Around 5-11 USD|

**Notes:**
- In an upcoming section section you will choose hardware for the adapter board
  - If the adapter board uses USB-C you can use an Xbox to USB-C Cable.
  - If the adapter board uses Micro USB you can use an Xbox to Micro USB Cable.

**USB Hub**

A powered USB hub will be needed if you want to connect more than one device to the adapter board. 
|Hardware|Usage|Where to Buy|Price|
|---|---|---|---|
|USB Hub|Connects multiple devices to one device, power adapter ensures that it will not draw too much voltage from the adapter board | [Ebay](https://www.ebay.com/itm/334645888588?_skw=powered+usb+hub&itmmeta=01KZV57C33Q88G3AG75GB9JZ8K&hash=item4dea73064c%3Ag%3AnHkAAOSw4TxjhH7O&itmprp=enc%3AAQALAAAA0GfYFPkwiKCW4ZNSs2u11xBFIgVGBtXS5wgwN4pyL7MXjRDfFIAGwkYnN2nvH1ie4GqBubRWete0jUF0Y7T3eaG5Bhiht%2BrRE4qSLcnKbDpUlWfg5GtL6E3AzxSM7Mmtt6iPctwDBgFzD0hstEHe9el%2B%2ByRt5bjj2qzX818UcQIKMJBklrM9FdhHkvLi%2FQAGcgRCuMlniqCaJM%2FuA1Gb5%2FtqM1f5sVS6Xpk%2BsbAmkdeBn3ZPmxICIbtRF7wexiyMZW7ljH56IcS4znFNPAny1Dw%3D%7Ctkp%3ABk9SR6TCneX-Zw&var=543780669152)| Around 12-19 USD but more expensive ones exists|

## Adapter Board
Before building the controller proper we need hardware that emulates the original controller's signals.
For the sake of ease, we will call this an Adapter Board.

**Adapter Boards Hardware**

|Hardware|Relevant Software|Where to Buy|Price|Notes|
|---|---|---|---|---|
|Teensy 4.1|[ogx360_t4](https://github.com/Ryzee119/ogx360_t4/)|Ebay, Sparkfun | 27-30 USD| Uses Micro USB, has mSD card slot,  <br>powerful development platform. 
|RP2040|[OGX-Mini-2026](https://github.com/MegaCadeDev/OGX-Mini-2026), [SBCFirm2040-lite](https://github.com/quizerno/SBCFirm2040-lite)|Ebay, Sparkfun, Adafruit| 4-30 USD|Many Options including Pi Pico,  <br>Pi Pico 2, Pi Pico W, Pi Pico 2 W, RP2354, Pico/ESP32
|USB Host Cable (Female USB A)||Ebay, Sparkfun or other online electronics stores| 3-8 USD| Needed to take in the Custom Controller inputs. Some of the RP2040 boards (such as the Adafruit Feather) come with a USB Host built in and therefore do not require this cable
|Micro USB/USB-C to USB-A Cable||Everywhere|1-15 USD|Needed to connect the platform to the computer, as stated above the Teeny 4.1 uses Micro USB, RP2040s have Micro USB and USB-C options

**Which Board Should I Choose?**
The Teensy 4.1, while expensive, is pretty easy to configure. 
The RP2040 boards are cheaper, but use more complex libraries and so might be overwhelming for newcomers. 


Here is where the soldering comes in.

### Soldering the Host Cable

### Teensy 4.1  
<img width="805" height="737" alt="usb copy" src="https://github.com/user-attachments/assets/89d8b624-9c0c-4c28-8122-38923cfed306" />

The wiring on the teensy is pretty straight forward. Solder 5 pins to the USB header on the board and attach the cable, **MAKE ABSOLUTELY SURE YOUR ORIENATION IS CORRECT** 

### RP2400  
This is slightly trickier because the pins are not in a row. See the [OGX-Mini-2026 documentation for wiring diagrams](https://github.com/MegaCadeDev/OGX-Mini-2026/tree/master/hardware).

https://www.pjrc.com/store/cable_usb_host_t36.html

## Firmware Building
* [For instructions on ogx360_t4 go here](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/3A-ogx360_t4.md)
* [For instructions on OGX-Mini-2026 go here](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/3B-OGX-MINI-2026.md)
* [For instructions on SBCFirm2040-lite go here](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/3C-SBCFirm2040-lite.md)

## Controller Pieces
