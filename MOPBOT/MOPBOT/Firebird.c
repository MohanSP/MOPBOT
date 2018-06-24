/*
 * Firebird.c
 *
 * Created: 5/5/2018 8:52:11 PM
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

#define F_CPU 14745600

#include "ADC.h"
#include "Buzzer.h"
#include "Common_includes.h"
#include "Firebird.h"
#include "LCD.h"
#include "Motor.h"
#include "Servo.h"
#include "Timers.h"
#include "Ultrasound.h"

//Configure all the required ports
void port_init()
 {
	lcd_port_config();
	adc_pin_config();
	motion_pin_config();
	buzzer_pin_config();
	ultrasound_config();
	servo_pin_config();
 }

//Initialaize all the necessary devices
void init_devices (void)
 {
	cli(); //Clears the global interrupts
	port_init();
	adc_init();
	timer1_init();
	timer4_init();
	timer5_init();
	lcd_init();
	sei();   //Enables the global interrupts
 } 