/*
 * ADC.c
 *
 * Created: 5/5/2018 8:36:00 PM
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

#define F_CPU 14745600

#include "ADC.h"
#include "Common_includes.h"

//Initialize the ADC
void adc_init()
 {
	ADCSRA = 0x00;
	ADCSRB = 0x00;		//MUX5 = 0
	ADMUX = 0x20;		//Vref=5V external --- ADLAR=1 --- MUX4:0 = 0000
	ACSR = 0x80;
	ADCSRA = 0x86;		//ADEN=1 --- ADIE=1 --- ADPS2:0 = 1 1 0
 }

//ADC pin configuration

void adc_pin_config (void)
 {
	DDRF = 0x00;
	PORTF = 0x00;
	DDRK = 0x00;
	PORTK = 0x00;
 }

//Convert the output voltage to ADC value

unsigned char ADC_Conversion(unsigned char Ch)
 {
	unsigned char a;
	
	if(Ch>7)
     {
		ADCSRB = 0x08;
	 }
	 
	Ch = Ch & 0x07;
	ADMUX= 0x20| Ch;
	ADCSRA = ADCSRA | 0x40;		//Set start conversion bit
	
	while((ADCSRA&0x10)==0);	//Wait for conversion to complete

	a=ADCH;
	ADCSRA = ADCSRA|0x10; //clear ADIF (ADC Interrupt Flag) by writing 1 to it
	ADCSRB = 0x00;

	return a;
 }