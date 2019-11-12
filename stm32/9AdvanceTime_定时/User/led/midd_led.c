#include "midd_led.h"
#include "midd_AdvanceTim.h" 


extern volatile uint32_t time;

void LED_GPIO_Config(void)
{
	/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef  GPIO_InitStruct;
	/*开启LED相关的GPIO外设时钟*/
	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE);
	/*选择要控制的GPIO引脚*/
	GPIO_InitStruct.GPIO_Pin = LED_G_GPIO_PIN;
	/*设置引脚模式为通用推挽输出*/
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	/*设置引脚速率为50MHz */   
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	/*调用库函数，初始化GPIO*/
	GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStruct);	
	
}

void LED_DELAY_1_0(void)
{
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
