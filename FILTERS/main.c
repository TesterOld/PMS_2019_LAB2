#include "filters.h"
#include "delay.h"
#include "tm1637.h"
#include "stdio.h"
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_adc.h"
#include "delay.h"
#include "stm32f10x_tim.h"
#define BUFFER_SIZE 8
#define FILTER_ARITY 16

unsigned int digit_display0 = 0;
struct Buffer buf;
int array[8]={1050,1240,1330,1320,1210,1000,990,1180};
int main()
{
	delay_ms(10);
	TM1637_init();
	TM1637_brightness(BRIGHT_TYPICAL);
	delay_ms(10);
	TM1637_display_all(digit_display0);
	delay_ms(1000);
	buf = cbuf_new(BUFFER_SIZE);
	
	TIM_TimeBaseInitTypeDef TIMER_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
 
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	/*seed n initial values into buffer*/

	for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++){
		cbuf_write(&buf, array[i]);
		cbuf_read(&buf);
		delay_ms(5);
	}
	
	int filter_val = 0;

	while (1)
	{ 
		filter_val = A_term_filter(&buf);
		TM1637_display_all(filter_val);
		cbuf_read(&buf);
		delay_ms(1000);
		
		filter_val = B_term_filter(&buf);
		TM1637_display_all(filter_val);
		cbuf_read(&buf);
		delay_ms(1000);
		
		filter_val = C_term_filter(&buf);
		TM1637_display_all(filter_val);
		cbuf_read(&buf);
		delay_ms(1000);
	}
}
