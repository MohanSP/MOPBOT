/*
 * Motor.h
 *
 * Created: 5/5/2018 8:49:02 PM
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

void motion_pin_config(void);
void motion_set (unsigned char Direction);
void velocity (unsigned char left_motor, unsigned char right_motor);
void forward (unsigned char left_motor_pwm, unsigned char right_motor_pwm);
void left(void);
void right(void);
void stop (void);
void right_degrees(unsigned int Degrees);
