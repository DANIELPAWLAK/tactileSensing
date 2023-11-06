/*
   ____  _____ _        _
   | __ )| ____| |      / \
   |  _ \|  _| | |     / _ \
   | |_) | |___| |___ / ___ \
   |____/|_____|_____/_/   \_\
http://bela.io

\example flex-print-raw

Trill Flex Print Slider
=======================

This is an example of how to communicate with the Trill Flex
sensor using the Trill Arduino library.

The sensor is set to Differential mode and readings from each of the
capacitive connections on the sensor are printed to the serial port.

You can find our Processing library for visualising here:
https://github.com/BelaPlatform/trill-processing-library/
The accompanying Processing sketch, `TrillFlexRaw.pde`, listens for
touch information on the Arduino serial port* and displays it in a
render of a each of the channels of Trill Flex.
 */

#include <Trill.h>

Trill trillSensor;

void setup() {
	// put your setup code here, to run once:
	Serial.begin(115200);
	int ret = trillSensor.setup(Trill::TRILL_FLEX);
	if(ret != 0) {
		Serial.println("failed to initialise trillSensor");
		Serial.print("Error code: ");
		Serial.println(ret);
	}
  // when the slider is connected we increase the
  // prescaler to deal with the increased baseline
  // capacitance it brings
  trillSensor.setPrescaler(4);
  delay(10);
  // after any prescaler change, it's always good to update
  // the baseline, too.
  trillSensor.updateBaseline();
}
#define nothing 11
#define holding 12
#define slipping 13
int eachVal[30];
int counter = 0;
void loop() {
	// put your main code here, to run repeatedly:
	delay(100);
	trillSensor.requestRawData();

	while(trillSensor.rawDataAvailable() > 0) {
		int data = trillSensor.rawDataRead();
		eachVal[counter] = data;
    counter++;
	}
  counter = 0;
  for (int i = 26; i < 30; i++) {
    Serial.print(eachVal[i]);
    Serial.print(" ");
  }
	Serial.println("");
}
