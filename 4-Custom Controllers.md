# 4. Custom Controller

Whether you decide to play on Xbox or Emulator ultimately decides on how you approach this.

**Emulator Play**
Requires rebinders on PC to remap existing USB devices for Xemu.

**Xbox Play**

Requires one of the adapters and firmware from section 3, and then configuring




## Simplifying the Approach

Going back to section 2, we can see the table that illustrates the inputs we need.

|Total |Analogue Inputs|Digital Inputs|
|---|---|---|
| Full Recreation|8| 62
| Simple Recreation|7|38
| Notes|| 

### Using Existing Hardware
Let's say, you want to get right to the game
|Block |Hardware|Examples|
|---|---|---|
| Left Block|Left Handed Joystick with Hatstick and 4 buttons| Thrustmaster 16000m series
| Middle Block|Full Length Keyboard|
| Right Block|Right Handed Joystick with NO RECENTERING| Microsoft Sidewinder Force Feedback 2
| Pedal Block|Logitech G29| Needs Adapter

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
