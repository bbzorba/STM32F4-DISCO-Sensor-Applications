#include "stm32f4xx_hal.h"
#include "lcd.h"
#include "LiDAR.h"

int main(void)
{
    HAL_Init();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_USART2_CLK_ENABLE();

    // Define pins for LCD
    pinStruct_t rsPin = {GPIOA, GPIO_PIN_0};
    pinStruct_t enPin = {GPIOA, GPIO_PIN_1};
    pinStruct_t d4Pin = {GPIOA, GPIO_PIN_4};
    pinStruct_t d5Pin = {GPIOA, GPIO_PIN_5};
    pinStruct_t d6Pin = {GPIOA, GPIO_PIN_6};
    pinStruct_t d7Pin = {GPIOA, GPIO_PIN_7};

    // Initialize LCD
    static LCD lcd(rsPin, enPin, d4Pin, d5Pin, d6Pin, d7Pin);
    lcd.Clear();

    // Define pins for LiDAR
    pinStruct_t uartTxPin = {GPIOD, GPIO_PIN_5};  // Tx pin PD5
    pinStruct_t uartRxPin = {GPIOD, GPIO_PIN_6};  // Rx pin PD6

    // Initialize LiDAR
    LiDAR lidar(uartTxPin, uartRxPin, USART2, 115200, GPIO_AF7_USART2);

    while (1)
    {
        // Get distance from LiDAR
        uint32_t distance = lidar.GetDistance();

        // Display distance on the LCD
        lcd.Clear();
        lcd.SetCursor(0, 0);
        lcd.Print("Distance: ");
        lcd.Print(distance);
        lcd.SetCursor(1, 0);
        lcd.Print(" cm");

        HAL_Delay(1000);  // Refresh every 1 second
    }
}
