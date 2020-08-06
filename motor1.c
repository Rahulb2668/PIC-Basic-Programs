#include<pic.h>
void delay()
{
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<1000;j++);
	}
void main()
{
	TRISB=0x00;
	TRISC=0xff;
	while(1)
	{
		if(RC0==1)
		{
			PORTB=0xff;
			delay();
			PORTB=0x00;
			delay();
			}
			}				