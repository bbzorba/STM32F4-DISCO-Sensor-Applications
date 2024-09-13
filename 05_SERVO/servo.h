#ifndef SERVO_H
#define SERVO_H

#include "pinmap.h"

enum 
{
	SERVO_LEFT = 200,
	SERVO_MIDDLE = 2500,
	SERVO_RIGHT = 20000
};

class Servo
{
	private:
		TIM_HandleTypeDef htim;
		uint8_t pwmCh;
	public:
		Servo(pinStruct_t& servoPin,
				  TIM_TypeDef* TIMx,
				  uint8_t gpioAFSelTIMx,
				  uint8_t pwmChannel);
		void TurnShaft(uint32_t position);
};

#endif //SERVO_H
