#include "Armstrong.h"
#include <Loop/LoopManager.h>
#include <SPIFFS.h>

ArmstrongImpl Armstrong;
EncoderInput Encoders;
ServoControl Motors;
LEDController LED;
RGBController RGB;
LightSensor Sensor;

ArmstrongImpl::ArmstrongImpl(){

}

void ArmstrongImpl::begin(){
	if(!SPIFFS.begin()){
		printf("SPIFFS error\n");
	}

	Encoders.begin();
	LED.begin();
	RGB.begin();
	Sensor.begin();
	Motors.begin();

	input = new InputShift(SHIFTIN_DATA, SHIFTIN_CLOCK, SHIFTIN_LOAD, 8);
	input->begin();
	LoopManager::addListener(input);
}

InputShift* ArmstrongImpl::getInput(){
	return input;
}

Slot ArmstrongImpl::btnToSlot(uint8_t i){
	auto pair = BtnSLotMap.find(i);
	if(pair == BtnSLotMap.end()) return None;

	return pair->second;
}
