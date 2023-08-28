#include "Elevator.h"

#define BTN_UP_PIN D0
#define BTN_DOWN_PIN D1
#define BTN_STOP_PIN D2
#define ELEVATOR_UP_PIN D7
#define ELEVATOR_DOWN_PIN D6
#define DEBOUNCE_TIME_MS 50

Elevator elevator(BTN_UP_PIN, BTN_DOWN_PIN, BTN_STOP_PIN, ELEVATOR_UP_PIN, ELEVATOR_DOWN_PIN, DEBOUNCE_TIME_MS);

void setup() {
  Serial.begin(9600);
	elevator.setup();
}

void loop() {
  elevator.loop();

  if (elevator.btnUp.isPressed()) {
		Serial.println("Up button pressed");
    elevator.moveUp();
  }

  if (elevator.btnDown.isPressed()) {
		Serial.println("Down button pressed");
    elevator.moveDown();
  }

  if (elevator.btnStop.isPressed()) {
		Serial.println("Stop button pressed");
    elevator.stop();
  }
}
