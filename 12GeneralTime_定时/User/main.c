#include "stm32f10x.h"   
#include "midd_led.h"
#include "midd_GeneralTim.h" 

uint32_t time = 0; // ms 计时变量 

int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
	/* led 端口配置 */ 
	LED_GPIO_Config();
	
	GENERAL_TIM_Init();
	
  while(1)
  {
    if ( time == 1000 ) /* 1000 * 1 ms = 1s 时间到 */
    {
      time = 0;
			/* LED1 取反 */      
			LED_G_TOGGLE; 
    }        
  }
	
}

