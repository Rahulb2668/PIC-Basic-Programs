#include<pic18.h>
void delay()
{
 for(int i=0;i<1000;i++)
for(int j=0;j<500;j++);
}
void main()
{ char b;
  SSPSTAT=0X80;
  SSPADD=0X32;
  SSPCON1=0X36;
  TRISC=0XbF;
  SPBRG=129;
  TXSTA=0X24;
  RCSTA=0X80;
while(1)
{
while(SSPIF==0);
b=SSPBUF;
SSPIF=0;//evanayirunu prasnakaaran... 
delay();
TXREG=b;
while(TXIF==0);

delay();
}
}