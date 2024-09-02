#include "lcd.h"

int main(void)
{
	HAL_Init();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	pinStruct_t rs = {GPIOA,GPIO_PIN_0};
	pinStruct_t en = {GPIOA,GPIO_PIN_1};
	pinStruct_t d4 = {GPIOA,GPIO_PIN_4};
	pinStruct_t d5 = {GPIOA,GPIO_PIN_5};
	pinStruct_t d6 = {GPIOA,GPIO_PIN_6};
	pinStruct_t d7 = {GPIOA,GPIO_PIN_7};
	
	static LCD lcd(rs,en,d4,d5,d6,d7);
	
	
	while(1)
	{
		lcd.Print("Hello world!");
		HAL_Delay(1000);
		lcd.Clear();
		HAL_Delay(1000);
		lcd.Print("Random Stuff:");
		lcd.SetCursor(1,0);
		lcd.Print("!'^+%&/()=?_;");
		HAL_Delay(1000);
		lcd.Clear();
	}
	
}
