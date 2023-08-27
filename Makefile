BOARD_TAG = esp32:esp32:XIAO_ESP32C3
MONITOR_PORT = /dev/cu.usbmodem1101

compile:
	arduino-cli compile --fqbn $(BOARD_TAG)

upload:
	arduino-cli upload -p $(MONITOR_PORT) --fqbn $(BOARD_TAG) --verbose

monitor:
	arduino-cli monitor -p $(MONITOR_PORT)

clean:
	arduino-cli cache clean

all: compile upload monitor