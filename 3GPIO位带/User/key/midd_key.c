#include "midd_key.h"


void KEY1_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(KEY1_G_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = KEY1_G_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
	
	GPIO_Init(KEY1_G_GPIO_PORT, &GPIO_InitStruct);	
	
}

uint8_t Key1_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	if( GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON)
	{
		//���ּ��
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);
		return KEY_ON;
	}
	else 
		return KEY_OFF;
	
}


uint8_t Key1_Scan_weidai(uint16_t PA_n)
{
	if( PAin(PA_n)  == KEY_ON)
	{
		//���ּ��
		while(PAin(PA_n)  == KEY_ON);
		return KEY_ON;
	}
	else 
		return KEY_OFF;
	
}

