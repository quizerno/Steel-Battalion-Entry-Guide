# 4A. Adapting Controllers 
**(Using Pre-Existing Hardware with a Controller Adapter)**

Let's say, you want to get right to the game. You're confident in your programming skills.
## Choosing Controllers

At risk of sounding like a self-help manual. Choose what's right for you.

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
You can get away with a keyboard and mouse, however there are downsides with only digital controls, the details of which are described in [section 2](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/2-The%20Controller%20Inputs.md) under "Notes on Analog Reads vs Digital Reads"

## Configuring the Adapter for your Selected Controllers

This is hard part of the process. Depending on the firmware you are using, you will need to figure out how to parse each of your hardware.


|Firmware|Host Drivers|Cons|Prebuilt Configurations|
|---|---|---|---|
|[ogx360_t4](https://github.com/Ryzee119/ogx360_t4/)|**Board:** Very Powerful, lots of GPIO pins **Software:** Very easy to configure, keyboard and joystick support| **Board:** Expensive, very sensitive to higher voltages| Keyboard+Mouse, HOTAS Flightstick
|[OGX-Mini-2026](https://github.com/MegaCadeDev/OGX-Mini-2026)|**Board:** Inexpensive, many options, **Software:** For non-Steel Battalion uses, it can be used on most modern consoles| **Software:** No keyboard support yet, adding your own configurations might be time consuming| Xbox 360 Controller with Chatpad
|[SBCFirm2040-lite](https://github.com/quizerno/SBCFirm2040-lite)|**Board:** Inexpensive , **Software:** Simple  |**Board:** Currently only testing with the regular PICO **Software:** Currently WIP| Keyboard, Mouse, DS4 Controller, working on support for other devices
