#include "stm32f4xx_hal.h"
#include "LiDAR.h"
#include <stdio.h>

int main(void)
{
    HAL_Init();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_USART2_CLK_ENABLE();

    // Define pins for LiDAR
    pinStruct_t uartTxPin = {GPIOD, GPIO_PIN_5};  // Tx pin PD5
    pinStruct_t uartRxPin = {GPIOD, GPIO_PIN_6};  // Rx pin PD6

    // Initialize LiDAR
    LiDAR lidar(uartTxPin, uartRxPin, USART2, 115200, GPIO_AF7_USART2);

    while (1)
    {
        // Get distance from LiDAR
        uint32_t distance = lidar.GetDistance();

        printf("distance: %d" ,distance);

        HAL_Delay(1000);  // Refresh every 1 second
    }
}
