#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_AdvanceTim.h" 
#include "midd_GeneralTim.h" 
#include "midd_usart.h"

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	/* ���ڳ�ʼ�� */
	USART_Config();
	
	/* ͨ�ö�ʱ����ʼ������������PWM�ź� */
	GENERAL_TIM_Init();
	
	/* �߼���ʱ����ʼ�� ���û�����PWM�ź�*/
	ADVANCE_TIM_Init();
	
	while(1)
	{
	}
	
}

