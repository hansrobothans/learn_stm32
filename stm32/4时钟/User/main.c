#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_delay.h"
#include "midd_rccclkconfig.h"

int main(void)
{
	
	//HSE_SetSysClk(RCC_PLLMul_16 );
//	HSI_SetSysClk(RCC_PLLMul_8);
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	LED_GPIO_Config();
	
	
	LED_DELAY_1_0();
	
}

