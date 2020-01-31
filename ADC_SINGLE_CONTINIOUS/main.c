#include "buffer.h"
#include "delay.h"
#include "ADC.h"
#include "tm1637.h"
#include "stdio.h"
#define BUFFER_SIZE 64

unsigned int digit_display0 = 0;

int main()
{
	ADC_init();
	delay_ms(10);
	TM1637_init();
	TM1637_brightness(BRIGHT_TYPICAL);
	delay_ms(10);
	TM1637_display_all(digit_display0);
	delay_ms(1000);

	struct Buffer buf = cbuf_new(BUFFER_SIZE);

	while (1)
	{
		cbuf_write(&buf, ADC_read());
		delay_ms(10);
		TM1637_display_all(cbuf_avg(&buf));
		delay_ms(100);
	}
}
