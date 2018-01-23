#include <reg51.h>
sbit LED = P2^0;

sbit sw = P1^0;
void delay(unsigned int );
main()
{
	sw=1;
	LED=1;
	while(1)
	{
		if(sw==0)
		{
			LED=0;
			delay(10);
			LED=1;
		}
	}
}
void delay(unsigned int n)
{
	TMOD= 0x01; // timer 0 mode 1
	TH0=0xDC;
	TL=0x00;
	TR=1;
	while(TF==0);
	TF=0;
	TR=0;
}