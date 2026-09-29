#include <Joystick.h>

// Create Joystick object with x and y axis, 8 buttons and 1 hat switch, and a throttle
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,
  8, 1,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y Axis, No Z Axis
  false, false, false,   // No Rx, Ry, Rz
  false, true,          // No Rudder, Throttle
  false, false, false);  // No Accelerator, Brake, Steering


//In my case, I am converting a CH Flightstick Pro to USB
//The Flightstick Pro has x and y axis, 4 buttons, a four direction hatswitch, and a throttle
//Since my hatswitches are digital, I am defining them as buttons but can also define them as hatswitches later if I want.
//Hence I am declaring this with 8 buttons




//This is used to keep track of my pins and which button they refer to.
//  pinMode(5, INPUT_PULLUP); //L BUTTON (1)
//  pinMode(8, INPUT_PULLUP); //M BUTTON (2) 
//  pinMode(10, INPUT_PULLUP); //R BUTTON (3)
//  pinMode(6, INPUT_PULLUP); //TRIGGER (4)

  //pinMode(9, INPUT_PULLUP); //HAT UP (5)
  //pinMode(7, INPUT_PULLUP); //HAT DOWN (6)
  //pinMode(3, INPUT_PULLUP); //HAT LEFT (7)
  //pinMode(4, INPUT_PULLUP); //HAT RIGHT (8)


//The order of the pins in this array is very important.
const int buttonPins[] = {5, 8, 10, 6, 9, 7, 3, 4};

int negate = -1;


//This is in case I want to have the hatswitch defined as as a hatswitch
//const int hatPins[] = {9, 7, 3, 4}; // Up, Down, Left, Right

void setup() {
  // Initialize push buttons and hat pins with internal pull-ups
  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
   // pinMode(hatPins[i], INPUT_PULLUP);
  }

  // Start Joystick
  Joystick.begin();
}

void loop() {
  // Read Joystick X and Y axes
  //In my case, my x axis is backwards so I need to do some extra code to have it point in the right direction
  int xAxisVal = 1023-analogRead(A1);
  int yAxisVal = analogRead(A2);

  // Read throttle value
  int ThrottleVal = analogRead(A0);
  
  //Set values
  Joystick.setXAxis(xAxisVal);
  Joystick.setYAxis(yAxisVal);
  Joystick.setThrottle(ThrottleVal);


  // Read 8 main action buttons
  for (int i = 0; i < 8; i++) {
    Joystick.setButton(i, !digitalRead(buttonPins[i]));
    //Joystick.setButton(i + 1, !digitalRead(buttonPins[i]));
  }

  // // Process Digital Hat Switch (4 directional buttons)
  // int hatDirection = -1; // Center / Neutral
  // if (!digitalRead(hatPins[0])) hatDirection = 0;     // Up
  // else if (!digitalRead(hatPins[1])) hatDirection = 180;  // Down
  // else if (!digitalRead(hatPins[2])) hatDirection = 270;  // Left
  // else if (!digitalRead(hatPins[3])) hatDirection = 90;   // Right
  //Joystick.setHatSwitch(0, hatDirection);

  delay(50);
}
