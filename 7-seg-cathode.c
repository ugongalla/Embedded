#include <reg51.h>
#include "DELAY.H"

main()
{
	unsigned int i;
	unsigned char a[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	P2=0x00;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			P2 = a[i];
			delay_ms(10);
		}
	}
}