#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_BasicTime.h"

uint16_t time=0;

int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
	LED_GPIO_Config();
	BASIC_TIM_Init();
	while (1)
	{
		if (time == 1000)
		{
			time = 0;
			LED_G_TOGGLE;
		}
	}
	
}

