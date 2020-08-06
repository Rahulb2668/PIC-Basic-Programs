#include<pic.h>
void delay(int i)
{
	int a,b;
	for(a=0;a<i;a++)
	for(b=0;b<i;b++);
	}
void trans(char a)
{
	TXREG=a;
	while(TXIF==0);
	TXIF=0;
	}	
	
char key()
{
	while(1)
	{
		int e;
		PORTB=0x7F;
		e=PORTB&0x0f;
		switch(e)
		{
			case(0x07):return('1');
			case(0x0B):return('2');
			case(0x0D):return('3');
			case(0x0E):return('4');
			}
	}
}
void main()
{
	int i=0,count=0;
	char a[]="1234";
	char b[4];
	RBPU=0;
	TRISB=0x0f;
	TRISC=0x80;
	TRISD=0x00;
	TXSTA=0x24;
	RCSTA=0x90;
    SPBRG=64;
	PORTD=0x00;
while(1)
{
  for(;i<4;i++)
	{
		b[i]=key();
		trans(b[i]);
		delay(400);
		}
  for(i=0;i<4;i++)
     {
	   if(a[i]==b[i])
	   { 
	    count++;
	   }
	 }
  if(count==4)
    {
	  trans('C');
		PORTD=0x01;
		delay(500);
		  }
  else 
	{
	  trans('w');
		PORTD=0x10;
		delay(500);
		  }
break;
	
}	
}		