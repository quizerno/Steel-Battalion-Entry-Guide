# 3. Custom Controller Options

(**Playing on Emulator Without an Original Controller**)<br /)
If you plan on playing on emulator, you can any skip any part of this section that has to do with with the Controller Adapters, and go to the Emulator section. However, if you want to build a custom controller, some of this knowledge will be helpful.

(**Playing on Xbox Without An Original Controller**)
If you want to play on Xbox or are curious about tinkering, read on.


**Skills you need**
- Knowledge of programming: Coding is not strictly necessary unless you want to do more complex control options.
- Mild understanding of linux commands
- Basic soldering: you will need to solder at least 4 points. If you're planning on building a controller from scratch you will be need to solder a lot.
- Patience: this can be difficult




## Planning

**First:** to interact with the Xbox USB protocol, we need a Controller Adapter and Firmware. 

**Second:** you will need to decide on the control set-up you want. One of these uses existing controllers, 
the other 3 involve DIY controllers.

* **Adapted Set-Up:** If you want to use existing controllers that connect to an adapter.
* **DIY-HID Set-Up:** If you want to create your own controller that connects to an adapter.
* **DIY-SBC HUB Set-Up:** If you want to create multiple emulated Steel Battalion devices that meet together in one adapter.
* **DIY-GPIO Set-Up:** If you want to have the controls directly wired to the adapter.

Combining these set-ups is also an option but it will be heavily dependent on the adapter and firmware you choose. 


## Adapted Set-Up

If you would like to make the custom controller quickly, utilizing  using existing controllers and configuring your chosen adapter.

**How this works**

<img width="1152" height="360" alt="image" src="https://github.com/user-attachments/assets/44a67dc0-539d-45d2-8aa5-a849d6a9ef41" />

Your **Existing USB Controller** connects to a **Host Cable** on your **adapter board** which connects to the Xbox. The inputs on the USB Controller are read by the adapter which outputs Steel Battalion inputs to the Xbox. As long as the USB devices are parsed properly, you can play Steel Battalion with the USB devices you want. 


**To lay it out simply:**
- One adapter board 
- One or more USB-Devices connected to Host Cable of the adapter (HUB needed for 2+ devices)
- The adapter is programmed to parse each of the devices to and map them to corresponding Steel Battalion inputs
- The inputs are then sent to the Xbox

Proceed to [section 4A](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4A-Adapting%20Controllers.md).

## DIY-HID Set-Up

Let's say you want to build your own controller, but you also want to use it on PC.

IMAGE

Your **Custom USB Controller** connects to a **Host Cable** on your **adapter board** which connects to the Xbox. The inputs on the USB Controller are read by the adapter which outputs Steel Battalion inputs to the Xbox.


**To lay it out simply:**
- This is essentially the same as an adapted controller but with your own custome controller 
- One or more Custom HID Joysticks connected to Host Cable of the adapter (HUB needed for 2+ devices)
- An advantage of this is that since you are responsible for the HID Protocol, it is far easier to parse it on the adapter side
- A disadvantage of this is that you need to buy more microcontroller boards


## DIY-SBC HUB Set-Up

Let's say you want to build your own controller, but you don't want to bother with USB protocols and parsing.

IMAGE

Your **Custom SBC Controller** connects to a **Host Cable** on your **adapter board** which connects to the Xbox. The inputs on the USB Controller are read by the adapter which outputs Steel Battalion inputs to the Xbox.


**To lay it out simply:**
- This is essentially the same as an adapted controller but with your own custome controller 
- One or more Custom HID Joysticks connected to Host Cable of the adapter (HUB needed for 2+ devices)
- An advantage of this is that since you are responsible for the HID Protocol, it is far easier to parse it on the adapter side
- A disadvantage of this is that you need to buy more microcontroller boards


### Building a Controller 
If you are interested in building your own controller, using microcontrollers and wiring your own inputs. [Go to section 4B](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4A-Adapting%20Controllers.md).

### Adapting or Building Pedals
If you need pedals and want to create your own pedals or need help adapting the analog inputs. [Go to Section 4C](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4C-Adapting%20or%20Building%20Pedals.md).



## Examples of Custom/Adapted Controllers

<img width="768" height="576" alt="20231025_231002" src="https://github.com/user-attachments/assets/13e4fa22-7629-4a2d-b51b-697041da6807" />

QuantX's combination controller utilizing two Thrustmaster T16000s, Logitech G920 pedals, and a custom board.

<img width="652" height="870" alt="image" src="https://github.com/user-attachments/assets/08253b2d-0585-467e-956d-fb97184d3a9f" />

FluffStuff's Emulator set-up utilizing the VBK EVO Gladiator and Omni-throttle and Turtle Beach VelocityOne Rudder Pedals

[![to youtube](https://img.youtube.com/vi/g_eQlOcccg8/0.jpg)](https://www.youtube.com/watch?v=g_eQlOcccg8)

Ryzee demonstrating his completed build of ogx360 and utilizing the Xbox 360+Chatpad as a Steel Battalion Controller (click the image to go to the full video)



