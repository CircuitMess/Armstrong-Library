
#ifndef ARMSTRONG_LIBRARY_ARMSTRONG_H
#define ARMSTRONG_LIBRARY_ARMSTRONG_H


#include <Input/InputShift.h>
class ArmstrongImpl {
public:
	ArmstrongImpl();
	void begin();

	InputShift* getInput();

private:
	InputShift* input;

};

extern ArmstrongImpl Armstrong;


#endif //ARMSTRONG_LIBRARY_ARMSTRONG_H
