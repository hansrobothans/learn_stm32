#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_GeneralTim.h" 

uint32_t time = 0; // ms ��ʱ���� 

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	/* led �˿����� */ 
	LED_GPIO_Config();
	
	/* ��ʱ����ʼ�� */
	GENERAL_TIM_Init();
	
  while(1)
  {      
  }
	
}

