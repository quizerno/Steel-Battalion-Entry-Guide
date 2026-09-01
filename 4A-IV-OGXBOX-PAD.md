# 4A-IV. OGXBOX-PAD

[OGXBOX-PAD](https://github.com/eolvera85/OGXBOX-PAD) by eolvera85 is effectively a port of ogx360 to the arduino platform.
Because of this, unlike the previous firmware options, OGXBOX-PAD utilizes arduino boards.

Because it does not have any host libraries, this is effectively a GPIO only option

## Hardware

If you are unfamiliar with arduino boards, they are effectively multipurpose microcontrollers. 
They are noted for their 

## Set-up

* Install the arduino IDE
* 

```
#include <usbd_xid.h> // <- This contains your usbd_sbattalion_in_t structure!

const int fireButtonPin = 2;

// 1. Declare the Steel Battalion layout data structure defined in your file
usbd_sbattalion_in_t sbPacket; 

void setup() {
  pinMode(fireButtonPin, INPUT_PULLUP);

  // Tell the core engine to switch from a Duke pad to Steel Battalion mode
  XID().setType(STEELBATTALION);
  XID().begin();

  // Clear the packet memory layout completely
  memset(&sbPacket, 0, sizeof(sbPacket));
  
  // Set up the mandatory initial headers defined by the original hardware
  sbPacket.startByte = 0x00; 
  sbPacket.bLength = 0x1A; // Report Size is exactly 26 bytes   
}

void loop() {
  // Read physical pin 2 (LOW means button is actively pressed)
  bool isPressed = (digitalRead(fireButtonPin) == LOW);

  // 2. Map using the explicit naming conventions found in your file!
  // 'wButtons' is an array of 3 words. 'SBC_W0_RIGHTJOYMAINWEAPON' belongs in slot 0.
  if (isPressed) {
    sbPacket.wButtons[0] |= SBC_W0_RIGHTJOYMAINWEAPON; 
  } else {
    sbPacket.wButtons[0] &= ~SBC_W0_RIGHTJOYMAINWEAPON;
  }

  // 3. THE FOUND FUNCTION CALL: Broadcast the data packet down the USB wire.
  // We pass our packet pointer and the exact length size (26 bytes)
  XID().sendReport(&sbPacket, sizeof(sbPacket));

  delay(10); // 10ms polling interval to match console expectations
}```
