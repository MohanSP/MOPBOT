/*
 * Ultrasound.c
 *
 * Created: 5/18/2018 6:08:55 PM
 *  Author: Mohan Prabhakar and Kenneth Joel
 */ 

#define F_CPU 14745600
#define length 1

#include "Common_includes.h"
#include "Ultrasound.h"
#include "LCD.h"

int us_flag1=0, us_dist_int1, count1=0;
float us_dist1=0, us_time1=0;

float dist3=0,filter_array3[length],sum3=0;
int i3=0,j3=0,filtered_distance3=0;

int us_flag2=0, us_dist_int2, count2=0;
float us_dist2=0, us_time2=0;

float dist4=0,filter_array4[length],sum4=0;
int i4=0,j4=0,filtered_distance4=0;

void ultrasound_config()
{
	DDRJ = 0x3F;  //PJ0-5 as output and PJ6-7 as input
	PORTJ = 0x00; //Output is set to 0
}

//PJ2 ----> Trig1
//PJ3 ----> Trig2
//PJ7 ----> Echo1
//PJ6 ----> Echo2

//Function to make the trigger pin high for a very short duration
void ultrasound1_trigger()
{	
	PORTJ = 0x04;
	_delay_us(50);
	PORTJ = 0x00;
	_delay_us(10);
}

//Function to make the trigger pin high for a very short duration
void ultrasound2_trigger()
{
	PORTJ = 0x08;
	_delay_us(50);
	PORTJ = 0x00;
	_delay_us(10);
}

//Function to calculate the distance
int distance1_us()
 {	
	ultrasound1_trigger();
	TIFR4=0x01;	
	while ( (TIFR4 & 0x01) == 0x00 )
	{
		if ( ((PINJ & 0x80) == 0x00) && us_flag1==0 ) //Echo is low
		{
			TCNT4=0;
		}		
		if ( ((PINJ & 0x80) == 0x80) && us_flag1==0 ) //Echo goes from low to high, timer starts
		{
			TCNT4=0;
			us_flag1=1;
		}		
		if ( ((PINJ & 0x80) == 0x00) && us_flag1==1) //Echo goes from high to low, timer stops and the total time is calculated which is then used to calculate the distance
		{
			us_time1= (TCNT4H*256) + TCNT4L;
			us_dist1=(us_time1*33)/125;
			us_dist_int1=floor(us_dist1);
			filter_array3[i3]=us_dist_int1;
			i3++;
			break;
		}			
	}
	TIFR4=0x01;
	us_flag1=0;
	if (i3>length-1)
	{
		i3=length-1;		
		for (j3=0;j3<length-1;j3++)
		{	sum3=sum3+filter_array3[j3];
			filter_array3[j3]=filter_array3[j3+1];
		}
		sum3=sum3+filter_array3[length-1];
		filtered_distance3=(sum3/(length)) + 5;
		sum3=0;
	}
	return filtered_distance3;	
 }
 
 int distance2_us()
 {
	 ultrasound2_trigger();
	 TIFR4=0x01;
	 
	 while ( (TIFR4 & 0x01) == 0x00 )
	 {
		 if ( ((PINJ & 0x40) == 0x00) && us_flag2==0 )
		 {
			 TCNT4=0;
		 }
		 
		 if ( ((PINJ & 0x40) == 0x40) && us_flag2==0 )
		 {
			 TCNT4=0;
			 us_flag2=1;
		 }
		 
		 if ( ((PINJ & 0x40) == 0x00) && us_flag2==1)
		 {
			 us_time2= (TCNT4H*256) + TCNT4L;
			 us_dist2=(us_time2*33)/125;
			 us_dist_int2=floor(us_dist2);
			 filter_array4[i4]=us_dist_int2;
			 i4++;
			 break;
		 }
		 
	 }
	 TIFR4=0x01;
	 us_flag2=0;
	 
	 if (i4>length-1)
	 {
		 i4=length-1;
		 
		 for (j4=0;j4<length-1;j4++)
		 {	sum4=sum4+filter_array4[j4];
			 filter_array4[j4]=filter_array4[j4+1];
		 }
		 sum4=sum4+filter_array4[length-1];
		 filtered_distance4=(sum4/(length)) + 5;
		 sum4=0;
	 }
	 
//	 lcd_cursor(1,13);
//	 lcd_string("USLe2");
//	 lcd_print(2,14,filtered_distance4,2);
	 return filtered_distance4;
 }

