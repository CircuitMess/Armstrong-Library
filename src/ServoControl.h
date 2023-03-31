#ifndef ARMSTRONG_LIBRARY_SERVOCONTROL_H
#define ARMSTRONG_LIBRARY_SERVOCONTROL_H

#include <Arduino.h>
#include <Loop/LoopListener.h>
#include "Pins.hpp"
#include "Names.h"
#include <unordered_map>

class ServoControl {
public:
	ServoControl();

	void begin();
	void end();

	void setPos(Motor motor, uint8_t pos);
	uint8_t getPos(Motor motor) const;
	void centerPos();

private:
	const std::unordered_map<Motor, uint8_t, MotorHash> PWMChannels = {
			{ Motor::Rotate, 0 },
			{ Motor::Extend, 1 },
			{ Motor::Pinch,  2 },
			{ Motor::Lift,   3 }
	};

	const std::unordered_map<Motor, uint8_t, MotorHash> Pins = {
			{ Motor::Rotate, SERVO_1 },
			{ Motor::Extend, SERVO_2 },
			{ Motor::Pinch,  SERVO_3 },
			{ Motor::Lift,   SERVO_4 }
	};

	struct MotorLimit {
		uint8_t min, max;
	};

	const std::unordered_map<Motor, MotorLimit, MotorHash> Limits = {
			{ Motor::Rotate, { 30, 95 }},
			{ Motor::Extend, { 60, 100 }},
			{ Motor::Pinch, { 30, 45 }},
			{ Motor::Lift, { 40, 75 }}
	};

	const std::unordered_map<Motor, uint8_t, MotorHash> StartPos = {
			{ Motor::Rotate, 127 },
			{ Motor::Extend, 100 },
			{ Motor::Pinch,  255 },
			{ Motor::Lift,   0 }
	};

	std::unordered_map<Motor, uint8_t, MotorHash> state;

	uint8_t mapToRange(Motor motor, uint8_t value) const;

};

#endif //ARMSTRONG_LIBRARY_SERVOCONTROL_H
