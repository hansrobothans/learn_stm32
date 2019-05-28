#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_delay.h"

int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
	LED_GPIO_Config();
	
	LED_HuXi_led();
	
}

