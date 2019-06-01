#ifndef __MIDD_GENERALTIME_H
#define __MIDD_GENERALTIME_H

#include "stm32f10x.h"


/************ͨ�ö�ʱ��TIM�������壬ֻ��TIM2��3��4��5************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������Ĭ��ʹ��TIM5

#define            GENERAL_TIM                   TIM5
#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_CLK               RCC_APB1Periph_TIM5
#define            GENERAL_TIM_Period            0XFFFF
#define            GENERAL_TIM_Prescaler         (72-1)

// TIM5 ����Ƚ�ͨ��1
#define            GENERAL_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH1_PORT          GPIOA
#define            GENERAL_TIM_CH1_PIN           GPIO_Pin_0


// TIM5 ����Ƚ�ͨ��2
#define            GENERAL_TIM_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH2_PORT          GPIOA
#define            GENERAL_TIM_CH2_PIN           GPIO_Pin_1

//// TIM5 ����Ƚ�ͨ��3
//#define            GENERAL_TIM_CH3_GPIO_CLK      RCC_APB2Periph_GPIOA
//#define            GENERAL_TIM_CH3_PORT          GPIOA
//#define            GENERAL_TIM_CH3_PIN           GPIO_Pin_2

// TIM5 ����Ƚ�ͨ��4
#define            GENERAL_TIM_CH4_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH4_PORT          GPIOA
#define            GENERAL_TIM_CH4_PIN           GPIO_Pin_3


// TIM5 ���벶��ͨ��1GPIO��غ궨��
//#define            GENERAL_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
//#define            GENERAL_TIM_CH1_PORT          GPIOA
//#define            GENERAL_TIM_CH1_PIN           GPIO_Pin_0
//#define            GENERAL_TIM_CHANNEL_x         TIM_Channel_1

//// TIM5 ���벶��ͨ��2GPIO��غ궨��
//#define            GENERAL_TIM_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
//#define            GENERAL_TIM_CH2_PORT          GPIOA
//#define            GENERAL_TIM_CH2_PIN           GPIO_Pin_1
//#define            GENERAL_TIM_CHANNEL_x         TIM_Channel_2

// TIM5 ���벶��ͨ��3GPIO��غ궨��
#define            GENERAL_TIM_CH3_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH3_PORT          GPIOA
#define            GENERAL_TIM_CH3_PIN           GPIO_Pin_2
#define            GENERAL_TIM_CHANNEL_x         TIM_Channel_3

//// TIM5 ���벶��ͨ��4GPIO��غ궨��
//#define            GENERAL_TIM_CH4_GPIO_CLK      RCC_APB2Periph_GPIOA
//#define            GENERAL_TIM_CH4_PORT          GPIOA
//#define            GENERAL_TIM_CH4_PIN           GPIO_Pin_3
//#define            GENERAL_TIM_CHANNEL_x         TIM_Channel_4

// �ж���غ궨��
//#define            GENERAL_TIM_IT_CCx            TIM_IT_CC1
//#define            GENERAL_TIM_IT_CCx            TIM_IT_CC2
#define            GENERAL_TIM_IT_CCx            TIM_IT_CC3
//#define            GENERAL_TIM_IT_CCx            TIM_IT_CC4

#define            GENERAL_TIM_IRQ               TIM5_IRQn
#define            GENERAL_TIM_INT_FUN           TIM5_IRQHandler

// ��ȡ����Ĵ���ֵ�����궨��
//#define            GENERAL_TIM_GetCapturex_FUN                 TIM_GetCapture1
//#define            GENERAL_TIM_GetCapturex_FUN                 TIM_GetCapture2
#define            GENERAL_TIM_GetCapturex_FUN                 TIM_GetCapture3
//#define            GENERAL_TIM_GetCapturex_FUN                 TIM_GetCapture4
// �����źż��Ժ����궨��
//#define            GENERAL_TIM_OCxPolarityConfig_FUN           TIM_OC1PolarityConfig
//#define            GENERAL_TIM_OCxPolarityConfig_FUN           TIM_OC2PolarityConfig
#define            GENERAL_TIM_OCxPolarityConfig_FUN           TIM_OC3PolarityConfig
//#define            GENERAL_TIM_OCxPolarityConfig_FUN           TIM_OC4PolarityConfig

// ��������ʼ����
#define            GENERAL_TIM_STRAT_ICPolarity                TIM_ICPolarity_Rising
// �����Ľ�������
#define            GENERAL_TIM_END_ICPolarity                  TIM_ICPolarity_Falling


// ��ʱ�����벶���û��Զ�������ṹ������
typedef struct
{   
	uint8_t   Capture_FinishFlag;   // ���������־λ
	uint8_t   Capture_StartFlag;    // ����ʼ��־λ
	uint16_t  Capture_CcrValue;     // ����Ĵ�����ֵ
	uint16_t  Capture_Period;       // �Զ���װ�ؼĴ������±�־ 
}TIM_ICUserValueTypeDef;

extern TIM_ICUserValueTypeDef TIM_ICUserValueStructure;

/**************************��������********************************/
void GENERAL_TIM_Init(void);


#endif	/* __MIDD_GENERALTIME_H */


