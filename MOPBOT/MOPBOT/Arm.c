/*
 * Arm.c
 *
 * Created: 5/5/2018 8:52:33 PM
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

#define F_CPU 14745600

#include "Common_includes.h"
#include "Angle_fix_DH.h"
#include "Arm.h"
#include "LCD.h"
#include "Servo.h"

int degrees1=0, degrees2=0, degrees3=0;

//Function to obtain linear motion in z for 5 cm
void arm_z_linear()
 {
	degrees1=angle_fix(-56, -30, 81, 1);
	degrees2=angle_fix(-56, -30, 81, 2);
	degrees3=angle_fix(-56, -30, 81, 3);

	servo_1(degrees1);
	servo_2(degrees2);
	servo_3(degrees3);

	_delay_ms(100);

	degrees1=angle_fix(-56, -35, 82, 1);
	degrees2=angle_fix(-56, -35, 82, 2);
	degrees3=angle_fix(-56, -35, 82, 3);

	servo_1(degrees1);
	servo_2(degrees2);
	servo_3(degrees3);

	_delay_ms(100);
	
	degrees1=angle_fix(-56, -40, 83, 1);
	degrees2=angle_fix(-56, -40, 83, 2);
	degrees3=angle_fix(-56, -40, 83, 3);

	servo_1(degrees1);
	servo_2(degrees2);
	servo_3(degrees3);

	_delay_ms(100);
	
	degrees1=angle_fix(-56, -44, 82, 1);
	degrees2=angle_fix(-56, -44, 82, 2);
	degrees3=angle_fix(-56, -44, 82, 3);
	
	servo_1(degrees1);
	servo_2(degrees2);
	servo_3(degrees3);

	_delay_ms(100);
	
	degrees1=angle_fix(-56, -48, 81, 1);
	degrees2=angle_fix(-56, -48, 81, 2);
	degrees3=angle_fix(-56, -48, 81, 3);
	
	servo_1(degrees1);
	servo_2(degrees2);
	servo_3(degrees3);

	_delay_ms(100);

	degrees1=angle_fix(-56, -44, 82, 1);
	degrees2=angle_fix(-56, -44, 82, 2);
	degrees3=angle_fix(-56, -44, 82, 3);
	
	servo_1(degrees1);
	servo_2(degrees2);
	servo_3(degrees3);

	_delay_ms(100);	
	
	degrees1=angle_fix(-56, -40, 83, 1);
	degrees2=angle_fix(-56, -40, 83, 2);
	degrees3=angle_fix(-56, -40, 83, 3);

	servo_1(degrees1);
	servo_2(degrees2);
	servo_3(degrees3);

	_delay_ms(100);

	degrees1=angle_fix(-56, -35, 82, 1);
	degrees2=angle_fix(-56, -35, 82, 2);
	degrees3=angle_fix(-56, -35, 82, 3);

	servo_1(degrees1);
	servo_2(degrees2);
	servo_3(degrees3);

	_delay_ms(100);
	
	degrees1=angle_fix(-56, -30, 81, 1);
	degrees2=angle_fix(-56, -30, 81, 2);
	degrees3=angle_fix(-56, -30, 81, 3);

	servo_1(degrees1);
	servo_2(degrees2);
	servo_3(degrees3);

	_delay_ms(100);			
 }
 
 //Function to obtain linear motion in y for 5 cm
 void arm_y_linear()
  {
	degrees1=angle_fix(-44, -65, 140, 1);
	degrees2=angle_fix(-44, -65, 140, 2);
	degrees3=angle_fix(-44, -65, 140, 3);

	servo_1(degrees1);
	servo_2(degrees2+20);
	servo_3(degrees3-20);

	lcd_print(1, 1, degrees1, 3);
	lcd_print(1, 5, degrees2, 3);
	lcd_print(1, 9, degrees3, 3);
			
	_delay_ms(100);

	degrees1=angle_fix(-38, -66, 143, 1);
	degrees2=angle_fix(-38, -66, 143, 2);
	degrees3=angle_fix(-38, -66, 143, 3);

	servo_1(degrees1);
	servo_2(degrees2+20);
	servo_3(degrees3-20);

	lcd_print(1, 1, degrees1, 3);
	lcd_print(1, 5, degrees2, 3);
	lcd_print(1, 9, degrees3, 3);
	
	_delay_ms(100);
	
	degrees1=angle_fix(-31, -67, 145, 1);
	degrees2=angle_fix(-31, -67, 145, 2);
	degrees3=angle_fix(-31, -67, 145, 3);

	servo_1(degrees1);
	servo_2(degrees2+20);
	servo_3(degrees3-20);

	lcd_print(1, 1, degrees1, 3);
	lcd_print(1, 5, degrees2, 3);
	lcd_print(1, 9, degrees3, 3);
	
	_delay_ms(100);
	
	degrees1=angle_fix(-23, -67, 145, 1);
	degrees2=angle_fix(-23, -67, 145, 2);
	degrees3=angle_fix(-23, -67, 145, 3);
	
	servo_1(degrees1);
	servo_2(degrees2+20);
	servo_3(degrees3-20);

	lcd_print(1, 1, degrees1, 3);
	lcd_print(1, 5, degrees2, 3);
	lcd_print(1, 9, degrees3, 3);
	
	_delay_ms(100);
	
	degrees1=angle_fix(-14, -67, 145, 1);
	degrees2=angle_fix(-14, -67, 145, 2);
	degrees3=angle_fix(-14, -67, 145, 3);
	
	servo_1(degrees1);
	servo_2(degrees2+20);
	servo_3(degrees3-20);

	lcd_print(1, 1, degrees1, 3);
	lcd_print(1, 5, degrees2, 3);
	lcd_print(1, 9, degrees3, 3);
	
	_delay_ms(100);
	
	degrees1=angle_fix(-6, -66, 143, 1);
	degrees2=angle_fix(-6, -66, 143, 2);
	degrees3=angle_fix(-6, -66, 143, 3);

	servo_1(degrees1);
	servo_2(degrees2+20);
	servo_3(degrees3-20);

	lcd_print(1, 1, degrees1, 3);
	lcd_print(1, 5, degrees2, 3);
	lcd_print(1, 9, degrees3, 3);
	
	_delay_ms(100);

	degrees1=angle_fix(2, -65, 140, 1);
	degrees2=angle_fix(2, -65, 140, 2);
	degrees3=angle_fix(2, -65, 140, 3);

	servo_1(degrees1);
	servo_2(degrees2+20);
	servo_3(degrees3-20);

	lcd_print(1, 1, degrees1, 3);
	lcd_print(1, 5, degrees2, 3);
	lcd_print(1, 9, degrees3, 3);
	
	_delay_ms(100);
	
	degrees1=angle_fix(-6, -66, 143, 1);
	degrees2=angle_fix(-6, -66, 143, 2);
	degrees3=angle_fix(-6, -66, 143, 3);

	servo_1(degrees1);
	servo_2(degrees2+20);
	servo_3(degrees3-20);

	lcd_print(1, 1, degrees1, 3);
	lcd_print(1, 5, degrees2, 3);
	lcd_print(1, 9, degrees3, 3);
	
	_delay_ms(100);
	
	degrees1=angle_fix(-14, -67, 145, 1);
	degrees2=angle_fix(-14, -67, 145, 2);
	degrees3=angle_fix(-14, -67, 145, 3);
	
	servo_1(degrees1);
	servo_2(degrees2+20);
	servo_3(degrees3-20);

	lcd_print(1, 1, degrees1, 3);
	lcd_print(1, 5, degrees2, 3);
	lcd_print(1, 9, degrees3, 3);
	
	_delay_ms(100);
	
	degrees1=angle_fix(-23, -67, 145, 1);
	degrees2=angle_fix(-23, -67, 145, 2);
	degrees3=angle_fix(-23, -67, 145, 3);
	
	servo_1(degrees1);
	servo_2(degrees2+20);
	servo_3(degrees3-20);

	lcd_print(1, 1, degrees1, 3);
	lcd_print(1, 5, degrees2, 3);
	lcd_print(1, 9, degrees3, 3);
	
	_delay_ms(100);

	degrees1=angle_fix(-31, -67, 145, 1);
	degrees2=angle_fix(-31, -67, 145, 2);
	degrees3=angle_fix(-31, -67, 145, 3);

	servo_1(degrees1);
	servo_2(degrees2+20);
	servo_3(degrees3-20);

	lcd_print(1, 1, degrees1, 3);
	lcd_print(1, 5, degrees2, 3);
	lcd_print(1, 9, degrees3, 3);
	
	_delay_ms(100);
	
	degrees1=angle_fix(-38, -66, 143, 1);
	degrees2=angle_fix(-38, -66, 143, 2);
	degrees3=angle_fix(-38, -66, 143, 3);

	servo_1(degrees1);
	servo_2(degrees2+20);
	servo_3(degrees3-20);

	lcd_print(1, 1, degrees1, 3);
	lcd_print(1, 5, degrees2, 3);
	lcd_print(1, 9, degrees3, 3);
	
	_delay_ms(100);
	
	degrees1=angle_fix(-44, -65, 140, 1);
	degrees2=angle_fix(-44, -65, 140, 2);
	degrees3=angle_fix(-44, -65, 140, 3);

	servo_1(degrees1);
	servo_2(degrees2+20);
	servo_3(degrees3-20);

	lcd_print(1, 1, degrees1, 3);
	lcd_print(1, 5, degrees2, 3);
	lcd_print(1, 9, degrees3, 3);
	
	_delay_ms(100);						
  }
