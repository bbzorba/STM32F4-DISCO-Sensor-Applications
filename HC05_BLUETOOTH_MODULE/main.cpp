#include "hc05.h"

char bluetoothData = '\0';

int main(void)
{
	HAL_Init();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_USART1_CLK_ENABLE();
	
	pinStruct_t uartRxPin = {GPIOB,GPIO_PIN_7};
	static HC05 hc05(uartRxPin,USART1,9600,GPIO_AF7_USART1,UART_MODE_RX);
	
	while(1)
	{
		bluetoothData = hc05.GetChar();
	}
	
}
