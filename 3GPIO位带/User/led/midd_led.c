#include "midd_led.h"
#include "midd_delay.h"


void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LED_G_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStruct);	
	
}

void LED_DELAY_1_0(void)
{
	while(1)
	{
		LED_G(OFF);
		Delay(0xFFFFF);
		
		LED_G(ON);
		Delay(0xFFFFF);
	}
}

void LED_weidai_1_0(void)
{
	while(1)
	{
		PCout(13) = 1;
		Delay(0xFFFFF);
		
		PCout(13) = 0;
		Delay(0xFFFFF);
	}
}
