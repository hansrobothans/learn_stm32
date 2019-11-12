#include "reg52.h"

typedef struct 
{
	bit T1_GATE;
	bit T1_CT;
	bit T1_M1;
	bit T1_M0;
	
	bit T0_GATE;
	bit T0_CT;
	bit T0_M1;
	bit T0_M0;
}Time_TMOD;

typedef struct 
{
	bit TF1;
	bit TR1;
	bit TF0;
	bit TR0;
	
	bit IE1;
	bit IT1;
	bit IE0;
	bit IT0;
}Time_TCON;

void Time_init(Time_TMOD time_TMOD,Time_TCON time_TCON)
{
	unsigned char TMOD_init=((((((time_TMOD.T1_GATE*2+
									time_TMOD.T1_CT)*2+
									time_TMOD.T1_M1)*2+
									time_TMOD.T1_M0)*2+
									time_TMOD.T0_GATE)*2+
									time_TMOD.T0_CT)*2+
									time_TMOD.T0_M1)*2+
									time_TMOD.T0_M0;
	unsigned char TCON_init=((((((time_TCON.TF1*2+
									time_TCON.TR1)*2+
									time_TCON.TF0)*2+
									time_TCON.TR0)*2+
									time_TCON.IE1)*2+
									time_TCON.IT1)*2+
									time_TCON.IE0)*2+
									time_TCON.IT0;
	TMOD = TMOD_init;
	TCON = TCON_init;

}

void main(void)
{
	
}