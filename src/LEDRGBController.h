#ifndef ARMSTRONG_LIBRARY_LEDRGBCONTROLLER_H
#define ARMSTRONG_LIBRARY_LEDRGBCONTROLLER_H

#include "Pins.hpp"
#include <cstdint>
#include <Display/Color.h>

class LEDRGBController {
public:
	LEDRGBController();
	void set(uint8_t r, uint8_t g, uint8_t b);
	void set(Pixel pixel);

private:
	static constexpr uint8_t pins[3] = { LED_R, LED_G, LED_B };
	static constexpr uint8_t PWMChannels[3] = { 4, 5, 6 };

};


#endif //ARMSTRONG_LIBRARY_LEDRGBCONTROLLER_H
