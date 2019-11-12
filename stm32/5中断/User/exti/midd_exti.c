#include "midd_exti.h"

static void EXTI_NVIC_Config(void)
{
	//3配置优先级
		//3.2定义NVIC结构体，去misc.h
	NVIC_InitTypeDef	NVIC_InitStruct;
		//3.1设置中断分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_X);
	
		//3.2初始化NVIC结构体
			//3.2.1设置中断源和中断线对应
	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
			//3.2.2设置主优先级/抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
			//3.2.3设置子优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
			//3.2.3开总中断
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
		//3.3初始化结构体初始化函数
	NVIC_Init(&NVIC_InitStruct);	
}


void EXTI_Key_Config(void)
{
		//1定义中断触发io口结构体
	GPIO_InitTypeDef  GPIO_InitStruct;
	
		//2.3定义初始化EXTI结构体
	EXTI_InitTypeDef	EXTI_InitStruct;
	
	//3配置中断优先级
	EXTI_NVIC_Config();
	
	//1.初始化GPIO
		//1.1开时钟
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);
		//1.2选择引脚
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
		//1.3选择模式
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		//1.4初始化gpio
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStruct);
	
	//2初始化EXTI
		//初始化时钟APB
		//2.2操作io口需要打开时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
		//2.1配置选择输入线AFIO_EXTICR1,是GPIO的在GPIO.H找
	GPIO_EXTILineConfig(Key_GPIO_PortSourceGPIOX, Key_GPIO_PinSourceX);
	
		//2.3初始化EXTI结构体
			//2.3.1中断线PX[0-15]
	EXTI_InitStruct.EXTI_Line = EXTI_LineX;
			//2.3.2EXTI模式（中断/事件）
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
			//2.3.3触发（上/下/上下）
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
			//2.3.4使能或者失能（IMR/EMR）
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
		//2.4调用函数将初始化结构体写到相应的寄存器当中
	EXTI_Init(&EXTI_InitStruct);
	
}


