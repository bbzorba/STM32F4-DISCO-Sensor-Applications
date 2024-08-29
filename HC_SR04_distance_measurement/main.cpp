#include "hcsr04.h"

uint32_t distance = 0;

int main(void)
{
    HAL_Init();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_TIM2_CLK_ENABLE();  // Use TIM2 instead of TIM5

    // Sensor pins
    pinStruct_t trigPin = {GPIOA, GPIO_PIN_0};
    pinStruct_t echoPin = {GPIOA, GPIO_PIN_1};

    HCSR04_TrigPinPWMInit(trigPin, TIM2, GPIO_AF1_TIM2, TIM_CHANNEL_2);  // Use TIM2 and correct AF
    static HCSR04 hcsr04(echoPin, TIM2, GPIO_AF1_TIM2);

    while (1)
    {
        distance = hcsr04.GetDistance();
    }
}
