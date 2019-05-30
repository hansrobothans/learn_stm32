#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_AdvanceTim.h" 

uint32_t time = 0; // ms 计时变量 


int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
	LED_GPIO_Config();
	
	ADVANCE_TIM_Init();
	
	LED_DELAY_1_0();
	
}

