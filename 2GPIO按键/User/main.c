#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_delay.h"
#include "midd_key.h"

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	LED_GPIO_Config();
	KEY1_GPIO_Config();
	
	while(1)
	{
		if (Key1_Scan(KEY1_G_GPIO_PORT,KEY1_G_GPIO_PIN) == KEY_ON)
		{
			LED_G_TOGGLE;
		}
	}
	
}

