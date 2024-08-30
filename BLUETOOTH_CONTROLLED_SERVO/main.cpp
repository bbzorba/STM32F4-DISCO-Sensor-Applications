#include "hc05.h"
#include "servo.h"

char bluetoothData = '\0';

int main(void)
{
	HAL_Init();

	//initialize the clocks for the GPIO and UART communication of bluetooth module
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_USART1_CLK_ENABLE();

	//initialize the clocks for the GPIO and TIMER of servo motor
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_TIM9_CLK_ENABLE();
	
	//initialize the pin structures
	pinStruct_t servoPin = {GPIOE,GPIO_PIN_6};
	pinStruct_t uartRxPin = {GPIOB,GPIO_PIN_7};

	//initialize the servo and hc05 objects
	static Servo servo(servoPin,TIM9,GPIO_AF3_TIM9,TIM_CHANNEL_2);
	static HC05 hc05(uartRxPin,USART1,9600,GPIO_AF7_USART1,UART_MODE_RX);
	
	while(1)
	{ 
		bluetoothData = hc05.GetChar();
		switch(bluetoothData)
		{
			case 'l':
			case 'L':
				servo.TurnShaft(SERVO_LEFT);
				break;
			case 'm':
			case 'M':
				servo.TurnShaft(SERVO_MIDDLE);
				break;
			case 'r':
			case 'R':
				servo.TurnShaft(SERVO_RIGHT);
				break;
		}
	}
	
}
