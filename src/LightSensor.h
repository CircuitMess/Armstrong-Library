
#ifndef ARMSTRONG_LIBRARY_LIGHTSENSOR_H
#define ARMSTRONG_LIBRARY_LIGHTSENSOR_H


#include <veml6040.h>
#include <Loop/LoopListener.h>
#include <Display/Color.h>

class LightSensor : private LoopListener{
public:
	LightSensor();

	void begin();
	void end();

	Pixel getPixel();

private:
	void loop(uint micros) override;
	VEML6040 Sensor;
	Pixel pixel = {0};

	uint32_t counter = 0;
	static constexpr uint32_t Delay = 500000;
};


#endif //ARMSTRONG_LIBRARY_LIGHTSENSOR_H
