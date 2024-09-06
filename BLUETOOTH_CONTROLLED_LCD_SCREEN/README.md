# Bluetooth Controlled LCD Application

## Hardware Connections

### HC05 - STM32F4-DISCOVERY Board Connection

| HC05 | STM32 |
|----------|----------|
| VCC	| 3.3V |
| GND	| GND |
| TX Pin	| RX Pin (PB7) |


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

As told in HC05 Bluetooth application and lcd screen application, the correct UART RX pin and LCD data pins must be selected and the corresponding GPIO clock for the HC05 module must be enabled.