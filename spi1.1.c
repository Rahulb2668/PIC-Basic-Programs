#include<pic18.h>
void delay()
{
	for(int i=0;i<100;i++)
	for(int j=0;j<200;j++);
	}

 
void main()
{    
     char c;
     SPBRG=129;
	 TXSTA=0X24;
	 RCSTA=0X80;
	 ADCON1=0X0F;
     TRISA=0XFF;
     TRISC=0X98;
     SSPSTAT=0X00;
	 SSPCON1=0X24;
     while(SSPIF==0);
     c=SSPBUF;
      delay();
     TXREG=c;
     while(TXIF==0);
}
