# LiDAR Distance Application Printed on LCD Screen

## Hardware Connections

### Benewake TF02 Pro LiDAR - STM32F4-DISCOVERY Board Connection

| LiDAR | STM32 |
|----------|----------|
| VCC	| 5V |
| GND	| GND |
| TX Pin	| USART2 RX Pin (PD6) |
| RX Pin	| USART2 TX Pin (PD5) |


### 2x16 LCD Screen - STM32F4-DISCOVERY Board Connection

| LCD Pin | LCD Name | STM32 GPIO Pin | STM32 Pin Description |
|----------|----------|----------|----------|
| 1	| VSS |	GND	| Ground |
| 2	| VDD |	5V | Power Supply |
| 3	| V0 |	Potentiometer |	Contrast Adjustment |
| 4	| RS |	GPIOA_PIN_0	| Register Select |
| 5	| RW |	GND	| Ground (for Write) |
| 6	| E |	GPIOA_PIN_1 |	Enable Signal |
| 7	| D0 |	Not Connected	|	(Not used in 4-bit mode) |
| 8	| D1 |	Not Connected	|	(Not used in 4-bit mode) |
| 9	| D2 |	Not Connected	|	(Not used in 4-bit mode) |
| 10 | D3 | Not Connected	|	(Not used in 4-bit mode) |
| 11 | D4 |	GPIOA_PIN_4	|	Data Bit 4 |
| 12 | D5 |	GPIOA_PIN_5	|	Data Bit 5 |
| 13 | D6 |	GPIOE_PIN_6	|	Data Bit 6 |
| 14 | D7 |	GPIOE_PIN_7	|	Data Bit 7 |
| 15 | A |	5V (via 220 ohm resistor) |	LED Anode (Backlight +) |
| 16 | K |	GND |	LED Cathode (Backlight -) |

## Software Modifications

The TX and RX Pins of LiDAR should be connected to the USART2 RX (PD6) and TX (PD7) pins respectively. If it is intended to use another board or another UART/USART port on STM32F4-DISCOVERY board, following parts of the software should be modified accordingly.

    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_USART2_CLK_ENABLE();

    pinStruct_t uartTxPin = {GPIOD, GPIO_PIN_5};  // Tx pin PD5
    pinStruct_t uartRxPin = {GPIOD, GPIO_PIN_6};  // Rx pin PD6

    LiDAR lidar(uartTxPin, uartRxPin, USART2, 115200, GPIO_AF7_USART2);