#include<pic18.h>
void delay(int a,int b)
{
	for(int i=0;i<a;i++)
	for(int j=0;j<b;j++);
	}
void main()
{  static const char a[]="hello"; 
    TRISC=0X10;//CLK AND SDO O/P,SDI INPUT 
	TRISD=0x00;
    LATD0=0;//SS PIN MADE AS 0
	SSPSTAT=0x00;
	SSPCON1=0x20;
for(int i=0;a[i]!='\0';i++)
{ 
	SSPBUF=a[i];
	while(SSPIF==0);
delay(100,150);
}
}
		