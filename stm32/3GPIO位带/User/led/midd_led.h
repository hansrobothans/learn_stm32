#ifndef __MIDD_LED_H
#define __MIDD_LED_H

#include "stm32f10x.h"

#define LED_G_GPIO_PIN              GPIO_Pin_2
#define LED_G_GPIO_PORT             GPIOD
#define LED_G_GPIO_CLK              RCC_APB2Periph_GPIOD

#define    ON        1
#define    OFF       0

// \  C语言里面叫续行符，后面不能有任何的东西

#define   LED_G(a)   if(a) \
	                       GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN); \
                     else  GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);

#define LED_G_TOGGLE		{LED_G_GPIO_PORT->ODR ^= LED_G_GPIO_PIN;}

#define GPIOD_ODR_Addr (GPIOD_BASE+0X0C)
#define PDout(n)     *(unsigned int*)((GPIOD_ODR_Addr & 0xF0000000) + 0x02000000 + ((GPIOD_ODR_Addr & 0x00FFFFFF) << 5) +(n << 2))

void LED_GPIO_Config(void);
void LED_DELAY_1_0(void);
void LED_weidai_1_0(void);

#endif  /*__MIDD_LED_H*/
