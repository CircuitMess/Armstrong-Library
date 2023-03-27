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

	LED.begin();
	Encoder.begin();
	RGB.set(0,0,0);
	Sensor.begin();
	Servo.begin();

	input = new InputShift(14, 27, 26, 8);
	input->begin();
	LoopManager::addListener(input);
}

InputShift* ArmstrongImpl::getInput(){
	return input;
}
