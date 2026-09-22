# Steel Battalion Pedal Research 
**by AndyNumbers**

## Stock Pedal <br />
* Stock Pedals use a 10kohm B potentiometer with a 45 degree actuation. 

* A “B-type” pot is linear, as opposed to an “A-type” which is logarithmic (for audio volume applications typically)

The 45 degree actuation means that the pot only has to turn 45 degrees to go from “full-off” to “full-on”. The physical pot may still turn a total of 270 degrees like a standard potentiometer, so it’s important if you remote the pot to make sure it is set properly when it is reinstalled. Otherwise you could have it in a “dead zone” where no electrical actuation occurs because it is out of its 45 degree range. (I have never personally removed the pots in a set of SB pedals so I can’t confirm how much total physical range the pot has.)

The steel battalion controller uses a Vcc voltage of 3.3 volts for the pedals. Because of the 45 degree electrical actuation, the controller expects to read a value of 0 volts for “full off” and 3.3 volts for “full on”. This is also the reason why the pedals do not need to be calibrated. As long as the pots are set up correctly from the factory, the values should never be off spec. 

## Finding potential alternative pedals <br />
When looking for another set of pedals that can potentially be wired into the SB controller, we need to make sure the pedal’s pots are using a degree of electrical actuation, just like the stock pedals. Having this implies that the pedals work in a similar fashion to the SB pedals. The matching steering wheel expects to read a voltage of 0 for “full off” and the full Vcc voltage for “full on”. The actual degree value is not important. It could be 45, 60, or even 70. The important thing is that the pots have a degree value marked on them. If they do not, then they will NOT be compatible. 

_Aside: It doesn’t matter if the pots are 5k or 10k or 100k or any other value. Because of the degree of electrical actuation, the pots will behave as infinite resistance in one direction and zero resistance in the other direction. 
Having different resistance values will only potentially affect sensitivity._

**Pedals that might work but have not been tested** <br />
* Logitech G29 and similar (10k 70 pots) - a Japanese user has reportedly used this as a replacement
* Thrustmaster T3PA (B25K 60 pots) - currently awaiting adapters…testing soon!

**Example of pedals that will NOT work** <br />
* Arcade pedals that use a standard 5k pot without a degree value. 

These pedals are calibrated in game and read an arbitrary low-value voltage for “full-off” and an arbitrary high-value voltage for “full-on”. 
The SB controller cannot interpret this. I am looking into the possibility of replacing the pots on a set of arcade pedals to see if I can get the correct range of electrical actuation without having to modify the mechanical characteristics of the pedals. 

**Arcade pedal modification** <br />
I was able to get a set of San Francisco Rush arcade pedals working with Steel Battalion. The pots need to be swapped out with a RVQ24YS08-03-21S. You can find these on eBay from China for about $22 each. They are not cheap because they are mobility scooter pots designed for long life. This was the only angled pot that I could find that is regularly available to the public. Total investment was about $200, so not the cheapest solution. This pedal set is also designed to mount into an arcade cabinet so it would be a good idea to build some sort of wood or metal frame to mount the pedals onto. 

_(Angled pots from other pedal sets don’t seem to be available for public purchase. They are most likely specially manufactured specifically for each company.)_

When you swap on the new pots, you will need to perform a manual calibration by setting the pot to the correct setting. 
There will be a bit of dead space in the pedal movement, so you can either set the pot so that the dead space is at the beginning of the pedal press or at the end of the pedal press. 
(Ideally a 60 or 70 degree pot would eliminate this dead space if one could be located)



