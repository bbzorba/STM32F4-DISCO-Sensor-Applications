# LCD Controller Application

## Hardware Connections

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


### 10K Ohm Potentiometer Hardware Connection

| Pot Pin Number | Pot Pin Description | STM32 GPIO Pin | LCD Pin |
|----------|----------|----------|----------|
| 1	| VDD |	5V	| - |
| 2	| Output | - | 3 (V0) |
| 3	| VSS |	GND | - |


## Software Modifications

The data pins, enable signal, register select and read/write signals are all selected to be on GPIO-A to make sure that we only enabled its RCC clock via following line:

    __HAL_RCC_GPIOA_CLK_ENABLE();

If other pins are intended to be used, their corresponding GPIO clocks must be enabled.