#include "reg52.h"

void delay(void)
{
	int t = 20000;
	int i;
	for(i=t;i>0;i--);
}
void main(void)
{
	int i=0;
	char led=0x01;
	while(1)
	{
		P0=0xfe;
		delay();
		P0=0xfd;
		delay();
		P0=0xfb;
		delay();
		P0=0xf7;
		delay();
		P0=0xef;
		delay();
		P0=0xdf;
		delay();
		P0=0xbf;
		delay();
		P0=0x7f;
		delay();
	}
}