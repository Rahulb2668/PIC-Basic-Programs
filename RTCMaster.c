#include<pic.h>
void delay(int a)  // Function for creating delay 
{
	int i,j;
	for(i = 0;i<a;i++)
	for(j=0;j<a;j++);
	}
void I2C_Ack()
{
    ACKDT=0;		/* Acknowledge data 1:NACK,0:ACK */
    ACKEN=1;		/* Enable ACK to send */
    while(ACKEN);
 }
void I2C_Nack()
{
    ACKDT=1;		/* Acknowledge data 1:NACK,0:ACK */
    ACKEN=1;		/* Enable ACK to send */
    while(ACKEN);
}
void I2C_Write(char data)
{	
	SSPIF=0;
	SSPBUF=data;
	while(!SSPIF);

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
char I2C_read()
{	
	RCEN=1;
	char rec;
    while(RCEN);	
    rec=SSPBUF;
	SSPIF=0;
	return(rec);
}
void I2C_stopread()
{
	I2C_Nack();
		}
void trans(int b)
{
	TXREG=((b/16)+48);  // This is a BCD so this will give MSb
	while(TXIF==0);
	TXIF=0;
	TXREG=((b%16)+48);// This will give LSB
	while(TXIF==0);
	TXIF=0;
	}
void transsep()
{
	TXREG=':';
	while(TXIF==0);
	TXIF=0;
}
	
void main()
{
	int secs,mins,hours;
	TRISC=0x98;
	SSPSTAT=0x80;
	SSPCON=0x28;
	SSPADD=0x31;
	TXSTA=0x24;
	RCSTA=0x80;
	SPBRG=129;
	start_i2c();
	delay(100);
	I2C_Write(0xD0);
	I2C_Write(0x00);
	I2C_Write(0x20);
	I2C_Write(0x30);
	I2C_Write(0x46);
	delay(200);
	I2C_stop();
    delay(200);
while(1)
{
	start_i2c();
	I2C_Write(0xD0);
	I2C_Write(0x00);
	RSEN=1;
	while(RSEN);
	I2C_Write(0xD1);
	secs = (I2C_read());
	I2C_Ack();
	secs = secs & 0x7f;
	delay(200);
	mins = (I2C_read());
	I2C_Ack(); 
	mins = mins &0x7f;
	delay(200);
	hours = (I2C_read()); 
	I2C_stopread();
	I2C_stop();
	delay(200);
	hours = hours & 0x3f;
	trans(hours);
	transsep();
	delay(200);
	trans(mins);
	transsep();
	delay(200);
	trans(secs);
	delay(1000);
	}
}	