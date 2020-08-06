#include<pic18.h>
void delay()
{
	for(int i=0;i<500;i++)
	for(int j=0;j<500;j++);
	}
void main()
{
	TXSTA=0X24;
	RCSTA=0X80;
	SPBRG=129;
	TXREG='A';
	while(TXIF==0);
	}
		