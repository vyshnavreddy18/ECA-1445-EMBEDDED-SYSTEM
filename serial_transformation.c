#include <lpc214x.h>

void UART0_Init(void)
{
 PLL0CON = 0;
 PLL0FEED=0xAA;
 PLL0FEED=0x55;
 VPBDIV = 1;
 PINSEL0 |= 0x5; 
 U0FCR = 0; 
 U0LCR = 0x83; 
 U0DLL = 0x27; 
 U0DLM = 0;
 U0LCR = 3; 
}
void sout(unsigned char dat1)
{
 while(!(U0LSR & 0x20));
 U0THR = dat1;   
}
int main (void)
{  int dat; 
   UART0_Init();
 do
  { 
   if(U0LSR & 1)  	
    {
       dat = U0RBR;
       sout(dat);  
	}
   }while(1);
}
