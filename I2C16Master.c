#include<pic.h>
void delay(int a)
{
	int i,j;
	for(i = 0;i<a;i++)
	for(j=0;j<a;j++);
	}
void I2C_Write(char data)
{
	SSPBUF=data;
	while(!SSPIF);
	SSPIF=0;
	}
void start_i2c()
{
	SEN=1;
	while(SEN);
	SSPIF=0;
}	
void I2C_stop()
{
	PEN=1;
	while(!SSPIF);
	SSPIF=0;
	}
	
void main()
{
	TRISC=0xFF;
	SSPSTAT=0x80;
	SSPCON=0x28;
	SSPADD=0x31;
	start_i2c();
	delay(100);
	I2C_Write(0x10);
	delay(100);
	I2C_Write('g');
	delay(100);
	I2C_stop();
	delay(100);
	}
	
	