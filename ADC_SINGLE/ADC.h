#include <stdio.h>
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_adc.h"
#include "delay.h"

uint32_t GPIOC15_gnd_connect(void);
void GPIO_toggeld_13(void);
void GPIOC_init_13_o (void);


void ADC_init(void);
unsigned int ADC_read(void);
