#include <usbd_xid.h> // <- This contains your usbd_sbattalion_in_t structure!


//The order of the pins in this array is very important.
const int buttonPins[] = {5, 8, 10, 6, 9, 7, 3, 4};



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

  //set up pins
  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }


}//end of setup

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
}
