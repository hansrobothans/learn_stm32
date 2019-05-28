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

void LED_HuXi_led(void)
{
	uint32_t t=0;
	uint32_t t_max=1000;
	
	while(1)
	{
		while(t < t_max)
		{
			t++;
			LED_G(OFF);
			SysTick_Delay_us(t);

			LED_G(ON);
			SysTick_Delay_us(t_max-t);
		}
		while(t > 0)
		{
			t--;
			LED_G(OFF);
			SysTick_Delay_us(t);

			LED_G(ON);
			SysTick_Delay_us(t_max-t);
		}
		

	}
}

