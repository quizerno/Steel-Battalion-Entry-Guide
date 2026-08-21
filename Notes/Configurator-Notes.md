<img width="2486" height="1996" alt="image" src="https://github.com/user-attachments/assets/b638ad0c-7193-4a58-aae4-aabd373e3605" />

# Sim Configuration Tool + Hotkey Fixes and Other Menu Options — requirements

## Sim Configuration Tool (SCT)

- **Pauses the VM at launch** for marked games. For Steel Battalion the pause
  is **right before the controller connects to the game**, so configuration is
  done before the game's controller check.
- A **window** opens where the player browses **profiles**, mostly per the
  controller the launched game expects.
- **Views mirror the real hardware**: left block, middle block, right block,
  **pedals**, and an **all three at once** view.
- **Calibration** is part of the tool.
- **Connects to the emulated Steel Battalion controller** for the SB games.
- **Connects a real SB controller to games that never supported it** — e.g. a
  different Xbox mech game — with a **default profile already built** for that
  game.
- Works with **USB passthrough automatically** — the user must NOT have to
  drop to a console and run passthrough commands as they do today.
- **Default profile shipped per game**; user profiles saved alongside.
- Also covers **racing wheels** and **cockpit/flight games** (Ace Combat-class)
  with joysticks/HOTAS.
- The specification must be **broad enough for everything Steel Battalion
  needs**, **flexible for other games**, and **adaptable to the other
  emulators**.

## Quality of Life for SCT

### SCT View
A **fourth section in the SCT view dropdown**, beside left/middle/right block.
Contents so far:

### Unbound Control List
Little window on the side that shows which controls still need bindings



## Mouse Options
- Steel Battalion's interaction with mouse movement is partially dependent on the usage.
- Weapon Aim (Right Stick): By default the weapon aim will limit the cursor to the window size of the main monitor.
- If the player decides to use a multi-monitor set-up, this limitation needs to be recognized, it could be indicated with some sort of optional border overlay

### Alt-to-look (Arma 3 style)
- A function for mouse users that do not have a left joystick
- On the original controller, the left joystic's hat-stick (called Sight Change in game) **controls the direction of the VT's camera** 
- Clicking down on the stick **re-centers the camera**
- Previously in emulator the stick's directions had been bound the arrow keys or the WASD keys, with the click-down being tied to another key (Q or X)
- Keyboard-and-mouse players should be able to **hold a toggle** to do this similar to how Arma 3 does free-look.
- This switches from the default mouse function which is **weapon aim**
- **It does not need to snap back to where it was before when released.** But the weapon aim location needs to be maintained.
- Either the cursor must be moved back to the original position, or something needs to be done to keep the relative center understood
- A suggested configuration might be **hold alt to have the mouse control the camera** while **middle mouse click re-centers the camera**
- **Possible Issues:** Check interactions with lock-on

## Consolidation

## Optional Controller Consolidation
- Note that this **Optional Controller Consolidation** which should not be confused with possible **Necessary Controller Solidation** for those with limited inputs
- **Duplicate Inputs:** For players who want to bind one control to multiple positions
- **One Toggle:** Allows an option to bind the **five toggle switches** to **one toggle**
- **One Start:** Allows an option to bind the **Hatch, Ignition, and Start** to **one button**
- **All Camera Control to Left:** For players without a middle block or don't wish to use one. Allows putting all camera controls on on the left block. Suggests positions on the Left Block for: Camera Zoom In/Out, Night Scope, and Line Color Change. 
- **All Combat Control to Right:** For players without a middle block or don't wish to use one. Allows putting all weapon controls on on the right block. Suggests positions on the Right Block for: F.S.S., Main Weapon Control, Sub Weapon Control, Reload, and Chaff.
- **Maintenance and Monitor:** Gives suggestions for remaining Middle Block and Monitor Controls if the user has selected the above two options.
    - **Maintenance:** includes F1, F2, F3, Washing, Extinguisher, Manipulator, Tank Detach and Override
    -  **Monitor:** includes Open/Close, Mode Select, Sub Monitor Mode Select, Map Zoom
### Necessary Controller Consolidation
- **Keyboard Map:** Provides suggested keyboard layouts for [various keyboard sizes](https://www.keychron.com/blogs/news/keyboard-size-layout-buying-guide) Maybe include options for Dvorak and AZERTY users.
- **No Middle Block:** Suggests positions for middle block controls if the player has no middle block.
- **No Pedals:** Looks for pressure sensitive buttons that the player can use if the player has pedals, this includes the Throttle
- **Throttle As Gear Shifter:** For players with no shifter but have a throttle. Allows Joystick Throttle axis to be mapped for switching between the 7 Gears.
- **Throttle As Gear Shifter + Pedal Combo:** For players with no shifter or pedals but have a throttle.
    - **Forward Axis:** Gear 1-7 and full Acceleration Pedal Press
    - **Neutral Axis:** Gear N
    - **Backward Axis:** Gear R and full Acceleration Pedal Press
- **Digital Gear Shifter:** For players with no Shifter or Throttle. Allows an option to have two buttons GEAR UP and GEAR DOWN to replace the Gear Lever. For players with no Shifter or Throttle.
- **Digital Tuner:** For players with no Throttle, Rotary Encoder, Thumb Roller, etc. Allows an option to have two buttons TUNE UP and TUNE DOWN to replace the Tuner Dials.
  
## Input Settings Menu: 

### Kiosk mode (hotkey)

- A **hotkey binding** in the normal hotkey binds.
- **Default: unbound, or Ctrl+Delete.**
- Toggling it **disables all other emulator hotkeys**.
- Rationale: Steel Battalion uses so many keys that it is genuinely better to
  disable the emulator's own hotkeys wholesale.
- The kiosk hotkey itself must stay live so it can be toggled back off.

### Toggle Fullscreen Switch
- Turns off Xemu's double-click that switches the emulator window between fullscreen mode and windowed mode
-**Default: Disables This**
- Rationale: not just for Steel Battalionm for FPS games that use the mouse this is a must-have..
- Rebinding to ALT+ENTER

## Display Settings Menu: 

### Toggle Menu Bar 
- Removes the Menu Bar.
-**Default: Menu Bar On**
- Rationale: Done so that mouse users don't accidentally click it during play and gives a bit more viewing room

### Toggle the Cursor Visibility 
-  Done so that it is not in the way of mouse users
- **Default: Cursor On**
- Rationale: Done for FPS games and Steel Battalion.


## Optimization
As it currently stands. Certain display options are only possible via rebuilding the ISO with an XBE file that altered with [JayXbox's patcher](https://jayxbox.com/Misc/SB.php).
If memory editing is possible we might be able to cut out the middle-man for some features like removing the film grain.


