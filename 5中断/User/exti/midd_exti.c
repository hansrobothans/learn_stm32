#include "midd_exti.h"

static void EXTI_NVIC_Config(void)
{
	//3�������ȼ�
		//3.2����NVIC�ṹ�壬ȥmisc.h
	NVIC_InitTypeDef	NVIC_InitStruct;
		//3.1�����жϷ���
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_X);
	
		//3.2��ʼ��NVIC�ṹ��
			//3.2.1�����ж�Դ���ж��߶�Ӧ
	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
			//3.2.2���������ȼ�/��ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
			//3.2.3���������ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
			//3.2.3�����ж�
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
		//3.3��ʼ���ṹ���ʼ������
	NVIC_Init(&NVIC_InitStruct);	
}


void EXTI_Key_Config(void)
{
		//1�����жϴ���io�ڽṹ��
	GPIO_InitTypeDef  GPIO_InitStruct;
	
		//2.3�����ʼ��EXTI�ṹ��
	EXTI_InitTypeDef	EXTI_InitStruct;
	
	//3�����ж����ȼ�
	EXTI_NVIC_Config();
	
	//1.��ʼ��GPIO
		//1.1��ʱ��
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);
		//1.2ѡ������
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
		//1.3ѡ��ģʽ
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		//1.4��ʼ��gpio
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStruct);
	
	//2��ʼ��EXTI
		//��ʼ��ʱ��APB
		//2.2����io����Ҫ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
		//2.1����ѡ��������AFIO_EXTICR1,��GPIO����GPIO.H��
	GPIO_EXTILineConfig(Key_GPIO_PortSourceGPIOX, Key_GPIO_PinSourceX);
	
		//2.3��ʼ��EXTI�ṹ��
			//2.3.1�ж���PX[0-15]
	EXTI_InitStruct.EXTI_Line = EXTI_LineX;
			//2.3.2EXTIģʽ���ж�/�¼���
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
			//2.3.3��������/��/���£�
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
			//2.3.4ʹ�ܻ���ʧ�ܣ�IMR/EMR��
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
		//2.4���ú�������ʼ���ṹ��д����Ӧ�ļĴ�������
	EXTI_Init(&EXTI_InitStruct);
	
}


