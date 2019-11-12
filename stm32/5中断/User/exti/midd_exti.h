#ifndef __MIDD_EXTI_H
#define __MIDD_EXTI_H

#include "stm32f10x.h"


#define KEY1_INT_GPIO_PIN              	GPIO_Pin_12
#define KEY1_INT_GPIO_PORT             	GPIOB
#define KEY1_INT_GPIO_CLK              	RCC_APB2Periph_GPIOB

#define	Key_GPIO_PortSourceGPIOX				GPIO_PortSourceGPIOB
#define	Key_GPIO_PinSourceX							GPIO_PinSource12

#define EXTI_LineX											EXTI_Line12									

#define NVIC_PriorityGroup_X						NVIC_PriorityGroup_1

void EXTI_Key_Config(void);


#endif  /*__MIDD_EXTI_H*/
