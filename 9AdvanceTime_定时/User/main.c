#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_AdvanceTim.h" 

uint32_t time = 0; // ms ��ʱ���� 


int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	LED_GPIO_Config();
	
	ADVANCE_TIM_Init();
	
	LED_DELAY_1_0();
	
}

