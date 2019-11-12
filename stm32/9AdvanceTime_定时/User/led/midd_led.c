#include "midd_led.h"
#include "midd_AdvanceTim.h" 


extern volatile uint32_t time;

void LED_GPIO_Config(void)
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef  GPIO_InitStruct;
	/*����LED��ص�GPIO����ʱ��*/
	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE);
	/*ѡ��Ҫ���Ƶ�GPIO����*/
	GPIO_InitStruct.GPIO_Pin = LED_G_GPIO_PIN;
	/*��������ģʽΪͨ���������*/
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	/*������������Ϊ50MHz */   
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	/*���ÿ⺯������ʼ��GPIO*/
	GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStruct);	
	
}

void LED_DELAY_1_0(void)
{
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
