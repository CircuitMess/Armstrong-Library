#ifndef ARMSTRONG_LIBRARY_ARMSTRONG_H
#define ARMSTRONG_LIBRARY_ARMSTRONG_H

#include <CircuitOS.h>
#include <Input/InputShift.h>
#include "EncoderInput.h"
#include "ServoControl.h"
#include "LEDController.h"
#include "RGBController.h"
#include "LightSensor.h"

class ArmstrongImpl {
public:
	ArmstrongImpl();
	void begin();

	InputShift* getInput();

private:
	InputShift* input;

};

extern ArmstrongImpl Armstrong;
extern EncoderInput Encoders;
extern ServoControl Motors;
extern LEDController LED;
extern RGBController RGB;
extern LightSensor Sensor;

#endif //ARMSTRONG_LIBRARY_ARMSTRONG_H
