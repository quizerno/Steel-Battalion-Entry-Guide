# 3D. Custom Pedals
**(Adapted or DIY Pedals)**

Creating or adapting pedals for the original controller or for use with PC



## Original Controller Pedals

<img width="975" height="592" alt="image" src="https://github.com/user-attachments/assets/61031888-86cc-48f7-a8e4-929d80e0cd4c" />

The original pedals use three 10K Type B potentiometers. If you don’t understand this, it means that the game can detect different levels of pressure hence why it is analogue.

**Specifications**
* Three 10K Type B potentiometers, these have 3 terminals each.
 * Input lines connected to the same 3.3 volt wire.
 * Ground line connected to the same ground wire.
 * Output line connected to different return wires.

**In-Game Function**
|Left Pedal|Middle Pedal|Right Pedal|
|---|---|---|
| **Slide Step:** Despite using the potentiometer, only reads the signal digitally. The pressure does not matter. But it does read the length of time you hold down the pedal, longer press means longer slide.|**Break:** has several positions, but a full stop requires a full press.|**Accelerator:** has several positions. A half-press will not reach max speed. A full press will reach max speed. A full press of this pedal is necessary after becoming unbalanced.|

## Original Controller Replacement Custom Pedals<br/>
This is where things might get confusing. 
What You Need:
* Three Pedals that use linear potentiometers or have had their signals converted to do such (see below)
* A Male Mini 6DIN connector **with all 6 lines**, only 5 lines are used but a regular PS/2 Cable might not work if it omits two of the lines. This connects to the central control block.
* A circuit board or a way to splice cables together.

### 3D Printing

There are a multitude of 3D printable options available. These are perfectly fine options as long as you use the 10K Type B Linear potentiometers

* https://makerworld.com/en/models/1578870-sim-pedals#profileId-2657983
* https://www.printables.com/model/770673-sim-racing-pedals-with-load-cell
* https://www.thingiverse.com/thing:4812405
* https://www.youtube.com/watch?v=I4P86DJPXAc


### Logitech
Logitech Pedal modules connect to their main unit via DE-9 Connector.  <br/>
The potentiometers are the same as the original pedals.  <br/>
[Harcroft](https://x.com/OGX_Harcroft) sells an adaptor which converts the the DE9 connector to the Original Controller's Mini-Din6.  <br/>
If you would like to create your own, follow the schematic below.  <br/>

<img width="302.5" height="254.5" alt="image" src="https://github.com/user-attachments/assets/b740d8c6-5328-447d-a2ae-1e075b457dff" />

### Thrustmaster <br/>
Thrustmaster Pedals require an electronics adapter that is also sold by Harcroft.<br/>
This adapter has worked with the following models: T3PA, T3PA-GT, T3PM, T-LCM<br/>
<img width="312.5" height="277.5" alt="image" src="https://github.com/user-attachments/assets/5b9c1aab-2553-40f9-9e73-a629fdfe66d1" />

### Go-kart and Industrial Pedals
Online, there are a couple of cheap options for pedals that are normally intended for non-gaming.<br/>
These pedals, however, use Hall Effect sensors which are not linear. Again, Harcroft sells an adapter for this particular model, and has provided schematics if you wish to build it yourself.

<img width="1146" height="489" alt="image" src="https://github.com/user-attachments/assets/41432c9e-959a-4608-a047-b896b9fe84c8" />

<img width="441.5" height="408" alt="image" src="https://github.com/user-attachments/assets/67a57e8d-1abc-4eb0-9616-f703e49e3347" />



#### The digital option

If you 

<img width="1121" height="404" alt="image" src="https://github.com/user-attachments/assets/23dd0a4c-8518-4844-96a4-aa73d9e6ab53" />




## Adapted Pedals<br/>


## DIY HID Pedals<br/>


## DIY GPIO Pedals<br/>


































**Adapting Pedals for use with the original controller**




**Pedals for a Custom Controller**<br/>
Custom Controllers have two options. Using the GPIO pins on the adapter (see DIY Pedals) or using the USB host to plug-in a USB Pedal controller:

## Emulator Play
If you are looking for a simple plug-in and play option, any USB Pedal Controller will work. <br/>
If you are looking for a DIY option, you will need:
* Three DIY Pedals (see below)
* HID Microcontroller, either an arduino or something similar.


## Options for Pedals

As long as you 
### Adapted Pedals
In the case of adapting pedals, 


### DIY Pedals
<br/>


1. Buying set of pre-made simulation pedals, making adjustments 
2. DIY: Using a 3D printer and making them yourself with necessary electronics and springs
3. DIY: Buying go-kart and/or industrial pedals, making adjustments
4. DIY: Using microswitch pedals




Existing Potentiometer Pedals
Car Simulation Racing Pedals will work if they use the same potentiometers or might require some adjustments. However you must be sure to get a set that contains three, or add an additional pedal to a set of two
Popular options include Logitech or Thrustmaster
 
The Logitech G29 requires building an adapter. The pinout below shows the connections you need
 

Pedals from scratch
Online you will find a few different 3D Printer projects that create a mechanism like this the original torsion spring system. If you have a 3D printer and can buy the parts, then you have many options.

(list options here)


Hall Effect Pedals
A cheap alternative for those without 3D printers, is the use of Pedals that use Hall-Effect sensors. Unlike the Potentiometer pedals, these ARE sold online and for decent prices. However, the Hall Effect sensors require creation of a separate circuit to properly stabilize the voltage for Steel Battalion
 
 

Harcroft has created a circuit to convert the voltages properly, specifically for the GoKart pedals above. If you have knowledge of electronics you can follow diagram. Or buy a board from him.




Microswitch Pedals
If you want to use cheap microswitch pedals, this is not out of the question. But there will be no pressure detection. The difference is that you will, not be able to control the accelerator as well, you will need to release the pedal more frequently.
The wiring is exactly the same as the potentiometer pedals

<img width="628" height="344" alt="image" src="https://github.com/user-attachments/assets/2fe090e2-6051-40e2-8e81-118e54797482" />




 
 <img width="975" height="404" alt="image" src="https://github.com/user-attachments/assets/903dc332-d521-40c4-b7f0-2974480a3a9a" />


<img width="816" height="404" alt="image" src="https://github.com/user-attachments/assets/fc4a5eea-265b-486e-aa33-03c6e15ccb6e" />





<img width="716" height="620" alt="image" src="https://github.com/user-attachments/assets/2877dfc7-cc57-432e-ae55-9bc90b2524b0" />
Torsion Spring Pedal Mechanism

<img width="752" height="441" alt="image" src="https://github.com/user-attachments/assets/920c7f72-2beb-47f2-a2c2-c93c393f4b9c" />
Compression Spring Pedal Mechanism


