
#include "LEDController.h"


LEDController::LEDController(){

}

LEDController::~LEDController(){
	end();
}

void LEDController::begin(){
	output = std::make_unique<ShiftOutput>(OUT_CLOCK, OUT_DATA);
	output->begin();
}

void LEDController::end(){
	output->setAll(false);
}

void LEDController::set(uint8_t index, bool value){
	output->set(leds[index], value);
	ledsValue[index] = value;
}

bool LEDController::get(uint8_t index){
	return ledsValue[index];
}
