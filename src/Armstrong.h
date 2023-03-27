#ifndef ARMSTRONG_LIBRARY_ARMSTRONG_H
#define ARMSTRONG_LIBRARY_ARMSTRONG_H

#include <Input/InputShift.h>
#include "EncoderInput.h"
#include "LEDController.h"
#include "LEDRGBController.h"
#include "LightSensor.h"
#include "ServoControl.h"

class ArmstrongImpl {
public:
	ArmstrongImpl();
	void begin();

	InputShift* getInput();

private:
	InputShift* input;

};

extern ArmstrongImpl Armstrong;
extern LEDController LED;
extern EncoderInput Encoder;
extern LEDRGBController RGB;
extern LightSensor Sensor;
extern ServoControl Servo;

#endif //ARMSTRONG_LIBRARY_ARMSTRONG_H
