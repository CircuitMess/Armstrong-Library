
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

void LEDController::turnOffLed(uint8_t i){
	output->set(i, false);
}
