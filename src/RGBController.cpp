
#include "RGBController.h"
#include <Wire.h>


RGBController::RGBController(){

}

RGBController::~RGBController(){
	end();
}

void RGBController::begin(){
	for(int i = 0; i < 3; i++){
		ledcSetup(PWMChannels[i], 1000, 8);
		ledcWrite(PWMChannels[i], 0);
		ledcAttachPin(pins[i], PWMChannels[i]);
	}
}

void RGBController::end(){
	for(int i = 0; i < 3; i++){
		ledcDetachPin(pins[i]);
	}
}

void RGBController::set(uint8_t r, uint8_t g, uint8_t b){
	ledcWrite(PWMChannels[0], r);
	ledcWrite(PWMChannels[1], g);
	ledcWrite(PWMChannels[2], b);
}
