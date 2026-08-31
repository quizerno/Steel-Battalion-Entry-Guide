# 5. Improving Performance and Graphics on Xbox

Xbox Modding is required to implement these upgrades.

### Xbox Modding
As said in the intro, I am not going to be detailing Xbox Mods as there are many tutorials, and much of it will depend on your Xbox revision.
Here are several tutorials. All will give a custom dashboard capable of running Steel Battalion. If your Xbox has been modded, go down to the next section on "Connecting via FTP."

* Softmodding: [Coulter Peterson's Tutorial](https://www.youtube.com/watch?v=NchZ-mHqTb0) utilizing [Rocky5's Softmodding Tool](https://github.com/Rocky5/Xbox-Softmodding-Tool)
   * Easiest Option: Only requires a USB-to-Xbox Controller Adapter and compatible flash drive
   * Works on all Xbox revisions
* Hardmodding: [Modzcville USA's ModXO tutorial](https://www.youtube.com/watch?v=uUsov3i6jL0) using [ModXO](https://github.com/Team-Resurgent/Modxo)
   * Requires some more in-depth soldering, and a RP2040 board, with some additional parts
   * For Xbox (any revision) with a working LPC Port. But 1.6 Xboxes will need an LPC rebuild.
* TSOP Flash Modding: [MrMario's TSOP Flash Tutorial](https://www.youtube.com/watch?v=YLcEAbb2iP0), see also [the console mods wiki](https://consolemods.org/wiki/Xbox:TSOP_Flashing)
  * Requires some more in-depth soldering and necessary wires
  * For Xbox revisions up to 1.4
* Non-TSOP Flash Modding:[ MrMario's Xyclo Mod tutorial](https://www.youtube.com/watch?v=6lVsoFpWr7w) using Xyclo Scripts
   * Only requires a bit of soldering and a UART USB Adapter
   * Works on Xbox revision 1.6


## HDMI/Component Adapter
<img width="566" height="566" alt="image" src="https://github.com/user-attachments/assets/cbe29e1f-73fa-4fe6-8b9c-2f0b0c16911d" />

The original Xbox can actually output HD signals, it just requires an adapter and changing settings in the original dashboard.
There are many different style of these adapters sold. Do not confuse these with composite to HDMI adapters, they will only try to upscale the composite signal.
You can also consider building one yourself if you have spare parts ([TechnoOnTop's Tutorial](https://www.youtube.com/watch?v=S8jFJjoIO8s)).

After you've connected the cable to the Xbox, go to the original Xbox dashboard (NOT your custom one) and enable the signals

<img width="366" height="331" alt="image" src="https://github.com/user-attachments/assets/fd25b8ae-f53a-40c8-90a8-1de0d30c7138" />


##Implimentation

To utilize HDMI signals for Steel Battalion specifically, asoftmodded or hard modded Xbox is require. Go down to the section on "Playing Steel Battalion from the Xbox HDD"



## Connecting via FTP
After your Xbox has been modded. Connect it to your network (the same one your PC is connected to) with an ethernet cable.
There are multiple FTP clients you can use. For this tutorial I will use FileZilla. On your computer, install Filezilla

In your custom dashboard, go to your network settings and find the Xbox's IP address. In filezilla you will input this address and connect to the Xbox's file structure.

### Dumping Steel Battalion to the Xbox HDD

https://www.youtube.com/watch?v=HB0sqDRoFe4

https://github.com/KilLo445/extract-xiso-gui





Playing Steel Battalion from the Xbox HDD
Getting Steel Battalion to use those signals requires
1.
2.	Enabling higher resolution options from the ORIGINAL Xbox Dashboard (see previous section)
3.	Extracting the ISO’s game files to a folder (with XISO)
4.	FTP connection to the Xbox
5.	Dumping the game to the Xbox 
6.	Altering the XBE file with Jay Xbox’s site, explanation below
7.	Running the XBE file from a modded dashboard
Jay Xbox’s Steel Battalion Patcher
Jay Xbox has provided a great website that allows customization of many of the game’s graphical options. Make a back-up of your original XBE file and upload a copy to the website and alter the options you wish. Put this file back on the console in the directory it came from. Then simply run the game from the XBE via a modded dashboard.
HDD performance can be improved with upgrades to the original console.
In-Depth Instructions: TBD
 
<img width="975" height="613" alt="image" src="https://github.com/user-attachments/assets/b1843ac4-80b4-4000-baab-8ebee880edc2" />


1. Get this https://github.com/KilLo445/extract-xiso-gui 2. In XISO Gui, Extract ISO to Directory, select the SB ISO 3. Take the XBE file, make a copy 4. Upload the XBE to this website https://jayxbox.com/Misc/SB.php 5. Load Patch Library > Archive > Most Recent > Misc Modifications, select the options you want 6. Click Download Modified Core, this is your new XBE 7. Put the new XBE into the SB directory (overwrite if necessary) 2. In XISO gui, Create XISO from directory, select the SB directory.


Improving Performance and Visuals on Emulator
Emulators
XEMU
Xemu cannot run the XBE files directly, to run the altered XBE files described above, Xemu must be running a modded dashboard and Cerbios (yes you are softmodding an emulator at this point), alternatively you can rebuild the ISO file  and run the game via the ISO.

Method 1. Softmodding Xemu

Method 2. Rebuilding the ISO 
https://github.com/xboxdev/extract-xiso
https://github.com/KilLo445/extract-xiso-gui
Utilize 


## Other additional Xbox Mods that can improve performance.
* IDE to SSD Adapter
* RAM Upgrade
* CPU Upgrade
