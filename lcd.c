#include <reg51.h>
#include "DELAY.H"
#define lcd P0
sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P1^2;
int n;
void init_lcd();
void cmd_lcd(unsigned char);
void data_lcd(unsigned char);
void write_lcd(unsigned char);

main()
{
	lcd_init();
	lcd_data('V');
	delay_ms(100);\
}


void init_lcd()
{
	cmd_lcd(0x38);    // lcd 8 bit mode
	cmd_lcd(0x01);   //clear screen
	cmd_lcd(0x0c);   // display on cursur off
	cmd_lcd(0x06);   // shift left or right
	cmd_lcd(0x80);   // starting from the first position
	
}

void cmd_lcd(unsigned char ch)
{
	RS=0;     // lcd command mode
	write_lcd(ch); 
}
void data_lcd(unsigned char ch)
{
	RS=1;    // lcd data mode
	write_lcd(ch);
}

void write_lcd(unsigned char ch)
{
	lcd=ch;
	RW=0;
	EN=1;
	delay_ms(2);
	EN=0;
}

