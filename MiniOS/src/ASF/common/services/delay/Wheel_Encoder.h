/*
 * CFile1.c
 *
 * Created: 4/12/2016 10:31:48 AM
 *  Author: drakos
 */ 

#include <stdint-gcc.h>

#ifndef WHEEL_ENCODER_H
#define WHEEL_ENCODER_H

/*
 * Function: configure_adc
 * -------------------------
 * Used to configure the analog to digital
 * drivers.
 */
void configure_adc(void);

/*
 * Function: task2
 * Usage: uint32_t val
 * -------------------------
 * Used to determine the current wheel position
 * and calls task1 in case the counter needs to be
 * incremented
 */
void task2(uint32_t val);

/*
 * Function: task1
 * Usage: uint32_t val
 * -------------------------
 * Used to increment the counter when the wheel
 * encoder hits one of the 4 poles of the wheel
 */
void task1(uint32_t val);

/*
 * Function: get_values
 * Usage: uint32_t val
 * -------------------------
 * Used to poll the adc channels for the values.
 */
void get_values();

/*
 * Function: check_values
 * Usage: Stack S1
 * -------------------------
 * Used to poll the adc channels for the values.
 */
void check_values_left(int val_left, int val_right);

void check_values_right();

void check_values();

#endif //WHEEL_ENCODER_H