
#include "stm32f10x.h"                  // Device header

void delayMs(volatile int delay);

int main (void){
	
	RCC->APB2ENR |= 4;
	GPIOA->CRL &= 0x0;
	GPIOA->CRL |= 0x300000;
	
	//0000 0000 0000 0000 0000 0000 0010 0000=0x20//Set PA5
	//0000 0000 0010 0000 0000 0000 0000 0000=0x200000//Reset PA5
	while(1)
	{
	 GPIOA->BSRR=0x20;//here we set PA5
	 delayMs(5000000);
	 GPIOA->BSRR=0x200000;//here PA5 is reset
	 delayMs(5000000);
	}
	
}

void delayMs(volatile int delay){
	int i;
	for(;delay>0;delay--){
		for(i=0;i<3195;i++){}
	}
}
