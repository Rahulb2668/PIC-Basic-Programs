#include<pic18.h>
void delay()
{
 for(int i=0;i<500;i++)
for(int j=0;j<500;j++);
}
void main()
{ char b;
  TRISC=0XbF;
  SPBRG=129;
  TXSTA=0X24;
  RCSTA=0X80;
  SSPSTAT=0X80;
SSPADD=0X32;
  SSPCON1=0X26;
while(1)
{
while(SSPIF==0);
b=SSPBUF;
TXREG=b;
while(TXIF==0);
SSPIF=0;
delay();
}
}