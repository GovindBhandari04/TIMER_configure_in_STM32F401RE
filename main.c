#include <stm32f4xx.h>

void Timer10_congif()
{
	RCC -> APB2ENR |= (1U<<17);
	TIM10 -> PSC |= 84000-1;
	TIM10 -> ARR |= 1000-1;
	TIM10 -> CR1 |= (1U<<0);
	while(!(TIM10 -> SR & (1U<<0)));
}

void Timer10_GPIO()
{
	RCC -> AHB1ENR |= (1U<<2);
	GPIOC -> MODER |= (1U<<8);
	GPIOC -> OTYPER |= (1U<<4);
	GPIOC -> OSPEEDR |= (1U<<8)|(1U<<9);
	GPIOC -> PUPDR &= ~(1U<<8) & ~(1U<<9);
}

void Timer10_delay()
{
	for(int i=0;i<100000;i++)
	{}
}

int main()
{
	Timer10_congif();
	Timer10_GPIO();

	while(1)
	{
		GPIOC -> BSRR = (1U<<4);
		Timer10_delay();
		GPIOC -> BSRR = (1U<<20);
		Timer10_delay();
	}
}
