#include<pic18.h>
void delay()
{
	for(int i=0;i<1000;i++)
	for(int j=0;j<300;j++);
	}
void cmd(int a)
{
	LATD=a;
	LATC0=0;
	LATC1=1;
	delay();
	LATC1=0;
	}
void data(char b)
{
	LATD=b;
	LATC0=1;
	LATC1=1;
	delay();
	LATC1=0;
	delay();
	cmd(0x01);
	delay();
	}	
void main()
{
	int e;
	//ADCON1=0x0f;
	//TRISA=0x00;
	TRISB=0xf0;
	TRISC=0x00;
	TRISD=0x00;
	cmd(0x38);
	cmd(0x01);
	cmd(0x80);
	cmd(0x06);
	cmd(0x0e);
	while(1)
	{
		LATB=0xfE;
		e=PORTB&0xf0;
		switch(e)
		{
			case(0xE0):data('1');break;
			case(0xD0):data('2');break;
			case(0xB0):data('3');break;
			case(0x70):data('4');break;
	
		  }
//		  LATD=0xbf;
//		  e=PORTD&0x0f;
//		  switch(e)
//		  {
//			  case(0x07):data('5');break;
//			  case(0x0b):data('6');break;
//			  case(0x0d):data('7');break;
//			  case(0x0e):data('8');break;
//			  }
//		  LATD=0xDf;
//		  e=PORTD&0x0f;
//		  switch(e)
//		  {
//			  case(0x07):data('9');break;
//			  case(0x0b):data('A');break;
//			  case(0x0d):data('B');break;
//			  case(0x0e):data('C');break;
//			  }
			  }
}	  	