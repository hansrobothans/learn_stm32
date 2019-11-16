#ifndef __TIMER_H
#define __TIMER_H
#include "reg52.h"
#include "Type.h"

#define CO 11.0592	//晶振频率

typedef enum
{ 
	GPIO_Mode_AIN = 0x0,
}GPIOMode_TypeDef;

typedef struct
{
  uint8 TMOD;
	
//	GATE=0，定时器启动由TCON中TR控制
//	GATE=1，定时器启动由TCON中TR和外部中断信号INT共同控制
	bit 	GATE_11;	
//	CT=0,定时器模式
//	CT=1,计数器模式
	bit		CT_1;
//	M1=0,MO=0,工作方式0，13位计数器
//	M1=0,MO=1,工作方式1，16位计数器
//	M1=1,MO=0,工作方式2，8位自动重装载计数器
//	M1=0,MO=1,工作方式3，T0两个独立计数器，T1无效
	bit		M1_1;
	bit		M0_1;
	
	bit 	GATE_0;
	bit		CT_0;
	bit		M1_0;
	bit		M0_0;
}Timer_TMOD;

typedef struct
{
  uint8 TCON;
//	定时器溢出标志位
	bit	TF1;
//	定时器启动控制位
	bit	TR1;
//	定时器溢出标志位
	bit	TF0;
//	定时器启动控制位
	bit	TR0;
	
	bit	IE1
	bit	IT1
	bit	IE0
	bit	IT0
}Timer_TCON;
//配置定时参数值赋零
void TimerValueReset(Timer_TMOD *timer_TMOD,Timer_TCON *timer_TCON)
{
	timer_TMOD->TMOD=0;
//	GATE=0，定时器启动由TCON中TR控制
//	GATE=1，定时器启动由TCON中TR和外部中断信号INT共同控制
	timer_TMOD->GATE_11=0;	
//	CT=0,定时器模式
//	CT=1,计数器模式
	timer_TMOD->CT_1=0;
//	M1=0,MO=0,工作方式0，13位计数器
//	M1=0,MO=1,工作方式1，16位计数器
//	M1=1,MO=0,工作方式2，8位自动重装载计数器
//	M1=0,MO=1,工作方式3，T0两个独立计数器，T1无效
	timer_TMOD->M1_1=0;
	timer_TMOD->M0_1=0;
	timer_TMOD->GATE_0=0;
	timer_TMOD->CT_0=0;
	timer_TMOD->M1_0=0;
	timer_TMOD->M0_0=0;

	timer_TCON->TCON=0;
//	定时器溢出标志位
	timer_TCON->TF1=0;
//	定时器启动控制位
	timer_TCON->TR1=0;
//	定时器溢出标志位
	timer_TCON->TF0=0;
//	定时器启动控制位
	timer_TCON->TR0=0;
}
void TimerInit0(void)
{
	timer_TMOD->TMOD=0;
//	GATE=0，定时器启动由TCON中TR控制
//	GATE=1，定时器启动由TCON中TR和外部中断信号INT共同控制
	timer_TMOD->GATE_0=0;	
//	CT=0,定时器模式
//	CT=1,计数器模式
	timer_TMOD->CT_0=0;
//	M1=0,MO=0,工作方式0，13位计数器
//	M1=0,MO=1,工作方式1，16位计数器
//	M1=1,MO=0,工作方式2，8位自动重装载计数器
//	M1=0,MO=1,工作方式3，T0两个独立计数器，T1无效
	timer_TMOD->M1_0=0;
	timer_TMOD->M0_0=0;

	timer_TCON->TCON=0;
//	定时器溢出标志位
	timer_TCON->TF0=0;
//	定时器启动控制位
	timer_TCON->TR0=0;
}
void TimerInit1(void)
{
	timer_TMOD->TMOD=0;
//	GATE=0，定时器启动由TCON中TR控制
//	GATE=1，定时器启动由TCON中TR和外部中断信号INT共同控制
	timer_TMOD->GATE_11=0;	
//	CT=0,定时器模式
//	CT=1,计数器模式
	timer_TMOD->CT_1=0;
//	M1=0,MO=0,工作方式0，13位计数器
//	M1=0,MO=1,工作方式1，16位计数器
//	M1=1,MO=0,工作方式2，8位自动重装载计数器
//	M1=0,MO=1,工作方式3，T0两个独立计数器，T1无效
	timer_TMOD->M1_1=0;
	timer_TMOD->M0_1=0;

	timer_TCON->TCON=0;
//	定时器溢出标志位
	timer_TCON->TF0=0;
//	定时器启动控制位
	timer_TCON->TR0=0;
}

#endif  /*__TIMER_H*/
