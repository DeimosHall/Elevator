#ifndef Elevator_H
#define Elevator_H

#include <ezButton.h>
#include <ezOutput.h>

class Elevator {
 private:
	enum State { UP, DOWN, STOPPED };
	State _state;
	int _btnUpPin;
	int _btnDownPin;
	int _btnStopPin;
  int _debounceTimeMs;
  ezOutput _elevatorUp;
  ezOutput _elevatorDown;
	unsigned long _now;
	int CHANGE_DIRECTION_DELAY_MS;

 public:
  Elevator(int btnUpPin, int btnDownPin, int btnStopPin, int elevatorUpPin, int elevatorDownPin, int debounceTimeMs);
  ezButton btnUp;
  ezButton btnDown;
  ezButton btnStop;
  void setup();
  void loop();
	void moveUp();
	void moveDown();
	void stop();
};

#endif