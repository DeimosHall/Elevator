#ifndef Elevator_H
#define Elevator_H

#include <ezButton.h>
#include <ezOutput.h>

class Elevator {
 private:
  int _btnUpPin;
  int _btnDownPin;
  int _btnStopPin;
  int _elevatorUpPin;
  int _elevatorDownPin;
  int _debounceTimeMs;
  ezOutput _elevatorUp;
  ezOutput _elevatorDown;

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