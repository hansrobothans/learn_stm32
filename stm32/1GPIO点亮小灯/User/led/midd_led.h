#ifndef __MIDD_LED_H
#define __MIDD_LED_H

#include "stm32f10x.h"

#define LED_G_GPIO_PIN              GPIO_Pin_2
#define LED_G_GPIO_PORT             GPIOD
#define LED_G_GPIO_CLK              RCC_APB2Periph_GPIOD

#define    ON        1
#define    OFF       0

// \  C������������з������治�����κεĶ���

#define   LED_G(a)   if(a) \
	                       GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN); \
                     else  GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);


void LED_GPIO_Config(void);
void LED_DELAY_1_0(void);

#endif  /*__MIDD_LED_H*/
