/*
 * Motor.c
 *
 * Created: 5/5/2018 8:49:13 PM
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

#define F_CPU 14745600

#include "Common_includes.h"
#include "Motor.h"

//Configure ports to enable robot's motion
void motion_pin_config (void)
 {
	DDRA = DDRA | 0x0F;
	PORTA = PORTA & 0xF0;
	DDRL = DDRL | 0x18;   //Setting PL3 and PL4 pins as output for PWM generation
	PORTL = PORTL | 0x18; //PL3 and PL4 pins are for velocity control using PWM.
 }

//Velocity control
void velocity (unsigned char left_motor, unsigned char right_motor)
 {
	OCR5AL = (unsigned char)left_motor;
	OCR5BL = (unsigned char)right_motor;
 }

//Setting motor's direction
void motion_set (unsigned char Direction)
 {
	unsigned char PortARestore = 0;

	Direction &= 0x0F; // removing upper nibble for the protection
	PortARestore = PORTA; // reading the PORTA original status
	PortARestore &= 0xF0; // making lower direction nibble to 0
	PortARestore |= Direction; // adding lower nibble for forward command and restoring the PORTA status
	PORTA = PortARestore; // executing the command
 }

//Set direction of motor as forward
void forward (unsigned char left_motor_pwm, unsigned char right_motor_pwm)
 {
	motion_set (0x06);
	velocity(left_motor_pwm,right_motor_pwm);
 }

void left (void) //Left wheel backward, Right wheel forward
 {
	motion_set(0x05);
 }

void right (void) //Left wheel forward, Right wheel backward
 {
	motion_set(0x0A);
 }

//Stop the motor

void stop (void)
 { 
	motion_set (0x00);
 }

//Function to make a 90 degree right turn
void right_degrees(unsigned int Degrees)
 {
	right(); 
	velocity(130,130);
 }