#include <reg51.h>
#include " DELAY.H"
// common anode Design
main()
{
	unsigned char i;
	unsigned char arr[10]={0xc0, 0xf9, 0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
	P2=0x00;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			P2=arr[i];
			delay_ms(100);
		}
	}
}
