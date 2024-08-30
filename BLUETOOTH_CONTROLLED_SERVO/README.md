# Bluetooth Controlled Servo Application

## Hardware Connections

### HC05 - STM32F4-DISCOVERY Board Connection

| HC05 | STM32 |
|----------|----------|
| VCC	| 3.3V |
| GND	| GND |
| TX Pin	| RX Pin (PB7) |


### Servo Motor - STM32F4-DISCOVERY Board Connection

| Servo | STM32 |
|----------|----------|
| VCC	| 5V |
| GND	| GND |
| Servo Pin	| PE6 |


## Software Modifications

As told in HC05 Bluetooth application and servo motor control application, the correct UART RX pin and servo pin on the STM32 must be selected and their corresponding GPIO clocks must be enabled. To achieve this, the following lines in main.cpp file must be modified to use this application on another board.

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