# 3A-III. SBCFirm2040-lite
[SBCFirm2040-lite](https://github.com/quizerno/SBCFirm2040-lite) is a RP2040 firmware I cobbled together from Faha's [SteelBattalionControllerFirmware_RP2040](https://github.com/faha223/SteelBattalionControllerFirmware_RP2040) and 
the stock [PICO-PIO-USB Host example](https://github.com/raspberrypi/pico-examples/tree/master/usb/host/host_cdc_msc_hid). It is my attempt at a port of [ogx360_t4](https://github.com/Ryzee119/ogx360_t4) for the RP2040 boards, which are much cheaper than Teensy boards. It is very crudely built with lots of bug testing via AI assistance.


As of now I have only tested it with a regular Pico

### Soldering the Host Cable to the RP2040
Same as the OGX-Mini. This will be dependent on your board. The original repository has some [examples of the wiring.
](https://github.com/MegaCadeDev/OGX-Mini-2026/tree/master/hardware).

### Set-up
For set-up clone [pico-sdk](https://github.com/raspberrypi/pico-sdk) to your computer and export path. You may also need to download python3

```
git clone --recurse-submodules https://github.com/raspberrypi/pico-sdk.git
export PICO_SDK_PATH=$HOME/pico-sdk/
```

### Build Instructions

```bash
git clone --recurse-submodules https://github.com/quizerno/SBCFirm2040-lite.git
cd SBCFirm2040-lite
mkdir build
cd build
cmake ..
make
```
Once that's done, connect your RP2040 to your PC in Download mode (hold button while connecting), and copy the .uf2 file to the drive that shows up
