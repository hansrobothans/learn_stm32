#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_delay.h"
#include "midd_key.h"



int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
	LED_GPIO_Config();
	KEY1_GPIO_Config();

#if 0	
	
	//LED_DELAY_1_0();
	LED_weidai_1_0();

#else

//	while(1)
//	{
//		if (Key1_Scan(KEY1_G_GPIO_PORT,KEY1_G_GPIO_PIN) == KEY_ON)
//		{
//			LED_G_TOGGLE;
//		}
//	}
	
	while(1)
	{
		if (Key1_Scan_weidai(12) == KEY_ON)
		{
			LED_G_TOGGLE;
		}
	}
#endif
	
}

