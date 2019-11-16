#ifndef __TIMER_H
#define __TIMER_H
#include "reg52.h"
#include "Type.h"

#define CO 11.0592	//����Ƶ��

typedef enum
{ 
	GPIO_Mode_AIN = 0x0,
}GPIOMode_TypeDef;

typedef struct
{
  uint8 TMOD;
	
//	GATE=0����ʱ��������TCON��TR����
//	GATE=1����ʱ��������TCON��TR���ⲿ�ж��ź�INT��ͬ����
	bit 	GATE_11;	
//	CT=0,��ʱ��ģʽ
//	CT=1,������ģʽ
	bit		CT_1;
//	M1=0,MO=0,������ʽ0��13λ������
//	M1=0,MO=1,������ʽ1��16λ������
//	M1=1,MO=0,������ʽ2��8λ�Զ���װ�ؼ�����
//	M1=0,MO=1,������ʽ3��T0����������������T1��Ч
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
//	��ʱ�������־λ
	bit	TF1;
//	��ʱ����������λ
	bit	TR1;
//	��ʱ�������־λ
	bit	TF0;
//	��ʱ����������λ
	bit	TR0;
	
	bit	IE1
	bit	IT1
	bit	IE0
	bit	IT0
}Timer_TCON;
//���ö�ʱ����ֵ����
void TimerValueReset(Timer_TMOD *timer_TMOD,Timer_TCON *timer_TCON)
{
	timer_TMOD->TMOD=0;
//	GATE=0����ʱ��������TCON��TR����
//	GATE=1����ʱ��������TCON��TR���ⲿ�ж��ź�INT��ͬ����
	timer_TMOD->GATE_11=0;	
//	CT=0,��ʱ��ģʽ
//	CT=1,������ģʽ
	timer_TMOD->CT_1=0;
//	M1=0,MO=0,������ʽ0��13λ������
//	M1=0,MO=1,������ʽ1��16λ������
//	M1=1,MO=0,������ʽ2��8λ�Զ���װ�ؼ�����
//	M1=0,MO=1,������ʽ3��T0����������������T1��Ч
	timer_TMOD->M1_1=0;
	timer_TMOD->M0_1=0;
	timer_TMOD->GATE_0=0;
	timer_TMOD->CT_0=0;
	timer_TMOD->M1_0=0;
	timer_TMOD->M0_0=0;

	timer_TCON->TCON=0;
//	��ʱ�������־λ
	timer_TCON->TF1=0;
//	��ʱ����������λ
	timer_TCON->TR1=0;
//	��ʱ�������־λ
	timer_TCON->TF0=0;
//	��ʱ����������λ
	timer_TCON->TR0=0;
}
void TimerInit0(void)
{
	timer_TMOD->TMOD=0;
//	GATE=0����ʱ��������TCON��TR����
//	GATE=1����ʱ��������TCON��TR���ⲿ�ж��ź�INT��ͬ����
	timer_TMOD->GATE_0=0;	
//	CT=0,��ʱ��ģʽ
//	CT=1,������ģʽ
	timer_TMOD->CT_0=0;
//	M1=0,MO=0,������ʽ0��13λ������
//	M1=0,MO=1,������ʽ1��16λ������
//	M1=1,MO=0,������ʽ2��8λ�Զ���װ�ؼ�����
//	M1=0,MO=1,������ʽ3��T0����������������T1��Ч
	timer_TMOD->M1_0=0;
	timer_TMOD->M0_0=0;

	timer_TCON->TCON=0;
//	��ʱ�������־λ
	timer_TCON->TF0=0;
//	��ʱ����������λ
	timer_TCON->TR0=0;
}
void TimerInit1(void)
{
	timer_TMOD->TMOD=0;
//	GATE=0����ʱ��������TCON��TR����
//	GATE=1����ʱ��������TCON��TR���ⲿ�ж��ź�INT��ͬ����
	timer_TMOD->GATE_11=0;	
//	CT=0,��ʱ��ģʽ
//	CT=1,������ģʽ
	timer_TMOD->CT_1=0;
//	M1=0,MO=0,������ʽ0��13λ������
//	M1=0,MO=1,������ʽ1��16λ������
//	M1=1,MO=0,������ʽ2��8λ�Զ���װ�ؼ�����
//	M1=0,MO=1,������ʽ3��T0����������������T1��Ч
	timer_TMOD->M1_1=0;
	timer_TMOD->M0_1=0;

	timer_TCON->TCON=0;
//	��ʱ�������־λ
	timer_TCON->TF0=0;
//	��ʱ����������λ
	timer_TCON->TR0=0;
}

#endif  /*__TIMER_H*/
