#include<pic18.h>
void delay()
{
	for(int i=0;i<500;i++)
	for(int j=0;j<500;j++);
}
void cmd(int a)
{
 LATD=a;
 LATA0=0;
 LATA1=1;
 delay();
 LATA1=0;
 }
 	
void data(char b)
{
	LATD=b;
	LATA0=1;
	LATA1=1;
	delay();
	LATA1=0;
	}
	
/*void display(char *p)
{
	while(*p!='\0')
	{
	  data(*p);
	  p++;
	  }
 }*/
 void main()
 {   //ADCON1=0x0f;
	 //TRISA=0x00;
	 TRISB=0xff;
	 //TRISC=0x00;
	 TRISD=0x00;
	/* cmd(0x38);
	 cmd(0x01);
	 cmd(0x80);
	 cmd(0x06);
	 cmd(0x0E);*/
	 
	 if(RB0==1)
	   {
		 LATC=0x65;
		// display("forward");
		 delay();
		 }
	else if(RB1==1)
		{
			LATC=0xA6;
			//display("REverse");
			delay();
			}
	else if(RB2==1)
	   {
		   LATC=0x00;
		   //display("stop");
		   delay();
		  } 
}		  		
			 
		 
	  	
		