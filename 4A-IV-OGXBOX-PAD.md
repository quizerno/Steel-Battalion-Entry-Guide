# 4A-IV. OGXBOX-PAD

[OGXBOX-PAD](https://github.com/eolvera85/OGXBOX-PAD) by eolvera85 is effectively a port of ogx360 to the arduino platform.
Because of this, unlike the previous firmware options, OGXBOX-PAD utilizes arduino boards.

Because it does not have any host libraries (althought they could be added), this is effectively a GPIO only option
If you are unfamiliar with arduino boards, they are effectively multipurpose microcontrollers, noted for their simplicity. 

## Set-up
1. Install the Arduino IDE
2. Depending on if you are Mac/Linux/Windows, look at the instructions for ["adding third party boards."](https://support.arduino.cc/hc/en-us/articles/360016466340-Add-third-party-platforms-to-the-Boards-Manager-in-Arduino-IDE)
3. At the "Additional Boards Manager URLs" add ```https://raw.githubusercontent.com/eolvera85/OGXBOX-PAD/main/releases/package_ogxbox_index.json```
4. Go to "Boards Manager" and add "OGXBOX AVR Boards"
5. Plug in your arduino board, when you select your board, you will select your board with the w/ OGXbox option (ie. for a Pro Micro or Micro you will select "Arduino Micro w/ OGXBox)

## Defining Your Inputs
From here, this will be a matter of handwiring your inputs and defining them in the Arduino IDE.

In the example below, the Arduino's PIN 2 is set to be press when connected to ground. When it is pressed it triggers the Fire Main Weapon input.

TO DO: examples of analog


**Example**<br/>
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
}
```

## Flashing
The Arduino IDE has a verify and upload button, it will also flash the OGXbox core to your board.
It should be noted that when your board is flashed with this core it will start having the VID and PID of the Original Xbox S Controller (VID 0x045E / PID 0x0289).
