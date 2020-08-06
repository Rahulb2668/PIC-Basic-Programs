#include<pic.h>
void delay(int i)
{
	int a,b;
	for(a=0;a<i;a++)
	for(b=0;b<i;b++);
	}
void main()
{
	int i=0; 
	unsigned int seg[]={0x3f,0x06,0x5B,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
TRISB=0x00;
TRISC=0x00;
while(1)
	{
	PORTC=0x01;
for(i=0;i<8;i++)
{

	PORTB=seg[i];
	delay(500);
}	
	}
}		