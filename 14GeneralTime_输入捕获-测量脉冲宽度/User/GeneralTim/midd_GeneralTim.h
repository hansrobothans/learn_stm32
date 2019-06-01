#ifndef __MIDD_GENERALTIME_H
#define __MIDD_GENERALTIME_H

#include "stm32f10x.h"


/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 我们这里默认使用TIM5

#define            GENERAL_TIM                   TIM5
#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_CLK               RCC_APB1Periph_TIM5
#define            GENERAL_TIM_Period            0XFFFF
#define            GENERAL_TIM_Prescaler         (72-1)

// TIM5 输出比较通道1
#define            GENERAL_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH1_PORT          GPIOA
#define            GENERAL_TIM_CH1_PIN           GPIO_Pin_0


// TIM5 输出比较通道2
#define            GENERAL_TIM_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH2_PORT          GPIOA
#define            GENERAL_TIM_CH2_PIN           GPIO_Pin_1

//// TIM5 输出比较通道3
//#define            GENERAL_TIM_CH3_GPIO_CLK      RCC_APB2Periph_GPIOA
//#define            GENERAL_TIM_CH3_PORT          GPIOA
//#define            GENERAL_TIM_CH3_PIN           GPIO_Pin_2

// TIM5 输出比较通道4
#define            GENERAL_TIM_CH4_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH4_PORT          GPIOA
#define            GENERAL_TIM_CH4_PIN           GPIO_Pin_3


// TIM5 输入捕获通道1GPIO相关宏定义
//#define            GENERAL_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
//#define            GENERAL_TIM_CH1_PORT          GPIOA
//#define            GENERAL_TIM_CH1_PIN           GPIO_Pin_0
//#define            GENERAL_TIM_CHANNEL_x         TIM_Channel_1

//// TIM5 输入捕获通道2GPIO相关宏定义
//#define            GENERAL_TIM_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
//#define            GENERAL_TIM_CH2_PORT          GPIOA
//#define            GENERAL_TIM_CH2_PIN           GPIO_Pin_1
//#define            GENERAL_TIM_CHANNEL_x         TIM_Channel_2

// TIM5 输入捕获通道3GPIO相关宏定义
#define            GENERAL_TIM_CH3_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH3_PORT          GPIOA
#define            GENERAL_TIM_CH3_PIN           GPIO_Pin_2
#define            GENERAL_TIM_CHANNEL_x         TIM_Channel_3

//// TIM5 输入捕获通道4GPIO相关宏定义
//#define            GENERAL_TIM_CH4_GPIO_CLK      RCC_APB2Periph_GPIOA
//#define            GENERAL_TIM_CH4_PORT          GPIOA
//#define            GENERAL_TIM_CH4_PIN           GPIO_Pin_3
//#define            GENERAL_TIM_CHANNEL_x         TIM_Channel_4

// 中断相关宏定义
//#define            GENERAL_TIM_IT_CCx            TIM_IT_CC1
//#define            GENERAL_TIM_IT_CCx            TIM_IT_CC2
#define            GENERAL_TIM_IT_CCx            TIM_IT_CC3
//#define            GENERAL_TIM_IT_CCx            TIM_IT_CC4

#define            GENERAL_TIM_IRQ               TIM5_IRQn
#define            GENERAL_TIM_INT_FUN           TIM5_IRQHandler

// 获取捕获寄存器值函数宏定义
//#define            GENERAL_TIM_GetCapturex_FUN                 TIM_GetCapture1
//#define            GENERAL_TIM_GetCapturex_FUN                 TIM_GetCapture2
#define            GENERAL_TIM_GetCapturex_FUN                 TIM_GetCapture3
//#define            GENERAL_TIM_GetCapturex_FUN                 TIM_GetCapture4
// 捕获信号极性函数宏定义
//#define            GENERAL_TIM_OCxPolarityConfig_FUN           TIM_OC1PolarityConfig
//#define            GENERAL_TIM_OCxPolarityConfig_FUN           TIM_OC2PolarityConfig
#define            GENERAL_TIM_OCxPolarityConfig_FUN           TIM_OC3PolarityConfig
//#define            GENERAL_TIM_OCxPolarityConfig_FUN           TIM_OC4PolarityConfig

// 测量的起始边沿
#define            GENERAL_TIM_STRAT_ICPolarity                TIM_ICPolarity_Rising
// 测量的结束边沿
#define            GENERAL_TIM_END_ICPolarity                  TIM_ICPolarity_Falling


// 定时器输入捕获用户自定义变量结构体声明
typedef struct
{   
	uint8_t   Capture_FinishFlag;   // 捕获结束标志位
	uint8_t   Capture_StartFlag;    // 捕获开始标志位
	uint16_t  Capture_CcrValue;     // 捕获寄存器的值
	uint16_t  Capture_Period;       // 自动重装载寄存器更新标志 
}TIM_ICUserValueTypeDef;

extern TIM_ICUserValueTypeDef TIM_ICUserValueStructure;

/**************************函数声明********************************/
void GENERAL_TIM_Init(void);


#endif	/* __MIDD_GENERALTIME_H */


