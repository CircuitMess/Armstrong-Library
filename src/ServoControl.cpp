#include <Loop/LoopManager.h>
#include "ServoControl.h"

ServoControl::ServoControl(){

}

ServoControl::~ServoControl(){
	end();
}

void ServoControl::setPos(uint8_t i, uint8_t pos){
	if(i >= 4) return;
	pwmValues[i] = constrain(pos, Ranges[i].min, Ranges[i].max);
	ledcWrite(i, pwmValues[i]);
}

uint8_t ServoControl::getPos(uint8_t i){
	if(i >= 4) return 0;
	return ledcRead(i);
}

void ServoControl::begin(){
	for(int i = 0; i < 4; i++){
		pwmValues[i] = (Ranges[i].min + Ranges[i].max) / 2;

		ledcSetup(i, 200, 8);
		ledcAttachPin(pwmPins[i], i);
		ledcWrite(i, pwmValues[i]);
	}
}

void ServoControl::end(){
	for(int i = 0; i < 4; i++){
		ledcDetachPin(pwmPins[i]);
		pinMode(pwmPins[i], INPUT);
	}
}
