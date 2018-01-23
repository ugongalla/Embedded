#include <reg51.h>

void delay(unsigned int );
sbit led=P2^0;      // assigninig led value to 8051 port2 0 bit
main()
{
	led=0;   // initial led state 0
	while(1)
	{
			led=1;
				delay(10);
			led=0;
				delay(10);
	}
	
}
void delay(unsigned int n)
{
	TMOD= 0x01;  // selecting timer0 mode1
	TH0=0xDC;    // hex value to generate 10 ms time delay
	TL0=0x00;
	TR0=1;       // timer 0 run 
	while(TF0==0); 
	TR0=0;				// timer 0 run bit off
	TF0=0;				//clear flag bit
}