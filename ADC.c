#include<pic18.h>
void delay()
{ 
	int i,j;
	for(i=0;i<300;i++)
	for(j=0;j<300;j++);
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
			}
void display(char *p)
{
	while(*p!='\0')
	{
		data(*p);
		delay();
		p++;
		}
		}
void main()
{
	int d;
    char p,q,r;
	ADCON0=0x01;
	ADCON1=0x0E;
	ADCON2=0x80;
	TRISA=0x0f;
	TRISC=0x00;
	TRISD=0x00;
	cmd(0x38);
	cmd(0x01);
	cmd(0x80);
	cmd(0x06);
	cmd(0x0E);
	while(1)
	{
		GODONE=1;
		while(GODONE==1);
		d=ADRESH;
        		p=(d/100)+48;
		q=((d%100)/10)+48;
		r=(d%10)+48;
		display(&p);
		display(&q);
		display(&r);
		delay();
		cmd(0x01);
		}
		}
						