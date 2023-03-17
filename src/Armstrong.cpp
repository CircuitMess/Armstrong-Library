#include "Armstrong.h"

ArmstrongImpl Armstrong;

ArmstrongImpl::ArmstrongImpl(){

}

void ArmstrongImpl::begin(){

	input = new InputShift(14, 27, 26, 8);
	input->begin();
	LoopManager::addListener(input);
}

void ArmstrongImpl::shutdown(){

}

InputShift* ArmstrongImpl::getInput(){
	return input;
}
