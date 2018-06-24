/*
 * Encoder.c
 *
 * Created: 5/5/2018 8:50:31 PM
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

#define F_CPU 14745600

#include "Common_includes.h"
#include "Encoder.h"

//Function to configure INT4 (PORTE 4) pin as input for the left position encoder
void left_encoder_pin_config()
{
	DDRE  = DDRE & 0xEF;  //Set the direction of the PORTE 4 pin as input
	PORTE = PORTE | 0x10; //Enable internal pull-up for PORTE 4 pin
}

//Function to configure INT5 (PORTE 5) pin as input for the right position encoder
void right_encoder_pin_config()
{
	DDRE  = DDRE & 0xDF;  //Set the direction of the PORTE 4 pin as input
	PORTE = PORTE | 0x20; //Enable internal pull-up for PORTE 4 pin
}

void left_position_encoder_interrupt_init() //Interrupt 4 enable
{
//	cli(); //Clears the global interrupt
//	EICRB = EICRB | 0x02; // INT4 is set to trigger with falling edge
//	EIMSK = EIMSK | 0x10; // Enable Interrupt INT4 for left position encoder
//	sei();   // Enables the global interrupt
}

void right_position_encoder_interrupt_init() //Interrupt 5 enable
{
//	cli(); //Clears the global interrupt
//	EICRB = EICRB | 0x08; // INT5 is set to trigger with falling edge
//	EIMSK = EIMSK | 0x20; // Enable Interrupt INT5 for right position encoder
//	sei();   // Enables the global interrupt
}

