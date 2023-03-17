
#ifndef ARMSTRONG_LIBRARY_LEDCONTROLLER_H
#define ARMSTRONG_LIBRARY_LEDCONTROLLER_H


#include <cstdint>
#include <Devices/ShiftOutput.h>
#include "Pins.hpp"
#include <memory>

class LEDController {
public:
	LEDController();
	~LEDController();
	void set(uint8_t index, bool value);
	bool get(uint8_t index, bool value);

private:
	std::unique_ptr<ShiftOutput> output;
	uint8_t leds[5] = {LED_PP, LED_1, LED_2, LED_3, LED_4};
	bool ledsValue[5] = {false};
};


#endif //ARMSTRONG_LIBRARY_LEDCONTROLLER_H
