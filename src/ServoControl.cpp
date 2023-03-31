#include <Loop/LoopManager.h>
#include "ServoControl.h"

ServoControl::ServoControl(){
	for(const auto& pair : Pins){
		state.insert({ pair.first, StartPos.find(pair.first)->second });
	}
}

void ServoControl::begin(){
	for(const auto& pair : Pins){
		const auto motor = pair.first;
		const auto pin = pair.second;
		const auto chan = PWMChannels.find(motor)->second;

		state[motor] = StartPos.find(motor)->second;

		ledcSetup(chan, 200, 8);
		ledcWrite(chan, mapToRange(motor, state[motor]));
		ledcAttachPin(pin, chan);
	}
}

void ServoControl::end(){
	for(const auto& pair : Pins){
		const auto motor = pair.first;
		const auto pin = pair.second;
		const auto chan = PWMChannels.find(motor)->second;

		ledcDetachPin(chan);
		pinMode(pin, INPUT);
	}
}

void ServoControl::setPos(Motor motor, uint8_t pos){
	auto pair = state.find(motor);
	if(pair == state.end()) return;

	state[motor] = pos;
	auto val = mapToRange(motor, pos);

	auto chan = PWMChannels.find(motor)->second;
	ledcWrite(chan, val);
}

uint8_t ServoControl::getPos(Motor motor) const{
	auto pair = state.find(motor);
	if(pair == state.end()) return 0;
	return pair->second;
}

void ServoControl::centerPos(){
	for(const auto& pair : state){
		const auto motor = pair.first;
		const auto pos = StartPos.find(motor)->second;

		setPos(motor, pos);
	}
}

uint8_t ServoControl::mapToRange(Motor motor, uint8_t value) const{
	const auto pair = Limits.find(motor);
	if(pair == Limits.end()) return UINT8_MAX / 2;

	const auto lim = pair->second;
	return map(value, 0, 255, lim.min, lim.max);
}
