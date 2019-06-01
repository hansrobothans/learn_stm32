#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_usart.h"
#include "midd_GeneralTim.h" 

uint32_t time = 0; // ms ��ʱ���� 

int main(void)
{
	uint32_t time;
	
	// TIM ������������ʱ��
	uint32_t TIM_PscCLK = 72000000 / (GENERAL_TIM_Prescaler+1);
	
	/* ���ڳ�ʼ�� */
	USART_Config();
	
	/* ��ʱ����ʼ�� */
	GENERAL_TIM_Init();
	
	
	while ( 1 )
	{
		if(TIM_ICUserValueStructure.Capture_FinishFlag == 1)
		{
			// ����ߵ�ƽʱ��ļ�������ֵ
			time = TIM_ICUserValueStructure.Capture_Period * (GENERAL_TIM_Period+1) + 
			       (TIM_ICUserValueStructure.Capture_CcrValue+1);
			
			// ��ӡ�ߵ�ƽ����ʱ��
			printf ( "\r\n��øߵ�ƽ����ʱ�䣺%d.%d s\r\n",time/TIM_PscCLK,time%TIM_PscCLK );
			
			TIM_ICUserValueStructure.Capture_FinishFlag = 0;			
	
		}
	}
}
