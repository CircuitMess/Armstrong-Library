#include "LEDRGBController.h"
#include <Wire.h>

constexpr uint8_t LEDRGBController::pins[3];
constexpr uint8_t LEDRGBController::PWMChannels[3];

LEDRGBController::LEDRGBController(){
	for(int i = 0; i < 3; i++){
		ledcSetup(PWMChannels[i], 1000, 8);
		ledcWrite(PWMChannels[i], 0);
		ledcAttachPin(pins[i], PWMChannels[i]);
	}
}

void LEDRGBController::set(uint8_t r, uint8_t g, uint8_t b){
	ledcWrite(PWMChannels[0], 255.0f - pow(r / 255.0f, 2.0f) * 255.0);
	ledcWrite(PWMChannels[1], 255.0f - pow(g / 255.0f, 2.0f) * 255.0);
	ledcWrite(PWMChannels[2], 255.0f - pow(b / 255.0f, 2.0f) * 255.0);
}

void LEDRGBController::set(Pixel pixel){
	set(pixel.r, pixel.g, pixel.b);
}
