��core_cm3.h��
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
	//�ж�ticks��ֵ�Ƿ����2^24�����򲻺Ϸ�
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            /* Reload value impossible */
  
	//��ʼ��reload�Ĵ���
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* set reload register */
	
	//�����ж����ȼ�������Ϊ15��Ĭ��Ϊ������ȼ��������ڲ��ж�û�з��飬����ֻ��Ҫ�����ⲿ������Ϊ��������ռ���ȼ��������ȼ�
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* set Priority for Cortex-M0 System Interrupts */
  
	//����counter��ֵ ��������ֵ
	SysTick->VAL   = 0;                                          /* Load the SysTick Counter Value */
  
	//����systick��ʱ��Ϊ72M
	//�ж�ʹ��
	//ʹ��systick
	SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */
  return (0);                                                  /* Function successful */
}