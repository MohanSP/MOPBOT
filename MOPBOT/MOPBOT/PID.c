/*
 * PID.c
 *
 * Created: 5/5/2018 8:44:58 PM
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

#define F_CPU 14745600

#include "Common_includes.h"
#include "PID.h"

int pid_speed_control(int setpoint, int process_variable)
 {
	//The goal of this module is to maintain the orientation of the robot by controlling only the right motor, marginally speeding it up
	//or slowing it down as required.
		int error=0, correction =0, kp=2;
		error=setpoint-process_variable;

		//Note that is error > 1 then robot is moving away from the wall, if less than 1 then it is moving towards it.
		
		if (error > 1 || error < -1)
		 {
			correction = kp*error;
			// Saturation of PWM values
			if (correction > 130)
			correction = 150;
			if (correction < -70)
			correction = -70;
		 }
		 
		else
		 {
			correction=0;			
		 } 
	
		return correction;
 }
	
 