# 4. Custom Controller

Hardware-wise path you take on building a custom controller does not matter provided you can get the controls to function with the adapters mentioned in section 3. 
The software side that interacts with those adapters is the key focus.

## Understanding HID codes

Most USB devices have specific usages.





## Required Hardware

Going back t0 section 2, we can see the table that illustrates the inputs we need.

|Total |Analogue Inputs|Digital Inputs|
|---|---|---|
| Full Recreation|8| 51 
| Simple Recreation|6|38

You then have a choice between separating the blocks into 2 or more micro controllers and using a HUB to bring them together or consolidating into one micro controller.

So how do we get that many digital inputs into one board? By using a matrix. You can turn 14 microcontroller pins into 49 inputs using a 7x7 keyboard matrix. Therefore, in theory you only need a board that has 14 digital pins and 6 analogue pins for a Simple Recreation of the controller.

Going back to section 3, deciding on your adapter board becomes a bit clearer. Your options are now

  1. Create a Keyboard



## Examples

<img width="1412" height="852" alt="image" src="https://github.com/user-attachments/assets/7f1cd1f8-c170-45
e7-8e3c-fdac7be13e43" />



### Links

https://github.com/gsmrana/USB-HID-Analyzer/releases/tag/v1.0.0

https://www.freebsddiary.org/APC/usb_hid_usages.php

## Full Custom Controller
A microcontroller such as a pro micro, arduino, or another teensy can be used to map a keyboard, and the keyboard will serve as a controller using the inputs designated in the ogx360_t4 configuration. This task can be quite daunting if you are unfamiliar with keyboard creation so I will create some examples to show you.
