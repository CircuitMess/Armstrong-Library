#include "EncoderInput.h"
#include <Loop/LoopManager.h>

constexpr std::pair<int, int> EncoderInput::pins[4];

EncoderInput::~EncoderInput(){
	end();
}

void EncoderInput::begin(){
	LoopManager::addListener(this);

	for(auto pin: { ENC_1A, ENC_1B, ENC_2A, ENC_2B, ENC_3A, ENC_3B, ENC_4A, ENC_4B }){
		pinMode(pin, INPUT);
	}

	for(int& i: prevState){
		i = INT32_MAX;
	}
}

void EncoderInput::end(){
	LoopManager::removeListener(this);
}

void EncoderInput::loop(uint micros){
	for(uint8_t i = 0; i < 4; i++){
		scan(i);
	}
}

void EncoderInput::scan(uint8_t i){
	const auto pin = pins[i];

	int8_t movement = 0;
	const int state = digitalRead(pin.first);
	if(state != prevState[i] && prevState[i] != INT32_MAX){
		if(digitalRead(pin.second) != state){
			movement = 1;
		}else{
			movement = -1;
		}
	}

	prevState[i] = state;

	if(movement != 0){
		iterateListeners([&movement, &i](EncoderListener* encL){
			encL->encoderMove(i, movement);
		});
	}
}
