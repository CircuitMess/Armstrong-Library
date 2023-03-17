
#include "LEDController.h"
#include "Pins.hpp"

LEDController::LEDController(){
	output = new ShiftOutput(OUT_CLOCK_PIN, OUT_DATA_PIN);
	output->begin();
}

LEDController::~LEDController(){
	delete output;
}

void LEDController::turnOnLed(uint8_t i){
	output->set(i, true);
}

void LEDController::set(uint8_t index, bool value){
	output->set(leds[index], value);
	ledsValue[index] = value;
}

bool LEDController::get(uint8_t index, bool value){
	return (ledsValue[index] == value);
}
