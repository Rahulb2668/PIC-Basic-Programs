/*fOSC=20MHz
FCPU=FOSC/4=5MHZ       
FCPU= INSTRUCTION CYCLE FREQUENCY
FOSC= OSCILLATOR FREQUENCY OF THE OCILLATOR

TMROIF flags sets when the TMR0 reg overflows from 255 to 0
so timer operating frequency=FCPU/prescaler
here, 

Timer Frequency= 5Mhz/64=78125Hz

so time for one cycle=1/78125=12.8microseconds

so no of counts in 1 second= 1/12.8=78125 counts

so we are initialising a count variable such that for 78125 counts TMR0 have to reset 78125/255=306

so when count =306, it is 1 second;*/
#include<pic18.h>
void main()
{
	int count=0;
	TRISD=0x00;
	T0CON=0xC5;//timer0 enabled/8 bit config/internal clk/low to high transition/prescaler assigned/1:64
	TMR0=0x00;// COUNT STARTS FROM 0
	while(1)
	{
		while(TMR0IF==0);// FLAG SETS WHEN TMR0 REACHES 255 ie, WHEN TMR0 OVER FLOWS
		TMR0IF=0;//RESETING FLAG
		count=count+1;
		if(count==306)//
		{
			LATD=~PORTD;
			count=0;
		}
	 }
}
			
		
	