
//PA5// I choose to use bits 23,22,21,20 from GPIOA_CRL
//APB2 Bus connected to GPIOA
//RCC->APB2ENR register APB2ENR is responsible for enabling peripherals connected to APB2 Bus
//GPIOx_CRL since we're using pin A5 from BluePill(Port A bit 5) we need to use the controls for the low registers (check the reference manual).
//GPIOx_ODR register responsible for setting output states of bits in Port A
#include "stm32f10x.h"    // Device header
void delayMs(volatile int delay);
int main(void)
{
	RCC->APB2ENR |=0x4 ;//IOPAEN page 113, the signal "|=" is the same as "x =x|y (x equals x OR y)" 
	GPIOA->CRL = 0x0;
	GPIOA->CRL |= 0x300000;
	//0000  0000  0011 0000   0000  0000  0000   0000=0x300000 here we're selecting the conditions for our output see page 170 form the reference manual  
     	
	while(1){
	GPIOA->ODR =0x20;
	//0000 0000 0000   0000
	//  0   0   0010     0=0020=0x20
	delayMs(5000000);//aprox.1 second delay, later we can use timers to do this precisely
	GPIOA->ODR &= 0x0000FFDF;//This makes an AND operation between the current value of the register and 0x0000FFDF
		                       //which in binary means" all bits as 1 except bit 5" .
	delayMs(5000000);          
	}
	
}
//just or function fpr
void delayMs(volatile int delay){
	volatile int i=0;
		for(i=0;i<=delay;i++){
			}
}



