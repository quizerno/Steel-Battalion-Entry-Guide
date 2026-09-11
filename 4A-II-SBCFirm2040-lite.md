# 4A-II. SBCFirm2040-lite
[SBCFirm2040-lite](https://github.com/quizerno/SBCFirm2040-lite) is a RP2040 firmware I cobbled together from Faha's [SteelBattalionControllerFirmware_RP2040](https://github.com/faha223/SteelBattalionControllerFirmware_RP2040) and 
the stock [PICO-PIO-USB Host example](https://github.com/raspberrypi/pico-examples/tree/master/usb/host/host_cdc_msc_hid). It is my attempt at a port of [ogx360_t4](https://github.com/Ryzee119/ogx360_t4) for the RP2040 boards, which are much cheaper than Teensy boards. It is very crudely built with lots of bug testing via AI assistance.

As of now I have only tested it with a regular Pico
## Wiring
### Soldering the Host Cable to the RP2040
This will be dependent on your board. The OGX-Mini-2026 repository has some [examples of the wiring.](https://github.com/MegaCadeDev/OGX-Mini-2026/tree/master/hardware).

## Firmware Building
### Building in Linux or WSL

**Initial Set-up**<br/>
In command line interface,   clone [pico-sdk](https://github.com/raspberrypi/pico-sdk) to your computer and export path. You may also need to download python3

```
git clone --recurse-submodules https://github.com/raspberrypi/pico-sdk.git
export PICO_SDK_PATH=$HOME/pico-sdk/
git clone --recurse-submodules https://github.com/quizerno/SBCFirm2040-lite.git
cd SBCFirm2040-lite
mkdir build
cd build
```
### Building
```
cmake ..
make
```
Once that's done, connect your RP2040 to your PC in Download mode (hold button while connecting), and copy the .uf2 file to the drive that shows up


## Host Input Configuring
### Keyboard and Mouse (Default)
### HOTAS Joystick + STECS
### Adding Your Own Joystick



## GPIO Input Configuring
### Digital Inputs
At the top of the main file, define your pins
```
#define fireButtonPin 15 //remember this is GPIO 15 not literally pin 15
```
At the beginning of ```int main(void)``` configure your pin

```
//input GPIO
    gpio_init(fireButtonPin); //initializes
    gpio_set_dir(fireButtonPin, GPIO_IN); //sets pin as GPIO input
    gpio_pull_up(fireButtonPin); //pin is set to be normal ACTIVE
	
```

within the ```apply_inputs_to_steelbattalion``` function:
```
	if(gpio_get(fireButtonPin)==0){
	gp->steel_battalion_in_report.dButtons.MainWeapon = true;
	}
```

## Analogue Inputs
