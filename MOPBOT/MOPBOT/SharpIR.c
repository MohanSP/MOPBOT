/*
 * SharpIR.c
 *
 * Created: 21-05-2018 09:32:31
 *  Author: U R SOLUTIONS
 */ 

#define F_CPU 14745600
#define lengthF 3

#include "Common_includes.h"
#include "SharpIR.h"
#include "LCD.h"
#include "ADC.h"

float dist2=0,filter_array2[lengthF],sum2=0;
unsigned char ADC_value2;
int i2=0,j2=0,filtered_distance2=0;

int distance_IRF()
 {
	ADC_value2=ADC_Conversion(11);
	dist2 = (2799.6*(1/(pow(ADC_value2,1.1546))));
	filter_array2[i2]=dist2;
	i2++;
	
	if (i2>lengthF-1)
 	 {
		i2=lengthF-1;
		
		for (j2=0;j2<lengthF-1;j2++)
		 {	sum2=sum2+filter_array2[j2];
			filter_array2[j2]=filter_array2[j2+1];
		 }
		sum2=sum2+filter_array2[lengthF-1];
		filtered_distance2=sum2/(lengthF);
		sum2=0;
	 }
	 
	return filtered_distance2;
 }
 