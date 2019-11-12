#include "midd_systick.h"

#if 0
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
	//判断ticks的值是否大于2^24，否则不合法
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            /* Reload value impossible */
  
	//初始化reload寄存器
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* set reload register */
	
	//配置中断优先级，配置为15，默认为最低优先级，配置内部中断没有分组，所以只需要按照外部分组人为来区分抢占优先级和子优先级
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* set Priority for Cortex-M0 System Interrupts */
  
	//配置counter的值 计数器的值
	SysTick->VAL   = 0;                                          /* Load the SysTick Counter Value */
  
	//配置systick的时钟为72M
	//中断使能
	//使能systick
	SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */
  return (0);                                                  /* Function successful */
}
#endif

void SysTick_Delay_us(uint32_t us)
{
	uint32_t i;
	SysTick_Config(72);
	
	for(i=0;i<us;i++)
	{
		while( !(SysTick->CTRL & (1<<16)));
	}
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
	
}

void SysTick_Delay_ms(uint32_t ms)
{
	uint32_t i;
	SysTick_Config(72000);
	
	for(i=0;i<ms;i++)
	{
		while( !(SysTick->CTRL & (1<<16)));
	}
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
	
}

