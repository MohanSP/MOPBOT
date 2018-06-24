/*
 * Angle_fix_DH.c
 *
 * Created: 27-05-2018 20:18:57
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

#define F_CPU 14745600

#include "Angle_fix_DH.h"
#include "Common_includes.h"
#include <stdlib.h>

//Calculating the servo angles from the angles obtained from DH parameter modelling of the arm
int angle_fix(int DH_degrees1, int DH_degrees2, int DH_degrees3, int servo_number)
 {
	int degrees=0, degrees1=0, degrees2=0, degrees3=0;
	
	degrees1=DH_degrees1+90;
	degrees2=abs(DH_degrees2+180);
	degrees3=(180-DH_degrees2-DH_degrees3);
		
	if (servo_number==1)
	{
		degrees=degrees1;
	}
		
	else if (servo_number==2)
	{
	if (degrees2<20)
	{
		degrees2=20;
	}

	else if (degrees2>160)
	{
		degrees2=160;
	}
		degrees=degrees2;
	}
	 
	else
	{
	if (degrees3<20)
	{
		degrees3=20;
	}
	
	else if (degrees3>160)
	{
		degrees3=160;
	}
		degrees=degrees3;
	}
	
	 return degrees;
 }