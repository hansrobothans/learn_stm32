#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_delay.h"

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	LED_GPIO_Config();
	
	LED_HuXi_led();
	
}




