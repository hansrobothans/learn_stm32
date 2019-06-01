#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_usart.h"
#include "midd_GeneralTim.h" 

uint32_t time = 0; // ms 计时变量 

int main(void)
{
	uint32_t time;
	
	// TIM 计数器的驱动时钟
	uint32_t TIM_PscCLK = 72000000 / (GENERAL_TIM_Prescaler+1);
	
	/* 串口初始化 */
	USART_Config();
	
	/* 定时器初始化 */
	GENERAL_TIM_Init();
	
	
	while ( 1 )
	{
		if(TIM_ICUserValueStructure.Capture_FinishFlag == 1)
		{
			// 计算高电平时间的计数器的值
			time = TIM_ICUserValueStructure.Capture_Period * (GENERAL_TIM_Period+1) + 
			       (TIM_ICUserValueStructure.Capture_CcrValue+1);
			
			// 打印高电平脉宽时间
			printf ( "\r\n测得高电平脉宽时间：%d.%d s\r\n",time/TIM_PscCLK,time%TIM_PscCLK );
			
			TIM_ICUserValueStructure.Capture_FinishFlag = 0;			
	
		}
	}
}
