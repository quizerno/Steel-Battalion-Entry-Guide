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

5. **Optional:** Depending on your operating system got to the following directory:
   * **Windows:** C:\Users\{username}\AppData\Local\Arduino15\packages\ogxbox\hardware\avr\1.0.1\
   * **macOS:** /Users/{username}/Library/Arduino15/packages/ogxbox/hardware/avr/1.0.1/
   * **Linux:** /home/{username}/.arduino15/packages/ogxbox/hardware/avr/1.0.1/

Find the boards.txt file and replace it with github.com/quizerno/Steel-Battalion-Entry-Guide/blob/main/Configuration Files/OGXBOX-PAD/boards.txt. Restart your IDE.

What this will do is change the emulated VID/PID from the OG Xbox S Controller (vid=0x045E, pid=0x0289) to the Steel Battalion Controller (vid=0x9A7B, pid=0xD000). It will also change the name of the board profile so you can confirm that the file was recognized. 

**This step is not strictly necessary**, but it will allow your microcontroller to be recognized as a Steel Battalion Controller should you try to use it with an emulator or other software in this guide.

5. Plug in your arduino board, when you select your board, you will select your board with the w/ OGXboxSBC option (ie. for a Pro Micro or Micro you will select "Arduino Micro w/ OGXBoxSBC", if you did not replace the file in step 5 it will just be "Arduino Micro w/ OGXBox")

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
