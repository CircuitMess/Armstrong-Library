#include <Arduino.h>
#include <CircuitOS.h>
#include "src/Armstrong.h"
#include <Loop/LoopManager.h>
#include <Wire.h>
#include <driver/i2c.h>

InputShift* input;

class InputTest : private InputListener {
public:
	InputTest(){
		input->addListener(this);
	}

private:
	void buttonPressed(uint i) override{
		LED.set(i, true);
		printf("%d press\n", i);
	}

	void buttonReleased(uint i) override{
		LED.set(i, false);
		printf("%d release\n", i);
	}

};

class EncoderTest : public EncoderListener {
	void encoderMove(uint8_t enc, int8_t amount) override{
		int val = Servo.getPos(enc) + amount;
		Servo.setPos(enc, constrain(val, 0, 255));
	}
};

EncoderTest* enc;

[[noreturn]] void i2cLoop(){
	for(;;){
		uint8_t data[2];
		int count = i2c_slave_read_buffer(I2C_NUM_0, data, 2, portMAX_DELAY);
		if(count < 0){
			printf("Read err %d\n", count);
			continue;
		}

		printf("Set servo %d to %d\n", data[0] + 1, data[1]);
		Servo.setPos(data[0], data[1]);
	}
}

bool inited = false;

void setup(){
	Serial.begin(115200);

	Armstrong.begin();

	input = Armstrong.getInput();


	new InputTest;
	enc = new EncoderTest;
	Encoder.addListener(enc);

	TaskHandle_t task;
	xTaskCreatePinnedToCore([](void* arg){
		for(;;){
			LoopManager::loop();
			delay(1);
		}
	}, "Loop", 12000, nullptr, 1, &task, 0);

//	i2c_config_t cfg = {
//			.mode = I2C_MODE_SLAVE,
//			.sda_io_num = (gpio_num_t) 14,
//			.sda_pullup_en = GPIO_PULLUP_ENABLE,
//			.scl_io_num = (gpio_num_t) 27,          // select GPIO specific to your project
//			.scl_pullup_en = GPIO_PULLUP_ENABLE
//	};
//
//	cfg.slave = {
//			.addr_10bit_en = false,
//			.slave_addr = 0x23
//	};
//
//	ESP_ERROR_CHECK(i2c_param_config(I2C_NUM_0, &cfg));
//	ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM_0, I2C_MODE_SLAVE, 256, 256, 0));
//
//	printf("Ready\n");
//
//	i2cLoop();

}

void loop(){
	auto c = Sensor.getPixel();
	RGB.set(c);
}
