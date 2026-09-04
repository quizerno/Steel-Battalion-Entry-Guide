# 4C. DIY Controllers
**(The really intricate path)**

Hardware-wise path you take on building a custom controller does not matter provided you can get the controls to function with the adapters mentioned in section 3. The software side that interacts with those adapters is the key focus.


Per [section 4A](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4A-Controller%20Adapters.md), I recommend either a 
* Teensy 4.1 with og360_t4
* Raspberry Pi board running SBCFirm2040-lite.
* An HID Arduino (with at least 14 digital pins and 7-8 Analog pins) running OGXBOX-PAD
  
The reason for this being that if using a pre-build controllers, you will want hub support to attach additional ones.

## Necessary Inputs
Going back to [section 2](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/3-Controller%20Inputs.md), we can see the table that illustrates the inputs we need.

|Total |Analogue Inputs|Digital Inputs|
|---|---|---|
| Full Recreation|8| 62
| Simple Recreation|7|38
| Notes|| 


## DIY-HID Set-Up:



## DIY-SBC HUB Set-Up

## DIY-GPIO Set-Up








## Understanding HID codes

Most USB devices have specific usages.





## Required Hardware

As
|Total |Analogue Inputs|Digital Inputs|
|---|---|---|
| Full Recreation|8| 51 
| Simple Recreation|6|38

You then have a choice between separating the blocks into 2 or more micro controllers and using a HUB to bring them together or consolidating into one micro controller.

So how do we get that many digital inputs into one board? By using a matrix. You can turn 14 microcontroller pins into 49 inputs using a 7x7 keyboard matrix. Therefore, in theory you only need a board that has 14 digital pins and 6 analogue pins for a Simple Recreation of the controller.

Going back to section 3, deciding on your adapter board becomes a bit clearer. Your options are now

  1. Create a Keyboard

# 4. Custom Controller

Whether you decide to play on Xbox or Emulator ultimately decides on how you approach this.

**Emulator Play**
Requires rebinders on PC to remap existing USB devices for Xemu. At the moment me and others are working on a framework that will hopefully reduce the software required.

**Xbox Play**
Requires one of the adapters and firmware from section 3, and then the proper configuring to get the adapter to recognize your devices.


## Simplifying the Approach

Going back to section 2, we can see the table that illustrates the inputs we need.

|Total |Analogue Inputs|Digital Inputs|
|---|---|---|
| Full Recreation|8| 62
| Simple Recreation|7|38
| Notes|| 


### Using Existing Hardware
Let's say, you want to get right to the game, and want a semi-accurate recreation of the original game.

|Block |Hardware|Examples|
|---|---|---|
| Left Block|Left Handed Joystick with Hatstick and 4 buttons| Thrustmaster 16000m series
| Middle Block|Full Length Keyboard| Any keyboard will work, but an RGB keyboard might draw too much power from the adapter board unless you have a HUB
| Right Block|Right Handed Joystick with NO RECENTERING| Microsoft Sidewinder Force Feedback 2 (Requires Modding)
| Pedal Block|Three Pedal Controller|Logitech G29

### Making Your Own

Let's say you want to build the controlle


Getting your chosen hardware and software to communicate with each other 
Hardware-wise path you take on building a custom controller does not matter provided you can get the controls to function with the adapters mentioned in section 3. 
The software side that interacts with those adapters is the key focus.

## Understanding HID codes

Most USB devices have specific usages.





## Required Hardware

Going back t0 section 2, we can see the table that illustrates the inputs we need.

|Total |Analogue Inputs|Digital Inputs|
|---|---|---|
| Full Recreation|8| 62
| Simple Recreation|7|38
| Notes|| 

You then have a choice between separating the blocks into 2 or more micro controllers and using a HUB to bring them together or consolidating into one micro controller.

So how do we get that many digital inputs into one board? By using a matrix. You can turn 14 microcontroller pins into 49 inputs using a 7x7 keyboard matrix. Therefore, in theory you only need a board that has 14 digital pins and 6 analogue pins for a Simple Recreation of the controller.

Going back to section 3, deciding on your adapter board becomes a bit clearer. Your options are now

  1. Create a Keyboard

So how do we get that many digital inputs into one board? By using a matrix. You can turn 14 microcontroller pins into 49 inputs using a 7x7 keyboard matrix. Therefore, in theory you only need a board that has 14 digital pins and 6 analogue pins for a Simple Recreation of the controller.

## Examples

<img width="1412" height="852" alt="image" src="https://github.com/user-attachments/assets/7f1cd1f8-c170-45
e7-8e3c-fdac7be13e43" />



### Links

https://github.com/gsmrana/USB-HID-Analyzer/releases/tag/v1.0.0

https://www.freebsddiary.org/APC/usb_hid_usages.php

## Full Custom Controller
A microcontroller such as a pro micro, arduino, or another teensy can be used to map a keyboard, and the keyboard will serve as a controller using the inputs designated in the ogx360_t4 configuration. This task can be quite daunting if you are unfamiliar with keyboard creation so I will create some examples to show you.


## Examples of Custom Controllers

<img width="768" height="576" alt="20231025_231002" src="https://github.com/user-attachments/assets/13e4fa22-7629-4a2d-b51b-697041da6807" />

QuantX's combination controller utilizing Thrustmaster T16000, Logitech G920 pedals, and a custom board

<img width="652" height="870" alt="image" src="https://github.com/user-attachments/assets/08253b2d-0585-467e-956d-fb97184d3a9f" />

FluffyStuff's combination controller utilizing

https://cdn.discordapp.com/attachments/1249909486928265331/1467308107498655857/IMG_20260131_140148251.jpg?ex=6a8d836a&is=6a8c31ea&hm=72a67fd7d0002f04ea164213c389eec69a3bdf3c5e7e980f1956b6e6d777ee89&






## Examples

<img width="1412" height="852" alt="image" src="https://github.com/user-attachments/assets/7f1cd1f8-c170-45
e7-8e3c-fdac7be13e43" />



### Links

https://github.com/gsmrana/USB-HID-Analyzer/releases/tag/v1.0.0

https://www.freebsddiary.org/APC/usb_hid_usages.php

