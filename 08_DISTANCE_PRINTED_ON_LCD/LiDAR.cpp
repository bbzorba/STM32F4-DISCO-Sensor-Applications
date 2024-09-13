#include "lidar.h"

LiDAR::LiDAR(pinStruct_t& txPin, pinStruct_t& rxPin, USART_TypeDef* USARTx, uint32_t baudRate, uint32_t gpioAFSelUSARTx)
{
    // GPIO configuration for UART2 (Tx, Rx)
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Initialize Tx pin
    GPIO_InitStruct.Pin = txPin.selectedPin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = gpioAFSelUSARTx;
    HAL_GPIO_Init(txPin.port, &GPIO_InitStruct);

    // Initialize Rx pin
    GPIO_InitStruct.Pin = rxPin.selectedPin;
    HAL_GPIO_Init(rxPin.port, &GPIO_InitStruct);

    // USART configuration
    huart.Instance = USARTx;
    huart.Init.BaudRate = baudRate;
    huart.Init.WordLength = UART_WORDLENGTH_8B;
    huart.Init.StopBits = UART_STOPBITS_1;
    huart.Init.Parity = UART_PARITY_NONE;
    huart.Init.Mode = UART_MODE_TX_RX;
    huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart.Init.OverSampling = UART_OVERSAMPLING_16;
    HAL_UART_Init(&huart);
}

uint32_t LiDAR::GetDistance()
{
    uint8_t bytes_serial[9] = {0};
    uint32_t distance = 0;

    // Read data from LiDAR
    HAL_UART_Receive(&huart, bytes_serial, sizeof(bytes_serial), HAL_MAX_DELAY);

    // Assuming data format of the LiDAR is correct, extract distance (bytes 2 and 3)
    distance = bytes_serial[3];

    return distance;
}
