# 3. Custom Controller Options

This is the bulk of the guide because it is extremely in-depth.

**Emulator Play:**
Requires rebinders on PC to remap existing USB devices for Xemu. At the moment me and others are working on a framework that will hopefully reduce the software required. If you are interested in playing on Emulator proceed to the Emulator section

**Xbox Play:**
Requires one of the adapters and firmware from [section 3](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/3-Controller%20Adapters.md), and then the proper configuring to get the adapter to recognize your devices.
Two factors

## Planning

**First:** to interact with the Xbox USB protocol, we need a Controller Adapter and Firmware. 
You will need to decide on 

**Second:** you will need to decide on the control set-up you want. 

Specifically:
* **Adapted Host Set-Up:** If you want to use existing hardware that goes into an adapter, say use a Flightstick controller to play Steel Battalion.
* **Adapted-HID Set-Up:** If you want to create your own hardware, a full custom controller to play Steel Battalion.
* **SBC Hub Set-Up:** If you want to create multiple emulated Steel Battalion devices that meet together in one adapter.
* **GPIO Set-Up:** If you want to have the controls directly wired to the adapter.

Combining these set-ups is also an option but it will be heavily dependent on the adapter and firmware you choose. 


## Adapted Set-Up
**How this works**
For an adapted controller set-up there is one path:
-One or more USB-Devices connected to Host Cable of the adapter (HUB needed for 2+ devices)
--The adapter is programmed to parse each of the devices to corresponding Steel Battalion inputs
--The inputs are then sent to the Xbox









### Adapting Controllers
If you would like to make the controller quickly, utilizing  using existing controllers and configuring your chosen adapter (or simply connecting it to a PC). [Go to section 4A](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/4A-Adapting%20Controllers.md).

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



