#include "Armstrong.h"
#include <Loop/LoopManager.h>
#include "Pins.hpp"

ArmstrongImpl Armstrong;
LEDController LED;
EncoderInput Encoder;
LEDRGBController RGB;
LightSensor Sensor;
ServoControl Servo;

ArmstrongImpl::ArmstrongImpl(){

}

void ArmstrongImpl::begin(){
	disableCore0WDT();
	disableCore1WDT();

	Encoder.begin();
	LED.begin();
	RGB.begin();
	Sensor.begin();
	Servo.begin();

	input = new InputShift(14, 27, 26, 8);
	input->begin();
	LoopManager::addListener(input);
}

InputShift* ArmstrongImpl::getInput(){
	return input;
}
