#include <Joystick.h>

// Create Joystick object with 4 buttons and 1 hat switch
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,
  8, 1,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y Axis, No Z Axis
  false, false, false,   // No Rx, Ry, Rz
  false, true,          // No Rudder, Throttle
  false, false, false);  // No Accelerator, Brake, Steering

//const int buttonPins[] = {10, 5, 2, 6};



//const int buttonPins[] = {2, 10, 5, 6};

//5 = button 1

//10 = button 3
//6 = button 4



//  pinMode(5, INPUT_PULLUP); //L BUTTON (1)
//  pinMode(8, INPUT_PULLUP); //M BUTTON (2) 
//  pinMode(10, INPUT_PULLUP); //R BUTTON (3)
//  pinMode(6, INPUT_PULLUP); //TRIGGER (4)

  //pinMode(9, INPUT_PULLUP); //HAT UP
  //pinMode(7, INPUT_PULLUP); //HAT DOWN
  //pinMode(3, INPUT_PULLUP); //HAT LEFT
  //pinMode(4, INPUT_PULLUP); //HAT RIGHT


const int buttonPins[] = {5, 8, 10, 6, 9, 7, 3, 4};

int negate = -1;


//CORRECT
//const int hatPins[] = {9, 7, 3, 4}; // Up, Down, Left, Right

void setup() {
  // Initialize push buttons and hat pins with internal pull-ups
//  pinMode(2, INPUT_PULLUP);
  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
   // pinMode(hatPins[i], INPUT_PULLUP);
  }

  // Start Joystick
  Joystick.begin();
}

void loop() {
  // Read and set Joystick X and Y axes
  int ThrottleVal = analogRead(A0);
  int xAxisVal = 1023-analogRead(A1);
  int yAxisVal = analogRead(A2);
  //xAxisVal = xAxisVal*negate;

  Joystick.setXAxis(xAxisVal);
  Joystick.setYAxis(yAxisVal);
  Joystick.setThrottle(ThrottleVal);
  // Read Joystick push button (Pin 2)
  //Joystick.setButton(0, !digitalRead(2));

  // Read 4 main action buttons
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
