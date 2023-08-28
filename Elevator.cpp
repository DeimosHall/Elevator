#include "Elevator.h"

Elevator::Elevator(int btnUpPin, int btnDownPin, int btnStopPin, int elevatorUpPin, int elevatorDownPin, int debounceTimeMs)
    : btnUp(btnUpPin), btnDown(btnDownPin), btnStop(btnStopPin), _elevatorUp(elevatorUpPin), _elevatorDown(elevatorDownPin) {
	
	this->CHANGE_DIRECTION_DELAY_MS = 2000;
	this->_state = STOPPED;
	this->_btnUpPin = btnUpPin;
	this->_btnDownPin = btnDownPin;
	this->_btnStopPin = btnStopPin;
  this->_debounceTimeMs = debounceTimeMs;
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

	if (_state == UP) {
		if (millis() - _now > CHANGE_DIRECTION_DELAY_MS) {
			_now = millis();
			Serial.println("here");
			_elevatorUp.high();
			_state = STOPPED;
		}
	}

	if (_state == DOWN) {
		if (millis() - _now > CHANGE_DIRECTION_DELAY_MS) {
			Serial.println("here2");
			_now = millis();
			_elevatorDown.high();
			_state = STOPPED;
		}
	}
}

void Elevator::moveUp() {
	_state = UP;
  _elevatorDown.low();
	_now = millis();
}

void Elevator::moveDown() {
	_state = DOWN;
  _elevatorUp.low();
	_now = millis();
}

void Elevator::stop() {
	_state = STOPPED;
  _elevatorUp.low();
  _elevatorDown.low();
}