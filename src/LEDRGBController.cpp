
#include "LEDRGBController.h"
#include <Wire.h>


LEDRGBController::LEDRGBController(){
	for(int i = 0; i < 3; i++){
		ledcSetup(4+i, 1000, 8);
		ledcWrite(4+i, 0);
		ledcAttachPin(pins[i], 4+i);
	}
}

void LEDRGBController::set(uint8_t r, uint8_t g, uint8_t b){
	ledcWrite(4, r);
	ledcWrite(5, g);
	ledcWrite(6, b);
}
