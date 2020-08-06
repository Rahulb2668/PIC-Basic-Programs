#include<pic18.h>
char rec()
{
    while(RCIF==0);
	return(RCREG);
	}
void trans(char b)
{
	while(b!='#')
	{
		TXREG=b;
		while(TXIF==0);
		TXIF=0;
		b=rec();
		}
	}
void main()
{
	char d;
//	TRISC=0x80;
	TXSTA=0x24;
	RCSTA=0x90;
	SPBRG=129;
	d=rec();

	if(d=='*')
	{    d=rec();
          //for(int i=0;i<1000;i++);
		trans(d);
	}
	}			
			