#ifndef __MIDD_DELAY_H
#define __MIDD_DELAY_H


#include "stm32f10x.h" 
#include "core_cm3.h" 

void SysTick_Delay_us(uint32_t us);
void SysTick_Delay_ms(uint32_t ms);

void Delay( uint32_t count );

#endif  /*__MIDD_DELAY_H*/
