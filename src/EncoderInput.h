#ifndef ARMSTRONG_LIBRARY_ENCODERINPUT_H
#define ARMSTRONG_LIBRARY_ENCODERINPUT_H

#include <Loop/LoopListener.h>
#include <Util/WithListeners.h>
#include <unordered_map>
#include "Pins.hpp"
#include "Names.h"

class EncoderInput;

class EncoderListener {
friend EncoderInput;
private:
	virtual void encoderMove(Motor enc, int8_t amount) = 0;
};

class EncoderInput : public LoopListener, public WithListeners<EncoderListener> {
public:
	EncoderInput();
	void begin();
	void end();

private:
	void loop(uint micros) override;
	void scan(Motor enc);

	const std::unordered_map<Motor, std::pair<int, int>, MotorHash> PinMap = {
			{ Motor::Rotate, { ENC_1A, ENC_1B } },
			{ Motor::Extend, { ENC_2A, ENC_2B } },
			{ Motor::Pinch, { ENC_3A, ENC_3B } },
			{ Motor::Lift, { ENC_4A, ENC_4B } }
	};

	std::unordered_map<Motor, int32_t, MotorHash> prevState;

};


#endif //ARMSTRONG_LIBRARY_ENCODERINPUT_H
