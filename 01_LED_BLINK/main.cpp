#include "stm32f4xx_hal.h"

void ToggleLED(void) {
    static GPIO_PinState state = GPIO_PIN_RESET;
    state = (state == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET;
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, state); //initialize PD12, PD13, PD14 and PD15 as write pins
}

int main(void)
{
    HAL_Init();
    __HAL_RCC_GPIOD_CLK_ENABLE(); // Ensure GPIOB clock is enabled

    // Initialize GPIO for LEDs
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);


    while(1)
    {
        ToggleLED(); // Toggle LEDs
        HAL_Delay(500); // Delay
    }
}
