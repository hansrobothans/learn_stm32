#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_GeneralTim.h" 

uint32_t time = 0; // ms ��ʱ���� 

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	/* led �˿����� */ 
	LED_GPIO_Config();
	
	GENERAL_TIM_Init();
	
  while(1)
  {
    if ( time == 1000 ) /* 1000 * 1 ms = 1s ʱ�䵽 */
    {
      time = 0;
			/* LED1 ȡ�� */      
			LED_G_TOGGLE; 
    }        
  }
	
}

