#ifndef __MIDD_KEY_H
#define __MIDD_KEY_H

#include "stm32f10x.h"


#define KEY_ON 1
#define KEY_OFF 0

#define KEY1_G_GPIO_PIN              GPIO_Pin_0
#define KEY1_G_GPIO_PORT             GPIOA
#define KEY1_G_GPIO_CLK              RCC_APB2Periph_GPIOA

#define GPIOA_IDR_Addr (GPIOA_BASE+0X08)
#define PAin(n)     *(unsigned int*)((GPIOA_IDR_Addr & 0xF0000000) + 0x02000000 + ((GPIOA_IDR_Addr & 0x00FFFFFF) << 5) +(n << 2))



void KEY1_GPIO_Config(void);
uint8_t Key1_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint8_t Key1_Scan_weidai(uint16_t PB_n);


#endif  /*__MIDD_KEY_H*/

