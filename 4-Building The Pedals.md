# 4B. Building The Pedals


For if you have a controller and need pedals.
What You Need

* a Mini 6DIN connector WITH ALL 6 LINES, only 5 lines are used but a regular PS/2 Cable might not work if it omits two of the lines. This connects to the central control block
* a circuit board or a way to splice cables together
* Three Pedals with potentiometers, and will transmit up to 3.33v (see options below)

The Pedals in the Original Controller and What They Do
The original game controller uses three potentiometers. If you don’t understand this, it means that the game can detect different levels of pressure (analog)
The best way to describe this in layman’s terms is that this not the same as pressing a button, it is the level of pressing a button.
How it works in the game varies between the three pedals:
The Slide-Step Pedal (left pedal) despite using the potentiometer, only reads the signal digitally. The pressure does not matter. But it does read the length of time you hold down the pedal, longer press = longer slide.
The Break Pedal (middle pedal)  - The break pedals has several positions, but a full stop requires a full press.
The Accelerator Pedal (right pedal) does read the pressure. A half-press will not reach max speed. A full press will reach max speed (depending on the terrain and VT of course). A full press of this pedal is necessary after becoming unbalanced.


The original controller utilizes three 10K Type B potentiometers 
The original controller’s mechanism utilized torsion springs to rotate the potentiometer,This was later revised to a compression spring system
 
Torsion Spring Pedal Mechanism
 
Compression Spring Pedal Mechanism

(https://www.youtube.com/watch?v=6TYqZhD9kCM)



Options for Pedals
Simply put your options are
1. Buying set of pre-made simulation pedals, making adjustments 
2. DIY: Using a 3D printer and making them yourself with necessary electronics and springs
3. DIY: Buying go-kart and/or industrial pedals, making adjustments
4. DIY: Using microswitch pedals

Ideally you want to get three pedals that use 10K Type B potentiometers to match the original. 10K Type B potentiometers themselves are quite cheap. But getting them into a physical housing for pedals requires some work. See Andynumbers research I have included 



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
 
 
