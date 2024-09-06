#include "lcd.h"
#include "hc05.h"
#include <string.h>  // Include for memset

#define BUFFER_SIZE 32  // Adjust size as needed
char bluetoothData[BUFFER_SIZE];

int main(void)
{
    HAL_Init();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_USART1_CLK_ENABLE();

    // Initialize the LCD Pins
    pinStruct_t rs = {GPIOA, GPIO_PIN_0};
    pinStruct_t en = {GPIOA, GPIO_PIN_1};
    pinStruct_t d4 = {GPIOA, GPIO_PIN_4};
    pinStruct_t d5 = {GPIOA, GPIO_PIN_5};
    pinStruct_t d6 = {GPIOA, GPIO_PIN_6};
    pinStruct_t d7 = {GPIOA, GPIO_PIN_7};

    // Initialize the UART RX Pin
    pinStruct_t uartRxPin = {GPIOB, GPIO_PIN_7};

    static LCD lcd(rs, en, d4, d5, d6, d7);
    static HC05 hc05(uartRxPin, USART1, 9600, GPIO_AF7_USART1, UART_MODE_RX);

    // Display waiting message once
    lcd.Print("Waiting for data:");

    while (1)
    {
        uint8_t index = 0;
        char receivedChar = '\0';

        // Initialize buffer
        memset(bluetoothData, 0, BUFFER_SIZE);

        // Loop to read the entire string
        while (1)
        {
            // Read a character from Bluetooth
            receivedChar = hc05.GetChar();

            if (receivedChar != '\0')  // If a character is received
            {
                // Check for termination characters
                if (receivedChar == '\n' || receivedChar == '\r')
                {
                    break;  // End of string
                }
                else if (index < BUFFER_SIZE - 1)  // Ensure buffer doesn't overflow
                {
                    bluetoothData[index++] = receivedChar;
                }
            }

            // Small delay to ensure all characters arrive
            HAL_Delay(20);  // Adjust this delay if needed
        }

        // Null-terminate the string
        bluetoothData[index] = '\0';

        // Clear the second line before displaying new data
        lcd.SetCursor(1, 0);
        lcd.Print("                ");  // 16 spaces to clear the line

        // Display the received string on the second row of the LCD
        lcd.SetCursor(1, 0);
        lcd.Print(bluetoothData);

        // Optional: Wait before clearing or resetting for the next string
        // HAL_Delay(5000);  // Wait for 5 seconds before clearing the display
    }
}
