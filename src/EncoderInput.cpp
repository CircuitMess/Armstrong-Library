
#include "EncoderInput.h"
#include <Loop/LoopManager.h>
#include <cstdlib>

EncoderInput::EncoderInput(){

}

EncoderInput::~EncoderInput(){
	end();
}

void EncoderInput::begin(){
	LoopManager::addListener(this);

	for(auto pin : { ENC_1A, ENC_1B, ENC_2A, ENC_2B, ENC_3A, ENC_3B, ENC_4A, ENC_4B }){
		pinMode(pin, INPUT);
	}

	for(int i = 0; i < 4; i++){
		prevState[i] = INT32_MAX;
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
	auto pin = pins[i];

	int movement = 0;
	int state = digitalRead(pin.first);
	if(state != prevState[i] && prevState[i] != INT32_MAX){
		if(digitalRead(pin.second) != state){
			movement = 1;
		}else{
			movement = -1;
		}
	}

	prevState[i] = state;

	if(movement != 0){
		switch(i){
			case 0:
				iterateListeners([movement](EncoderListener * encL){
					encL->EncMoveA(movement);
				});
				break;
			case 1:
				iterateListeners([movement](EncoderListener * encL){
					encL->EncMoveB(movement);
				});
				break;
			case 2:
				iterateListeners([movement](EncoderListener * encL){
					encL->EncMoveC(movement);
				});
				break;
			case 3:
				iterateListeners([movement](EncoderListener * encL){
					encL->EncMoveD(movement);
				});
				break;
		}
	}
}
