# 4B. Adapting Controllers 
**(Using Pre-Existing Hardware with a Controller Adapter on Xbox, aka the Host Option)**

This path requires understanding how to parse USB devices, or adapting certain functions to do so.

## Recommended Hardware

Per [section 4A](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4A-Controller%20Adapters.md), I recommend either a Teensy 4.1 with og360_t4 or Raspberry Pi board running SBCFirm2040-lite.
The reason for this being that if using a pre-build controllers, you will want hub support to attach additional ones.

## Necessary Inputs
Going back to [section 2](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/3-Controller%20Inputs.md), we can see the table that illustrates the inputs we need.

|Total |Analogue Inputs|Digital Inputs|
|---|---|---|
| Full Recreation|8| 62
| Simple Recreation|7|38
| Notes|| 

|Total |Analogue Inputs|Digital Inputs|
|---|---|---|
| Full Recreation|8| 62
| Simple Recreation|7|38
| Notes|| 


With this in mind you can plan out the exact hardware you need.

## Full Recreation Controller vs Simple Recreation Controller

A full recreation is difficult to achieve via an adapting method because two elements of the controller are not common parts:
  * The 7 position Gear Shifter
  * The 15 position Tuner Dial

The Gear Shifter as a separate module is sometimes available, but the Tuner Dial would likely require custom parts. 
Simplifying these reduces the number of inputs by 18. For this guide we shall proceed with a Full Recreation MINUS these 18



## Simple Recreation Controller

**Left Block:** consists of 

**Middle Block:**

**Right Block:** 

## Choosing Controllers

At risk of sounding like a self-help manual. Choose what you feel is comfortable, 

**Recommended Configuration**<br />
If you want a semi-accurate recreation of the original game.
|Block |Hardware|Examples|
|---|---|---|
| Left Block|Left Handed Joystick with Hatstick and 4 buttons| Thrustmaster 16000m series
| Middle Block|Full Length Keyboard| Any keyboard will work, but an RGB keyboard might draw too much power from the adapter board unless you have a HUB
| Right Block|Right Handed Joystick with NO RECENTERING| Microsoft Sidewinder Force Feedback 2 (With Spring Removed)
| Pedal Block|Three Pedal Controller|Logitech G29

**Budget Configuration**<br />
If you've already spent money and time on the adapter
|Block |Hardware|Examples|
|---|---|---|
| Left Block|Left Handed Joystick with Hatstick and 4 buttons| Thrustmaster 16000m series
| Middle Block|Full Length Keyboard| Any keyboard will work, but an RGB keyboard might draw too much power from the adapter board unless you have a HUB
| Right Block|Mouse| Three Button Mouse
| Pedal Block|Digital Foot Pad|Generic USB Triple Foot Switch Pedal

**Bare Bones**<br />
You can get away with a keyboard and mouse, however there are downsides with only digital controls, the details of which are described in [section 2](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/3-The%20Controller%20Inputs.md) under "Notes on Analog Reads vs Digital Reads"

## Configuring the Adapter for your Selected Controllers

This is hard part of the process. Depending on the firmware you are using, you will need to figure out how to parse each of your hardware.


|Firmware|Host Drivers|Cons|Prebuilt Configurations|
|---|---|---|---|
|[ogx360_t4](https://github.com/Ryzee119/ogx360_t4/)|**Board:** Very Powerful, lots of GPIO pins **Software:** Very easy to configure, keyboard and joystick support| **Board:** Expensive, very sensitive to higher voltages| Keyboard+Mouse, HOTAS Flightstick
|[SBCFirm2040-lite](https://github.com/quizerno/SBCFirm2040-lite)|**Board:** Inexpensive , **Software:** Simple  |**Board:** Currently only testing with the regular PICO **Software:** Currently WIP| Keyboard, Mouse, DS4 Controller, working on support for other devices
