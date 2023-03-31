#include "EncoderInput.h"
#include <Loop/LoopManager.h>

EncoderInput::EncoderInput(){
	for(const auto& pair : PinMap){
		prevState.insert({ pair.first, INT32_MAX });
	}
}

void EncoderInput::begin(){
	LoopManager::addListener(this);

	for(const auto& pair : PinMap){
		const auto motor = pair.first;
		const auto pins = pair.second;

		pinMode(pins.first, INPUT);
		pinMode(pins.second, INPUT);

		prevState[motor] = INT32_MAX;
	}
}

void EncoderInput::end(){
	LoopManager::removeListener(this);
}

void EncoderInput::loop(uint micros){
	for(uint8_t i = 0; i < 4; i++){
		scan((Motor) i);
	}
}

void EncoderInput::scan(Motor enc){
	const auto pins = PinMap.find(enc)->second;

	int8_t movement = 0;

	const int state = digitalRead(pins.first);
	if(state != prevState[enc] && prevState[enc] != INT32_MAX){
		if(digitalRead(pins.second) != state){
			movement = 1;
		}else{
			movement = -1;
		}
	}

	prevState[enc] = state;

	if(movement != 0){
		iterateListeners([movement, enc](EncoderListener* encL){
			encL->encoderMove(enc, movement);
		});
	}
}
