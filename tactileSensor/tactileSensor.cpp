#include "tactileSensor.h"
#include <Trill.h>

// Constructor that setups the trill sensor
tactileSensor::tactileSensor() {
	trillSensor.setup(Trill::TRILL_FLEX);
	trillSensor.setPrescaler(4);
	delay(10);
	trillSensor.updateBaseline();
}

// Method that reads the sensor and averages only the tip points which is then returned
int tactileSensor::averageTipValue() {
	int eachVal[30];
	int counter = 0;
	int average = 0;
	trillSensor.requestRawData();

	while (trillSensor.rawDataAvailable() > 0) {
		int data = trillSensor.rawDataRead();
		eachVal[counter] = data;
		counter++;
	}

	for (int i = 27; i < 30; i++) average += eachVal[i];

	return average / 4;
	
}