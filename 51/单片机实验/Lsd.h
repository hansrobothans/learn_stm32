#ifndef __LSD_H
#define __LSD_H

#include "reg52.h"
//延时函数
void delay_ms(int t)
{
	int i;
	t = 20000;

	for(i=t;i>0;i--);
}
//流水灯函数
void lsd(int t)
{
	int led_m[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
	int i = 0;
	while(1)
		for(i=0;i<8;i++)
		{
			P0=led_m[i];
			delay_ms(t);
		}
}

#endif  /*__LSD_H*/