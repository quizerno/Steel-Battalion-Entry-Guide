# Configurator Process Description

## Step 1.
* **Input:** Select Xbox port (Default Port 1)
* **Input:** Scan for devices
* **Output:** Display devices, see if OEM Steel Batallion Controller is detected
* **Input:** Select detected devices you want to use 
  * **Input:** Include Keyboard if desired
  * **Input:** Include Mouse if desired
    
* **Input:** Proceed to Next Step

## Step 2.
* **Output:** For all previously selected devices, display names and data gather all available inputs.
  * Checks how many inputs are available, compares to how many are needed.
  * Inputs for each block are color coded Left (Red), Middle (Green), Right (Blue), Pedal (Orange)
* **Input:** Asks if user would like to calibrate the available analog inputs
  * Left Joystick (signed 16 bit X Axis)
  * Left Hatstick (signed 16 bit X-Y Axis)
  * Right Joystick (unsigned 16 bit X-Y Axis)
