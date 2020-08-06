#include<pic.h>
void delay()
{
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<1000;j++);
	}
	
void main()
{
	TRISB=0x02;
	TRISD=0x00;
	while(1)
	{
		if((PORTB&0x02)==0)
		{
			PORTB=0x01;
			PORTD=0xff;
			delay();
			}
		PORTB=0x00;
			}
}