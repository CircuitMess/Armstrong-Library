#ifndef ARMSTRONG_LIBRARY_SERVOCONTROL_H
#define ARMSTRONG_LIBRARY_SERVOCONTROL_H


#include <cstdint>
#include <Loop/LoopListener.h>
#include <cstdlib>
#include "Pins.hpp"

class ServoControl {
public:
	ServoControl();
	~ServoControl();
	void setPos(uint8_t i, uint8_t pos);
	uint8_t getPos(uint8_t i);
	void begin();
	void end();

private:
	static const uint8_t NumMotors = 4;
	struct ServoRange{
		uint8_t min;
		uint8_t max;
	};
	const ServoRange Ranges[NumMotors] = {{ 25, 100 },
										  { 45, 110 },
										  { 35, 56 },
										  { 25, 60 }, };
	uint8_t pwmValues[4];
	const uint8_t pwmPins[4] = { SERVO_1, SERVO_2, SERVO_3, SERVO_4 };
};

#endif //ARMSTRONG_LIBRARY_SERVOCONTROL_H
