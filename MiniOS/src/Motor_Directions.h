/*
 * Motor_Driver.h
 *
 *	1. Have ioport_set_pin_dir in one function header instead of every single one
 *  2. probably have Motor_Forward_2 and _1 for each motor (same thing for the other motor direction operations)
 *
 */
#ifndef MOTOR_DIRECTIONS_H_
#define MOTOR_DIRECTIONS_H_

void Motor_Forward();

void Motor_Reverse();

void Motor_Stop();

#endif /* MOTOR_DRIVER_H_ */
