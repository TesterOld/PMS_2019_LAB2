#include "ADC.h"   
	//
	uint32_t GPIOC15_gnd_connect(void){
    if (!GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15))// Catch from GND 
		{//slow, press and connect GPIOC 13 to GND 
		 delay_ms(10);
         return 1;
		}
		else 
        {//fast no press !!!
        delay_ms(10);
        return 0;    
        }
		}

void GPIO_toggeld_13(void)
{
    /* Read LED output (GPIOA PIN8) status */
    uint8_t led_bit = GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_13);
     
    /* If LED output set, clear it */
    if(led_bit == (uint8_t)Bit_SET)
    {
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
    }
    /* If LED output clear, set it */
    else
    {
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
    }
}

void GPIOC_init_13_o (void){
	//to output for display
   GPIO_InitTypeDef GPIO_InitStructure;
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE); // (1)
   GPIO_StructInit (& GPIO_InitStructure);
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
   GPIO_Init(GPIOC , &GPIO_InitStructure); 
}
	
	//
void ADC_init(void)
{	
	__enable_irq();
	ADC_InitTypeDef ADC_InitStructure;
    GPIO_InitTypeDef  GPIO_InitStructure;
    // input of ADC (it doesn't seem to be needed, as default GPIO state is floating input)
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AIN;
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2 ;        // that's ADC2 (PA1 on STM32)
    GPIO_Init(GPIOA, &GPIO_InitStructure);
 
    //clock for ADC (max 14MHz --> 72/6=12MHz)
    RCC_ADCCLKConfig (RCC_PCLK2_Div6);
    // enable ADC system clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
 
    // define ADC config
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = ENABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;  // we work in continuous sampling mode
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 1;
 
    ADC_RegularChannelConfig(ADC1,ADC_Channel_2, 1,ADC_SampleTime_28Cycles5); // define regular conversion config
    ADC_Init ( ADC1, &ADC_InitStructure);   //set config of ADC2
 
    // enable ADC
    ADC_Cmd (ADC1,ENABLE);  //enable ADC2
 
    //  ADC calibration (optional, but recommended at power on)
    ADC_ResetCalibration(ADC1); // Reset previous calibration
    while(ADC_GetResetCalibrationStatus(ADC1));
    ADC_StartCalibration(ADC1); // Start new calibration (ADC must be off at that time)
    while(ADC_GetCalibrationStatus(ADC1));
 
    // start conversion
    ADC_Cmd (ADC1,ENABLE);  //enable ADC1
    ADC_SoftwareStartConvCmd(ADC1, ENABLE); 
}

unsigned int ADC_read()
{
	delay_ms(10);
	return ADC_GetConversionValue(ADC1);
	delay_ms(10);
}
