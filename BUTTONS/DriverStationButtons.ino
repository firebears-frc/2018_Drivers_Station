// Arduino code for the 2018 Firebears driver station.

#include <Joystick.h>

Joystick_ Joystick;

void setup() {
  // Initialize Button Pins
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
}


// Last state of the button
int lastButtonState[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void loop() {

  // Read pin values
  for (int index = 2; index < 17; index++)
  {
    int currentButtonState = !digitalRead(index);
    if (currentButtonState != lastButtonState[index])
    {
      lastButtonState[index] = currentButtonState;

      if (index == 10) {
        Joystick.setButton(7 - 1, currentButtonState);
      }
      if (index == 16) {
        Joystick.setButton(9 - 1, currentButtonState);
      }
      if (index == 14) {
        Joystick.setButton(14 - 1, currentButtonState);
      }
      if (index == 15) {
        Joystick.setButton(1 - 1, currentButtonState);
      }
      if (index == 9) {
        Joystick.setButton(13 - 1, currentButtonState);
      }
      if (index == 4) {
        Joystick.setButton(15 - 1, currentButtonState);
      }
      if (index == 5) {
        Joystick.setButton(16 - 1, currentButtonState);
      }
      if (index == 2) {
        Joystick.setButton(17 - 1, currentButtonState);
      }
      if (index == 3) {
        Joystick.setButton(18 - 1, currentButtonState);
      }
      if (index == A2) {
        Joystick.setButton(12 - 1, currentButtonState);
      }


    }

    unsigned int potValue = analogRead(A1);
    unsigned int throttleValue = map(potValue, 0, 1023, 0, 1023);
    Joystick.setThrottle(throttleValue);
  }

  delay(50);
}
