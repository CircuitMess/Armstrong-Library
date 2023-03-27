#include <Loop/LoopManager.h>
#include "ServoControl.h"

constexpr uint8_t ServoControl::PWMPins[NumMotors];
constexpr uint8_t ServoControl::PWMChannels[NumMotors];
constexpr ServoRange ServoControl::Ranges[NumMotors];

ServoControl::ServoControl(){
	for(auto& i:pwmValues){
		i = 127;
	}
}
ServoControl::~ServoControl(){
	end();
}

void ServoControl::begin(){
	for(int i = 0; i < 4; i++){
		ledcSetup(PWMChannels[i], 200, 8);
		ledcAttachPin(PWMPins[i], PWMChannels[i]);
		ledcWrite(PWMChannels[i], mapToRange(i, pwmValues[i]));
	}
}

void ServoControl::setPos(uint8_t index, uint8_t pos){
	if(index >= 4) return;
	pwmValues[index] = pos;
	ledcWrite(PWMChannels[index], mapToRange(index, pos));
}

uint8_t ServoControl::getPos(uint8_t index) const{
	if(index >= 4) return 0;
	Serial.printf("pwm Value: %d\n", pwmValues[index]);
	return pwmValues[index];
}


void ServoControl::end(){
	for(unsigned char pwmPin: PWMPins){
		ledcDetachPin(pwmPin);
		pinMode(pwmPin, INPUT);
	}
}

uint8_t ServoControl::mapToRange(uint8_t enc, uint8_t value) const{
	return map(value, 0, 255, Ranges[enc].min, Ranges[enc].max);
}
