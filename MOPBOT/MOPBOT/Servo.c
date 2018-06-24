/*
 * Servo.c
 *
 * Created: 5/5/2018 8:51:25 PM
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

#define F_CPU 14745600

#include "Common_includes.h"
#include "Servo.h"

void servo_pin_config()
 {
	DDRB  = 0xE0;  //making PORTB 5,6,7 pin output
	PORTB = 0xE0; //setting PORTB 5 pin to logic 1
 }

//Function to move the base servo to specified degrees by converting it into appropriate timer values
void servo_1(unsigned char degrees1)
 {
	float PositionPanServo1 = 0;
	PositionPanServo1 = ((float)degrees1 * 0.5556) + 48.33;
	OCR1A = (uint16_t)PositionPanServo1;	
 }

//Function to move the right servo to specified degrees by converting it into appropriate timer values
void servo_2(unsigned char degrees2)
 {
	float PositionPanServo2 = 0;
	PositionPanServo2 = ((float)degrees2 * 0.5556) + 48.33;
	OCR1B = (uint16_t)PositionPanServo2;
 }

//Function to move the left servo to specified degrees by converting it into appropriate timer values
void servo_3(unsigned char degrees3)
 {
	float PositionPanServo3 = 0;
	PositionPanServo3 = ((float)degrees3 * 0.5556) + 48.33;
	OCR1C = (uint16_t)PositionPanServo3;	
 }