/*
 * MOPBOT.c
 *
 * Created: 5/5/2018 8:53:15 PM
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

#define F_CPU 14745600

#include "Arm.h"
#include "Common_includes.h"
#include "Firebird.h"
#include "LCD.h"
#include "Motor.h"
#include "Timers.h"
#include "ADC.h"
#include "Buzzer.h"
#include "Ultrasound.h"
#include "PID.h"
#include "SharpIR.h"
#include "Servo.h"
#include "Angle_fix_DH.h"

	int setpoint=20, filtered_distanceF=0;
	double filtered_distanceL_US1=0, filtered_distanceL_US2=0;
	int base=100, offset=4, correction=0, true_distance=0, turn_count=1, turn_distance_max=25, turn_distance_min=5, skirting_flag=1;



int main(void)
 {
 	init_devices(); //Initialize various devices on Firebird

	while(1)
	 {	
		filtered_distanceF= distance_IRF();
		filtered_distanceL_US1= distance1_us();
		filtered_distanceL_US2= distance2_us();	
			
		true_distance= fmin(filtered_distanceL_US1,filtered_distanceL_US2);
		forward(base+correction,base-offset);
		correction=pid_speed_control(setpoint,true_distance);

		if (filtered_distanceF < turn_distance_max && filtered_distanceF > turn_distance_min)
		{
			right_degrees(90);
			_delay_ms(500);
			turn_count++;
		}
		
		if (turn_count==4 && setpoint<55)
		{  skirting_flag=0;
			turn_count=1;
			setpoint+=5;
			turn_distance_max+=5;
			turn_distance_min+=5;
		}
		
		if (skirting_flag==1)
		 {
			arm_z_linear();
		 }
				
		else
		 {
			 arm_y_linear();
		 }		
	 }
 }
 
 