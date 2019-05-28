#ifndef __MIDD_RCCCLKCONFIG_H
#define __MIDD_RCCCLKCONFIG_H

#include "stm32f10x.h"

void HSE_SetSysClk( uint32_t RCC_PLLMul_x );
void HSI_SetSysClk( uint32_t RCC_PLLMul_x );
void MCO_GPIO_Config(void);


#endif  /*__MIDD_RCCCLKCONFIG_H*/


