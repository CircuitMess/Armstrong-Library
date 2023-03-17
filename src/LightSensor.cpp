
#include <Wire.h>
#include <Loop/LoopManager.h>
#include "LightSensor.h"
#include "Pins.hpp"

LightSensor::LightSensor(){

}

void LightSensor::begin(){
	if(!Wire.begin(SDA_PIN, SCL_PIN) || !Sensor.begin()) return;
	Sensor.setConfiguration(VEML6040_IT_320MS | VEML6040_AF_AUTO | VEML6040_SD_ENABLE);
	LoopManager::addListener(this);
}

void LightSensor::end(){
	LoopManager::removeListener(this);
}

Pixel LightSensor::getPixel(){
	return pixel;
}


void LightSensor::loop(uint micros){
	counter += micros;
	if(counter >= Delay){
		counter = 0;

		float r = (float) Sensor.getRed() / (float) UINT16_MAX;
		float g = (float) Sensor.getGreen() / (float) UINT16_MAX;
		float b = (float) Sensor.getBlue() / (float) UINT16_MAX;

		b = std::min(1.0f, b*2.0f);

		r = constrain(pow(r, 6.0f) * 50.0f, 0.0f, 1.0f);
		g = constrain(pow(g, 6.0f) * 50.0f, 0.0f, 1.0f);
		b = constrain(pow(b, 6.0f) * 50.0f, 0.0f, 1.0f);

		uint8_t uintR = 255.0f - pow(r, 2.0f)*255.0f;
		uint8_t uintG = 255.0f - pow(g, 2.0f)*255.0f;
		uint8_t uintB = 255.0f - pow(b, 2.0f)*255.0f;

		pixel.r = uintR;
		pixel.g = uintG;
		pixel.b = uintB;
	}
}
