#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_AdvanceTim.h" 
#include "midd_GeneralTim.h" 
#include "midd_usart.h"

int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
	/* 串口初始化 */
	USART_Config();
	
	/* 通用定时器初始化，用于生成PWM信号 */
	GENERAL_TIM_Init();
	
	/* 高级定时器初始化 ，用户捕获PWM信号*/
	ADVANCE_TIM_Init();
	
	while(1)
	{
	}
	
}

