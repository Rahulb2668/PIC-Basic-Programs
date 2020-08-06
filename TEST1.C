#include<pic18.h>
void delay()
{
for(int i=0;i<500;i++)
for(int j=0;j<500;j++);
}
void start()
{
 SEN=1;
 while(SSPIF==0);
 SSPIF=0;
}
void stop()
{
 PEN=1;
 while(SSPIF==0);
 SSPIF=0;
}
void write(int a)
{
 SSPBUF=a;
 while(SSPIF==0);
 SSPIF=0;
}
void main()
{
 TRISD=0X00;
 TRISC=0XFF;//ITS INPUT BECAUSE IT CHECKS SOMETHING FROM SLAVE
 SSPSTAT=0X80;
 SSPADD=0X31;
 SSPCON1=0X28;
LATD=0X00; 
while(1)
{

start();
write(0X32);
write(0XFF);
LATD=0XFF;
stop();
}
}

