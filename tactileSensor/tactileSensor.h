#ifndef TACTILESENSOR_H
#define TACTILESENSOR_H
#include <Trill.h>
// Header file for tactile sensor with private Trill object, public constructor to setup sensor and public function to return average sensor value
class tactileSensor {

public:
	tactileSensor();
	int averageTipValue();
private:
	Trill sensor;
};