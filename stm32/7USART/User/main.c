#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_delay.h"
#include "midd_usart.h"

int main(void)
{
//	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
//	LED_GPIO_Config();
//	
//	LED_HuXi_led();
	
	USART_Config();
	while(1)
	{
//		Usart_SendByte(DEBUG_USARTx ,'a');
//		Usart_SendHalfWord(DEBUG_USARTx ,0x6464);
		Usart_SendStr(DEBUG_USARTx, "���\n");
		SysTick_Delay_ms(2000);
	}
	
	
	
}

