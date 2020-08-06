#include<pic.h>
void delay(int a)
{
	int i,j;
	for(i = 0;i<a;i++)
	for(j=0;j<a;j++);
	}

void main()
{
	char rec;
	TRISC=0x98;
	SSPSTAT=0x80;
	SSPCON=0x36;
	SSPADD=0x10;
	TXSTA=0x24;
	RCSTA=0x80;
	SPBRG=129;
	while(SSPIF==0);
	rec = SSPBUF;
	SSPIF=0;
	delay(100);
	TXREG=rec;
	while(TXIF==0);
	TXIF=0;
	}
	
	
	