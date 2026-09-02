
# 4A-I. ogx360_t4
[Ogx360_t4](https://github.com/Ryzee119/ogx360_t4) by Ryzee19 is an open source software package for the Teensy 4.1 boards that allows you to use modern controllers with the original Xbox. 
It is a port of Ryzee’s own project [ogx360](https://github.com/Ryzee119/ogx360), but far easier to put together.

This guide will be slightly out of order. First I will show you how to properly build for the teensy, then I will show you how to configure controls. After which you can build again.

### Soldering the Host Cable to the Teensy 4.1  
<img width="805" height="737" alt="usb copy" src="https://github.com/user-attachments/assets/89d8b624-9c0c-4c28-8122-38923cfed306" />

The wiring on the teensy is pretty straight forward. Solder 5 pins to the USB header on the board and attach the cable.

**MAKE ABSOLUTELY SURE YOUR ORIENATION IS CORRECT OTHERWISE YOU RISK DAMAGING THE DEVICE IS CONNECTED TO THE HOST** 


## Building
## Linux or WSL
Using command line interface. 

**Initial Set-up**

Run the following commands to set-up
```
#Clone the repository
git clone --recurse-submodules https://github.com/Ryzee119/ogx360_t4.git
#Confirm that python is installed 
sudo apt install python3
#Confirm that pip is installed
sudo apt install python3-pip
#Configure the python environment, the version of python might change in the future so keep that in mind.
sudo apt-get install python3.14-venv
#Confirm that platformio is installed
pip install platformio
# If you get a warning, you may have to do the command again with parameters like so
pip install platformio --break-system-packages
curl -fsSL -o get-platformio.py https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py
python3 get-platformio.py
#Add platformio as a shell command
mkdir -p /usr/local/bin
sudo ln -s ~/.platformio/penv/bin/platformio /usr/local/bin/platformio
sudo ln -s ~/.platformio/penv/bin/pio /usr/local/bin/pio
sudo ln -s ~/.platformio/penv/bin/piodebuggdb /usr/local/bin/piodebuggdb
```
Move to ogx360_t4’s directory
```
cd ogx360_t4
```

**Configuring plaftformio.ini**

From here you will decide which configuration for the ogx360_t4. Outside of the command line interface, go to the ogx360_t4 directory and open the platformio.ini (in a text or code editor).
At the very end of the file you will see two preset build environments DUKE and TEST.
```
[env:DUKE]
build_flags = 
    ${env.build_flags}
    -DXID_DUKE=1
    -DXID_STEELBATTALION=0
    -DXID_XREMOTE=0
    -DMSC_XMU=0
    -DXMU_SIZE_MB=8

[env:TEST]
build_flags = 
    ${env.build_flags}
    -DXID_DUKE=1
    -DXID_STEELBATTALION=1
    -DXID_XREMOTE=1
    -DMSC_XMU=1
    -DXMU_SIZE_MB=8
```    

DUKE enables only emulation of the regular Xbox Gamepad, while TEST enables all device emulation.
Create a third build environment that only installs the Steel Battalion configuration, go ahead and copy and paste the following at the end of the file and save
```
;paste this code, this is the Steel Battalion environment
[env:SB]
build_flags = 
    ${env.build_flags}
    -DXID_DUKE=0
    -DXID_STEELBATTALION=1
    -DXID_XREMOTE=0
    -DMSC_XMU=0
    -DXMU_SIZE_MB=8
```
It should look like this:


<img width="624" height="364" alt="image" src="https://github.com/user-attachments/assets/157c5f6a-7499-4610-a49e-ed7faa55b819" />


**Building**
Back in the command line, run the following command to build using this environment. Remember you need to be in the ogx360_t4 directory.
```platformio run -e SB```

After this you will get a hex file. Located at ogx360_t4\.pio\build\SB\ We must then flash this hex file to the teensy.  
If you need help flashing the teensy, go down to the section on flashing.

## Compile Using Windows

For windows you can either install Windows Subsystem for Linux and follow the Linux instructions above. Or you can use visual studio code.
**Visual Studio Code Initial Set-up**

- Download and install [Visual Studio Code](https://code.visualstudio.com/).
- Install the [PlatformIO IDE](https://platformio.org/platformio-ide) plugin.
- Clone this repo recursively ```git clone https://github.com/Ryzee119/ogx360_t4.git --recursive```

**Configure platformio.ini**

Locate the platformio.ini file, follow the same instructions as posted in the Linux section above.
**Building**

- In Visual Studio Code ```File > Open Folder... > ogx360_t4```
- Hit build on the Platform IO toolbar (✓).

You will get a hex file. We must then flash this hex file to the teensy.
If you need help flashing the teensy, go down to the section on flashing.

## Compile Using Mac OSX
WIP

## Flashing the Teensy
Open the Teensy Loader program, select the hex file, press the button on the teensy to begin the flash.

## Configuring the Controls
The controls are configured in [steelbattalion.cpp](https://github.com/Ryzee119/ogx360_t4/blob/master/src/steelbattalion.cpp
). ogx360_t4 is so far the most versatile of the adapter firmwares because it comes with implementation of the USBHost_t36 libraries, which allow it to read HID devices.

### Using a Keyboard and Mouse (Default)
The ogx360_t4 has a prebuilt Keyboard and Keyboard configuration for Steel Battalion. You must plug the mouse and keyboard to a powered USB HUB and then plug the hub into the teensy.
Rebinding the keyboard controls is fairly simple, you can open the steelbattalion.cpp file described above and see how the controls are bound, and edit them to your choosing

## Using a HOTAS Joystick + STECS
I have attached a [configuration for HOTAS provided by Gnomp](https://github.com/quizerno/Steel-Battalion-Entry-Guide/tree/main/Configurations/ogx360_t4%20configurations). These are specifically built for the Gunfighter MCG and STECs
To implement it before building the .hex file, you simply need to do 2 things. 

1. Substitute 2 files located in ```ogx360_t4/src/``` (main.cpp and steelbattalion.cpp, remove HOTAS from the name)
2. Substitute 1 file located in ```ogx360_t4/src/usbh/USBHost_t36``` (Joystick.cpp, again remove HOTAS from the name)

For Step 2, instead of replacing the whole file, you can merely add the following lines to the section ```JoystickController::product_vendor_mapping_t JoystickController::pid_vid_mapping[] = {```

```
	{ 0x231D, 0x0125, SpaceNav, true}, // Gunfighter
	{ 0x231D, 0x0136, SpaceNav, true}, // STECS
```
### Adding Your Own Joystick
If your joystick is not parsed immediately, you may need to configure further.
In the Joystick.cpp file described above, the section where the lines are added are where devices are recognized and how they are processed. To use the Gunfighter as an example:
```
{ 0x231D, 0x0125, SpaceNav, true}, // Gunfighter
{VendorID address, ProductID address, JoystickType, boolean HID Device}
```
1. Vendor ID is: ```0x231D```
2. Product ID is: ```0x0125```
3. Type of Joy stick is: ```SpaceNav```
4. Is it an HID Device: ```true```

The first two arguments require the VID and PID, these can be easily read from plugging in the device and looking at the settings
The third argument does not matter as it is not used.
The fourth argument depends on the device as some devices can use the HID Parsers and others can't



