# 6. Playing on Emulator


## Xemu
- **[Xemu Website](https://xemu.app/)**
- **[Xemu Github](https://github.com/xemu-project/xemu)**

Xemu is an open source emulator for the original Xbox. It requires Xbox BIOS files and other system files to run. Development of the main Xemu has been slow, it lacks basic features and cohesion. However since it is open source, people have taken it upon themselves to build it to their needs. Xemu originally used OpenGL for graphics, but now also can be built with Vulkan

### Setting up Xemu
Setting up Xemu is fairly simple. Once started you will be prompted for three required files. 

* MCPX Boot ROM Image
* Flash ROM Image (BIOS)
* Hard Disk Image

The first two files are copyrighted and must be obtained independently. The third file is provided by Xemu [here.](https://github.com/xemu-project/xemu-dashboard/releases/latest/download/xbox_hdd.qcow2)
CERBIOS does NOT work with Xemu (it flashes the title and then stops), but other custom dashboards like [UnleashX](https://consolemods.org/wiki/Xbox:UnleashX) do. For an official bios, it is recommended to use one of the Xbox Bios Complex 4627 files.

### PenguinBox Xemu
* [PenguinBox Github Release Page
](https://github.com/PenguinVRLab/PenguinBox/releases)

During the time at which this guide was being written (July 2026), there were some great strides in the emulation department.
For his PenguinVRLab project, Newerest forked a new version of Xemu which has very good performance. It is currently the best way to emulate the game. Despite the name, VR is not required for this.

### Legacy Steel Battalion Dedicated Forks of Xemu

Here are alternative forks of Xemu, most forks of the usb_passthrough fork of Xemu to allow use with the original controller.

|Xemu Description|Fork Name|Compatibility|Notes
|---|---|---|---|
| Xemu with Vulkan Graphics (VK)| [Usb_passthrough_vk](https://github.com/faha223/xemu/tree/usb_passthrough_vk)|Steel Battalion|By SpecialFred: uses SDL3 for controls bindings
| Xemu with OpenGL Graphics|[Usb_passthrough](https://github.com/faha223/xemu/tree/usb_passthrough)|Steel Battalion: Line of Contact|By SpecialFred: uses SDL2 for controls bindings, Input menu will display passthrough controller inputs
| Xemu with Vulkan Graphics (VK) and QOL|[Xemu-SB-VK](https://github.com/quizerno/Xemu-SB-VK)|Steel Battalion|By Quizerno: options to disable hotkeys, rebinding from within the game (requires restart)
| Xemu with Multiple Joystick Mapping|None, can be [downloaded here](https://github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/Other%20Guides%20and%20FIles/FluffyStuff%20Xemu%20Build.7z) |Steel Battalion(?)|By FluffStuff: uses an older version of Xemu but allows joystick inputs. 



## Cxbx-Reloaded (TBD)
https://www.youtube.com/watch?v=hatA9M7ftlE&t=300s
Cxbx reloaded is a stand alone emulator that does not require a dumped BIOS to run. 
Cxbx has many more options in regards to controls and Steel Battalion is technically playable, but it also has sound and performance issues. Further development is needed.
https://cxbx-reloaded.co.uk/
https://www.youtube.com/watch?v=YYqngubf_co
https://www.youtube.com/watch?v=JYqUdGF6bBc
https://www.youtube.com/watch?v=hatA9M7ftlE
http://youtube.com/watch?v=clwK9Pdt7o8


### Building Xemu Yourself (TBD)
If you are knowledgeable on C++ or have coding experience, you can clone either the main branch of xemu or the USB Pass-Through branck, edit the files and build Xemu yourself
Building Xemu https://xemu.app/docs/dev/building-from-source/#__tabbed_1_2

https://forums.launchbox-app.com/topic/59105-tutorial-xemu-configuration/

apt-get update && apt-get install curl

#### Clone and build
git clone https://github.com/xemu-project/xemu
docker run --rm -v $PWD/xemu:/xemu -w /xemu \
    -e CCACHE_DIR=/xemu/ccache \
    ghcr.io/xemu-project/xemu-win64-toolchain:latest \
    ./build.sh -p win64-cross
#### Run
./xemu/dist/xemu.exe

docker run --rm -v $PWD/usbpass:/usbpass -w /usbpass \
    -e CCACHE_DIR=/usbpass/ccache \
    ghcr.io/xemu-project/xemu-win64-toolchain:latest \
    ./build.sh -p win64-cross







#### Building PenguinBox (TBD)

Dependencies that might have to be installed
```

pip install -U sphinx --break-system-packages

pip install sphinx-rtd-theme --break-system-package

sudo apt-get install libglib2.0-dev

sudo apt-get install build-essential git make \
pkg-config cmake ninja-build gnome-desktop-testing libasound2-dev libpulse-dev \
libaudio-dev libfribidi-dev libjack-dev libsndio-dev libx11-dev libxext-dev \
libxrandr-dev libxcursor-dev libxfixes-dev libxi-dev libxss-dev libxtst-dev \
libxkbcommon-dev libdrm-dev libgbm-dev libgl1-mesa-dev libgles2-mesa-dev \
libegl1-mesa-dev libdbus-1-dev libibus-1.0-dev libudev-dev libthai-dev libusb-1.0-0-dev

sudo apt-get install libvulkan-dev
 sudo apt-get install build-essential git make libpipewire-0.3-dev libwayland-dev libdecor-0-dev liburing-dev

sudo apt-get install libepoxy-dev
 sudo add-apt-repository ppa:kisak/kisak-mesa && sudo dpkg --add-architecture i386 && sudo apt update && sudo apt upgrade && sudo apt install libgl1-mesa-dri:i386 mesa-vulkan-drivers mesa-vulkan-drivers:i386


sudo apt-get install python3-sphinx

sudo apt-get install python3-sphinx-rtd-theme





#if needing to remove some dependencies

pip uninstall sphinx --break-system-packages
pip uninstall sphinx-rtd-theme --break-system-packages







```
