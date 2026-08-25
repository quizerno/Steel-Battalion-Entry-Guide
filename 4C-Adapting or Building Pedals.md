# 4C. Adapting or Building Pedals


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
<img width="628" height="344" alt="image" src="https://github.com/user-attachments/assets/2fe090e2-6051-40e2-8e81-118e54797482" />


<img width="1121" height="404" alt="image" src="https://github.com/user-attachments/assets/23dd0a4c-8518-4844-96a4-aa73d9e6ab53" />


<img width="1146" height="489" alt="image" src="https://github.com/user-attachments/assets/41432c9e-959a-4608-a047-b896b9fe84c8" />

 
 <img width="975" height="404" alt="image" src="https://github.com/user-attachments/assets/903dc332-d521-40c4-b7f0-2974480a3a9a" />


<img width="816" height="404" alt="image" src="https://github.com/user-attachments/assets/fc4a5eea-265b-486e-aa33-03c6e15ccb6e" />


<img width="975" height="592" alt="image" src="https://github.com/user-attachments/assets/61031888-86cc-48f7-a8e4-929d80e0cd4c" />


<img width="605" height="509" alt="image" src="https://github.com/user-attachments/assets/b740d8c6-5328-447d-a2ae-1e075b457dff" />


<img width="716" height="620" alt="image" src="https://github.com/user-attachments/assets/2877dfc7-cc57-432e-ae55-9bc90b2524b0" />
Torsion Spring Pedal Mechanism

<img width="752" height="441" alt="image" src="https://github.com/user-attachments/assets/920c7f72-2beb-47f2-a2c2-c93c393f4b9c" />
Compression Spring Pedal Mechanism


Steel Battalion Pedal Research 
by AndyNumbers

Stock Pedals
Stock Pedals use a 10kohm B potentiometer with a 45 degree actuation. 

A “B-type” pot is linear, as opposed to an “A-type” which is logarithmic (for audio volume applications typically)

The 45 degree actuation means that the pot only has to turn 45 degrees to go from “full-off” to “full-on”. The physical pot may still turn a total of 270 degrees like a standard potentiometer, so it’s important if you remote the pot to make sure it is set properly when it is reinstalled. Otherwise you could have it in a “dead zone” where no electrical actuation occurs because it is out of its 45 degree range. (I have never personally removed the pots in a set of SB pedals so I can’t confirm how much total physical range the pot has.)

The steel battalion controller uses a Vcc voltage of 3.3 volts for the pedals. Because of the 45 degree electrical actuation, the controller expects to read a value of 0 volts for “full off” and 3.3 volts for “full on”. This is also the reason why the pedals do not need to be calibrated. As long as the pots are set up correctly from the factory, the values should never be off spec. 

Finding potential alternative pedals
When looking for another set of pedals that can potentially be wired into the SB controller, we need to make sure the pedal’s pots are using a degree of electrical actuation, just like the stock pedals. Having this implies that the pedals work in a similar fashion to the SB pedals. The matching steering wheel expects to read a voltage of 0 for “full off” and the full Vcc voltage for “full on”. The actual degree value is not important. It could be 45, 60, or even 70. The important thing is that the pots have a degree value marked on them. If they do not, then they will NOT be compatible. 

Aside: It doesn’t matter if the pots are 5k or 10k or 100k or any other value. Because of the degree of electrical actuation, the pots will behave as infinite resistance in one direction and zero resistance in the other direction. Having different resistance values will only potentially affect sensitivity. 

Pedals that might work but have not been tested:
Logitech G29 and similar (10k 70 pots) - a Japanese user has reportedly used this as a replacement
Thrustmaster T3PA (B25K 60 pots) - currently awaiting adapters…testing soon!

Example of pedals that will NOT work: arcade pedals that use a standard 5k pot without a degree value. These pedals are calibrated in game and read an arbitrary low-value voltage for “full-off” and an arbitrary high-value voltage for “full-on”. The SB controller cannot interpret this. I am looking into the possibility of replacing the pots on a set of arcade pedals to see if I can get the correct range of electrical actuation without having to modify the mechanical characteristics of the pedals. 

Arcade pedal modification:
I was able to get a set of San Francisco Rush arcade pedals working with Steel Battalion. The pots need to be swapped out with a RVQ24YS08-03-21S. You can find these on eBay from China for about $22 each. They are not cheap because they are mobility scooter pots designed for long life. This was the only angled pot that I could find that is regularly available to the public. Total investment was about $200, so not the cheapest solution. This pedal set is also designed to mount into an arcade cabinet so it would be a good idea to build some sort of wood or metal frame to mount the pedals onto. 

(Angled pots from other pedal sets don’t seem to be available for public purchase. They are most likely specially manufactured specifically for each company.)

When you swap on the new pots, you will need to perform a manual calibration by setting the pot to the correct setting. There will be a bit of dead space in the pedal movement, so you can either set the pot so that the dead space is at the beginning of the pedal press or at the end of the pedal press. (Ideally a 60 or 70 degree pot would eliminate this dead space if one could be located)



