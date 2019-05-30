#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_AdvanceTim.h" 

int main(void)
{
	
	/* 高级定时器初始化 */
	ADVANCE_TIM_Init();
	
	while(1)
	{
	}
	
}

