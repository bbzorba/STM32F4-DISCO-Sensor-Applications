#ifndef LIDAR_H
#define LIDAR_H

#include "stm32f4xx_hal.h"
#include "pinmap.h"

class LiDAR
{
private:
    UART_HandleTypeDef huart;
public:
    LiDAR(pinStruct_t& txPin, pinStruct_t& rxPin, USART_TypeDef* USARTx, uint32_t baudRate, uint32_t gpioAFSelUSARTx);
    uint32_t GetDistance();
};

#endif // LIDAR_H
