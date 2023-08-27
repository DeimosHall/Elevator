#include "Elevator.h"

Elevator::Elevator(int btnUpPin, int btnDownPin, int btnStopPin, int elevatorUpPin, int elevatorDownPin, int debounceTimeMs) : btnUp(btnUpPin), btnDown(btnDownPin), btnStop(btnStopPin), _elevatorUp(elevatorUpPin), _elevatorDown(elevatorDownPin) {
  _btnUpPin = btnUpPin;
  _btnDownPin = btnDownPin;
  _btnStopPin = btnStopPin;
  _elevatorUpPin = elevatorUpPin;
  _elevatorDownPin = elevatorDownPin;
  _debounceTimeMs = debounceTimeMs;
}

void Elevator::setup() {
	Serial.begin(9600);
	pinMode(_btnUpPin, INPUT_PULLUP);
	pinMode(_btnDownPin, INPUT_PULLUP);
	pinMode(_btnStopPin, INPUT_PULLUP);

	btnUp.setDebounceTime(_debounceTimeMs);
	btnDown.setDebounceTime(_debounceTimeMs);
	btnStop.setDebounceTime(_debounceTimeMs);
	_elevatorUp.low();
	_elevatorDown.low();
}

void Elevator::loop() {
	this->btnUp.loop();
	this->btnDown.loop();
	this->btnStop.loop();
}

void Elevator::moveUp() {
	Serial.println("Up button pressed");
	_elevatorDown.low();
	delay(1000);
	_elevatorUp.high();
}

void Elevator::moveDown() {
	Serial.println("Down button pressed");
	_elevatorUp.low();
	delay(1000);
	_elevatorDown.high();
}

void Elevator::stop() {
	Serial.println("Stop button pressed");
	_elevatorUp.low();
	_elevatorDown.low();
}