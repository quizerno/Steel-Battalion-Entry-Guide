# 4. Custom Controller Options

(**Playing on Emulator Without an Original Controller**)<br />
If you plan on playing on emulator, you can any skip any part of this section that has to do with with the Controller Adapters, and go to the Emulator section ([section 7](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/7-Playing%20on%20Emulator.md)). If you want to build a custom controller, some of this knowledge will be helpful.

(**Playing on Xbox Without An Original Controller**)<br />
If you want to play on Xbox or are curious about tinkering, read on.


**Skills you need**<br />
- Knowledge of programming: Coding is not strictly necessary unless you want to do more complex control options.
- Mild understanding of linux commands
- Basic soldering: you will need to solder at least 4 points. If you're planning on building a controller from scratch you will be need to solder a lot.
- Patience: this can be difficult

## Planning

There are two primary paths for this, both involve using a microcontroller to emulate inputs of a Steel Battalion Controller

* **[Adapted Set-Up:](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4B-Adapted%20Controllers.md)** You take any existing controllers (gamepad/flightstick/etc) and use a controller adapter to play Steel Battalion.
  * This path is the simplest option for playing on Xbox.

* **[DIY Set-Up:](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4C-DIY%20Controllers.md)** You make your controller from scratch and use a controller adapter to play Steel Battalion.
  * This path is more complicated and has many sub-options, but is great for learning about how to build gamepads and selecting your own inputs.


Combining parts of each of these into a **Hybrid Set-Up** is also an option but it will be heavily dependent on the adapter and firmware you choose. 


## Specifics of Each Set-Up

### Adapted Set-Up

<img width="1152" height="360" alt="image" src="https://github.com/user-attachments/assets/44a67dc0-539d-45d2-8aa5-a849d6a9ef41" />

Your **Existing USB Controller** connects to a **Host Cable** on your **adapter board** which connects to the Xbox. The inputs on the USB Controller are read by the adapter which outputs Steel Battalion inputs to the Xbox. As long as the USB devices are parsed properly, you can play Steel Battalion with the USB devices you want. 

### DIY Set-Up

<img width="991" height="239" alt="sb connection4 copy" src="https://github.com/user-attachments/assets/06677fe0-61e9-4047-a2f7-e18208547c0c" />

Your **DIY inputs** are directly connected to your **adapter board** which connects to the Xbox. The adapter board effectively becomes the Steel Battalion Controller.

After reading about each set-up, proceed to [**Section 4A**](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4A-Controller%20Adapters.md) and consider which adapter you want to use.

## Adapting or Building Pedals
If you need pedals and want to create your own pedals or need help adapting the analog inputs. [Go to Section 5](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/5-Custom%20Pedals.md).



## Examples of Custom/Adapted Controllers

<img width="768" height="576" alt="20231025_231002" src="https://github.com/user-attachments/assets/13e4fa22-7629-4a2d-b51b-697041da6807" />

QuantX's combination controller utilizing two Thrustmaster T16000s, Logitech G920 pedals, and a custom board.

<img width="652" height="870" alt="image" src="https://github.com/user-attachments/assets/08253b2d-0585-467e-956d-fb97184d3a9f" />

FluffStuff's Emulator set-up utilizing the VBK EVO Gladiator and Omni-throttle and Turtle Beach VelocityOne Rudder Pedals

[![to youtube](https://img.youtube.com/vi/g_eQlOcccg8/0.jpg)](https://www.youtube.com/watch?v=g_eQlOcccg8)

Ryzee demonstrating his completed build of ogx360 and utilizing the Xbox 360+Chatpad as a Steel Battalion Controller (click the image to go to the full video)



