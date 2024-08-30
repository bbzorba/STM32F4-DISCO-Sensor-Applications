#include "servo.h"

int main(void)
{
	HAL_Init();
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_TIM9_CLK_ENABLE();
	
	pinStruct_t servoPin = {GPIOE,GPIO_PIN_6};
	static Servo servo(servoPin,TIM9,GPIO_AF3_TIM9,TIM_CHANNEL_2);
	
	while(1)
	{
		//Turn servo shaft in the following sequence repeatedly:
		//MID-LEFT-MID-RIGHT
		servo.TurnShaft(SERVO_LEFT);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_MIDDLE);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_RIGHT);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_MIDDLE);
		HAL_Delay(1000);
	}
	
}
