#include "LEDController.h"

constexpr uint8_t LEDController::Pins[NumLEDs];

LEDController::LEDController() : output(SHIFTOUT_CLOCK, SHIFTOUT_DATA){

}

LEDController::~LEDController(){
	end();
}

void LEDController::begin(){
	output.begin();
	for(int i = 0; i < NumLEDs; i++){
		output.set(Pins[i], ledsValue[i]);
	}
}

void LEDController::end(){
	output.setAll(false);
}

void LEDController::set(uint8_t index, bool value){
	if(index >= NumLEDs) return;
	output.set(Pins[index], value);
	ledsValue[index] = value;
}

bool LEDController::get(uint8_t index) const{
	if(index >= NumLEDs) return false;
	return ledsValue[index];
}

void LEDController::clearAll(){
	for(int i = 0; i < NumLEDs; i++){
		set(i, false);
	}
}
