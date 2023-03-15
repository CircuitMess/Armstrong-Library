
#ifndef ARMSTRONG_LIBRARY_LEDCONTROLLER_H
#define ARMSTRONG_LIBRARY_LEDCONTROLLER_H


#include <cstdint>
#include <Devices/ShiftOutput.h>

class LEDController {
public:
	LEDController();
	~LEDController();
	void turnOnLed(uint8_t i);
	void turnOffLed(uint8_t i);

private:
	ShiftOutput* output;
};


#endif //ARMSTRONG_LIBRARY_LEDCONTROLLER_H
