
#ifndef ARMSTRONG_LIBRARY_RGBCONTROLLER_H
#define ARMSTRONG_LIBRARY_RGBCONTROLLER_H


#include "Pins.hpp"
#include <cstdint>


class RGBController  {
public:
	RGBController();
	~RGBController();
	void begin();
	void end();
	void set(uint8_t r, uint8_t g, uint8_t b);

private:
	const uint8_t pins[3] = { LED_R, LED_G, LED_B };
	static constexpr uint8_t PWMChannels[3] = {4, 5, 6};
};


#endif //ARMSTRONG_LIBRARY_RGBCONTROLLER_H
