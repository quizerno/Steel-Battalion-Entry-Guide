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

## Interface Cable
To furst connect the adapter board to the Xbox, you will need a cable that allows you to connect USB devices to the Xbox.  If you have done softmodding or hard modding before, you will likely have some experience with this.

**Xbox USB Bridge Cable**
|Hardware|Usage|Where to Buy|Price|
|---|---|---|---|
|USB-Female to Xbox Cable|Allows interfacing with the Original Xbox, also used for softmodding| [Ebay](https://www.ebay.com/itm/127869049454) among other places, you can also build one if you have a spare Xbox breakaway cable and a female USB port| Around 11 USD|

**Notes:**
- In the next section you will choose hardware for the adapter board
  - If the hardware uses USB-C you can use an Xbox to USB-C Cable.
  - If the hardware uses Micro USB you can use an Xbox to Micro USB Cable.
## USB Hub
A powered USB hub will be needed if you want to connect more than one device to the adapter board
|Hardware|Usage|Where to Buy|Price|
|---|---|---|---|
|USB Hub|Allows interfacing with the Original Xbox, also used for softmodding| [Ebay](https://www.ebay.com/itm/127869049454) among other places, you can also build one if you have a spare Xbox breakaway cable and a female USB port| Around 11 USD|

## Adapter Board
Before building the controller proper we need hardware that emulates the original controller's signals.
For the sake of ease, we will call this an Adapter Board.

**Adapter Boards Hardware**

|Hardware|Relevant Software|Where to Buy|Price|Notes|
|---|---|---|---|---|
|Teensy 4.1|[ogx360_t4](https://github.com/Ryzee119/ogx360_t4/)|Ebay, Sparkfun | 27-30 USD| Uses Micro USB, extremely powerful development platform, has mSD card slot. 
|RP2040|[OGX-Mini-2026](https://github.com/MegaCadeDev/OGX-Mini-2026)|Ebay, Sparkfun, Adafruit| 4-30 USD|Many Options including Pi Pico, Pi Pico 2, Pi Pico W, Pi Pico 2 W, RP2354, Pico/ESP32
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
This is slightly trickier because the pins are not in a row. See the [OGX-Mini-2026 for wiring diagrams](https://github.com/MegaCadeDev/OGX-Mini-2026/tree/master/hardware).

https://www.pjrc.com/store/cable_usb_host_t36.html

## Firmware for the board
For instructions on ogx360_t4 go here
For instructions on OGX-Mini-2026 go here


## Controller Pieces
