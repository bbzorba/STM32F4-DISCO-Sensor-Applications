# Servo Motor Control Application


### Servo Motor - STM32F4-DISCOVERY Board Connection

| Servo | STM32 |
|----------|----------|
| VCC	| 5V |
| GND	| GND |
| Servo Pin	| PE6 |


## Software Modifications

PWM is applied using the Channel 2 of Timer 9. While implementing this application on a board other than STM32, do not forget to modify the pin number (e.g. GPIO_PIN_6), port number (GPIOE), the clock and timer that is used by the pin you selected in main.cpp file. You also might need to assign different values to PWM signals since the frequency of the timer you use might be different. In that case, modify the SERVO_LEFT, SERVO_MIDDLE and SERVO_RIGHT values under servo.h file.


## Understanding the PWM Values

PWM (Pulse Width Modulation) signal is used to control the position of the servo motor. The pulse width (duration) determines the position of the servo.

- Pulse Width (ms): This is the duration for which the PWM signal stays high in one cycle.

- Period (ms): This is the duration of one complete cycle of the PWM signal (high and low).


In most servo applications, the PWM period is around 20ms (50Hz frequency), and the pulse width varies between 1ms (0 degrees) to 2ms (180 degrees) to control the position of the servo shaft.


## Configuring PWM Values for TIM9 on STM32F4-DISCOVERY

The standard PWM frequency for servo control is 50 Hz, equating to a 20 ms period.

### System and Timer Configuration

- System Clock (SYSCLK): 168 MHz (using PLL)
- Prescaler: 83
- Timer Clock: 168 MHz / (83 + 1) = 2 MHz

### PWM Period Calculation

To achieve a 20 ms period with a timer clock of 2 MHz:

- PWM Period (ARR) = Timer Clock / PWM Frequency = 2,000,000 Hz / 50 Hz = 40,000

Thus, the period value should be set to 40,000 - 1 to get a 20 ms period.

### PWM Pulse Widths

The pulse widths in microseconds (µs) for the PWM signal must be converted to timer counts:

- SERVO_LEFT: 200 (corresponding to a pulse width of 1 ms)
- SERVO_MIDDLE: 2500 (corresponding to a pulse width of 1.5 ms)
- SERVO_RIGHT: 20,000 (corresponding to a pulse width of 2 ms)