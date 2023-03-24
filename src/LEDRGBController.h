
#ifndef ARMSTRONG_LIBRARY_LEDRGBCONTROLLER_H
#define ARMSTRONG_LIBRARY_LEDRGBCONTROLLER_H


#include "Pins.hpp"
#include <cstdint>


class LEDRGBController  {
public:
	LEDRGBController();
	void set(uint8_t r, uint8_t g, uint8_t b);

private:
	const uint8_t pins[3] = { LED_R, LED_G, LED_B };
};


#endif //ARMSTRONG_LIBRARY_LEDRGBCONTROLLER_H
