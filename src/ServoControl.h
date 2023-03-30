#ifndef ARMSTRONG_LIBRARY_SERVOCONTROL_H
#define ARMSTRONG_LIBRARY_SERVOCONTROL_H

#include <cstdint>
#include <Loop/LoopListener.h>
#include <cstdlib>
#include "Pins.hpp"

struct ServoRange {
	uint8_t min;
	uint8_t max;
};

class ServoControl {
public:
	ServoControl();
	~ServoControl();

	void begin();
	void end();

	void setPos(uint8_t index, uint8_t pos);
	[[nodiscard]] uint8_t getPos(uint8_t index) const;

private:
	static constexpr uint8_t NumMotors = 4;
	uint8_t pwmValues[NumMotors] = { 127 };

	uint8_t mapToRange(uint8_t enc, uint8_t value) const;

	static constexpr uint8_t PWMPins[NumMotors] = { SERVO_1, SERVO_2, SERVO_3, SERVO_4 };
	static constexpr uint8_t PWMChannels[NumMotors] = { 0, 1, 2, 3 };
	static constexpr ServoRange Ranges[NumMotors] = {{ 25, 100 },
													 { 45, 110 },
													 { 37, 56 },
													 { 25, 60 }};

};

#endif //ARMSTRONG_LIBRARY_SERVOCONTROL_H
