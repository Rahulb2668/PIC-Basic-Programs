#include<pic18.h>
void delay()
{
	int i,j;
	for(i=0;i<300;i++)
	for(j=0;j<300;j++);
}
void main()
{
	TRISC=0x00;
	while(1)
	{
		LATC=0xff;
		delay();
		LATC=0x00;
		delay();
		}
}		
		
			