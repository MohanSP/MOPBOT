/*
 * Buzzer.c
 *
 * Created: 5/5/2018 8:51:02 PM
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

#define F_CPU 14745600

#include "Buzzer.h"
#include "Common_includes.h"

//Buzzer pin configuration
void buzzer_pin_config (void)
 {
	DDRC = DDRC | 0x08;		//Setting PORTC 3 as output
	PORTC = PORTC & 0xF7;	//Setting PORTC 3 logic low to turnoff buzzer
 }

//Switch on the buzzer
void buzzer_on (void)
 {
	unsigned char port_restore = 0;
	port_restore = PINC;
	port_restore = port_restore | 0x08;
	PORTC = port_restore;
 }

//Switch off the buzzer
void buzzer_off (void)
 {
	unsigned char port_restore = 0;
	port_restore = PINC;
	port_restore = port_restore & 0xF7;
	PORTC = port_restore;
 }