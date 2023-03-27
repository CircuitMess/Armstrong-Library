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

	void begin();
	void end();

	void set(uint8_t index, bool value);
	[[nodiscard]] bool get(uint8_t index) const;

	void clearAll();

private:
	ShiftOutput output;
	static constexpr uint8_t NumLEDs = 5;
	bool ledsValue[NumLEDs] = { false };
	uint8_t map(uint8_t led) const;
	static constexpr uint8_t Pins[NumLEDs] = { LED_PP, LED_1, LED_2, LED_3, LED_4 };
};


#endif //ARMSTRONG_LIBRARY_LEDCONTROLLER_H
