#include <Loop/LoopManager.h>
#include "ServoControl.h"

ServoControl::ServoControl(){

}

ServoControl::~ServoControl(){
	end();
}

void ServoControl::setPos(uint8_t index, uint8_t pos){
	if(index >= 4) return;
	pwmValues[index] = constrain(pos, Ranges[index].min, Ranges[index].max);
	ledcWrite(PWMChannels[index], pwmValues[index]);
}

uint8_t ServoControl::getPos(uint8_t index){
	if(index >= 4) return 0;
	return ledcRead(PWMChannels[index]);
}

void ServoControl::begin(){
	for(int i = 0; i < 4; i++){
		pwmValues[i] = (Ranges[i].min + Ranges[i].max) / 2;

		ledcSetup(PWMChannels[i], 200, 8);
		ledcAttachPin(pwmPins[i], PWMChannels[i]);
		ledcWrite(PWMChannels[i], pwmValues[i]);
	}
}

void ServoControl::end(){
	for(int i = 0; i < 4; i++){
		ledcDetachPin(pwmPins[i]);
		pinMode(pwmPins[i], INPUT);
	}
}
