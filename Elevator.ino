#include "WiFi.h"
#include <ezButton.h>
#include <ezOutput.h>

#define BTN_UP_PIN D0
#define BTN_DOWN_PIN D1
#define BTN_STOP_PIN D2
#define ELEVATOR_UP_PIN D7
#define ELEVATOR_DOWN_PIN D6
#define DEBOUNCE_TIME_MS 50

ezButton btnUp(BTN_UP_PIN);
ezButton btnDown(BTN_DOWN_PIN);
ezButton btnStop(BTN_STOP_PIN);
ezOutput elevatorUp(ELEVATOR_UP_PIN);
ezOutput elevatorDown(ELEVATOR_DOWN_PIN);

void setup() {
  Serial.begin(9600);
	pinMode(BTN_UP_PIN, INPUT_PULLUP);
	pinMode(BTN_DOWN_PIN, INPUT_PULLUP);
	pinMode(BTN_STOP_PIN, INPUT_PULLUP);

	WiFi.softAP("XIAO ESP32", "123456789");

	btnUp.setDebounceTime(DEBOUNCE_TIME_MS);
	btnDown.setDebounceTime(DEBOUNCE_TIME_MS);
	btnStop.setDebounceTime(DEBOUNCE_TIME_MS);
	elevatorUp.low();
	elevatorDown.low();
}

void loop() {
	btnUp.loop();
	btnDown.loop();
	btnStop.loop();

	if (btnUp.isPressed()) {
		Serial.println("Up button pressed");
		elevatorDown.low();
		delay(1000);
		elevatorUp.high();
	}

	if (btnDown.isPressed()) {
		Serial.println("Down button pressed");
		elevatorUp.low();
		delay(1000);
		elevatorDown.high();
	}

	if (btnStop.isPressed()) {
		Serial.println("Stop button pressed");
		elevatorUp.low();
		elevatorDown.low();
	}

	Serial.print("Host Name:");
  Serial.println(WiFi.softAPgetHostname());
  Serial.print("Host IP:");
  Serial.println(WiFi.softAPIP());
  Serial.print("Host IPV6:");
  Serial.println(WiFi.softAPIPv6());
  Serial.print("Host SSID:");
  Serial.println(WiFi.SSID());
  Serial.print("Host Broadcast IP:");
  Serial.println(WiFi.softAPBroadcastIP());
  Serial.print("Host mac Address:");
  Serial.println(WiFi.softAPmacAddress());
  Serial.print("Number of Host Connections:");
  Serial.println(WiFi.softAPgetStationNum());
  Serial.print("Host Network ID:");
  Serial.println(WiFi.softAPNetworkID());
  Serial.print("Host Status:");
  Serial.println(WiFi.status());
  delay(1000);
}
