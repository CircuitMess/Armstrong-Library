

#ifndef ARMSTRONG_LIBRARY_ENCODERINPUT_H
#define ARMSTRONG_LIBRARY_ENCODERINPUT_H


#include <Loop/LoopListener.h>
#include <cstdlib>
#include "WithListeners.h"
#include "Pins.hpp"

class EncoderInput;

class EncoderListener{
	friend EncoderInput;

private:
	virtual void EncMoveA(int8_t amount);
	virtual void EncMoveB(int8_t amount);
	virtual void EncMoveC(int8_t amount);
	virtual void EncMoveD(int8_t amount);
};


class EncoderInput : public LoopListener, public WithListeners<EncoderListener> {
public:
	EncoderInput();
	~EncoderInput();
	void begin();
	void end();

private:
	void loop(uint micros) override;
	void scan(uint8_t i);

	int32_t prevState[4];

	const std::pair<int, int> pins[4] = {
			{ ENC_1A, ENC_1B },
			{ ENC_2A, ENC_2B },
			{ ENC_3A, ENC_3B },
			{ ENC_4A, ENC_4B }
	};
};


#endif //ARMSTRONG_LIBRARY_ENCODERINPUT_H
