/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to board_init()
 * -# Basic usage of on-board LED and button
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <stdio.h>
#include <stdlib.h>
#include <asf.h>
#include <string.h>
#include <proj.h>

int main(void)
{
	//This is all for printing to the LCD screen
	sysclk_init();
	board_init();
	ssd1306_init();
	ssd1306_clear();

	//Initializing LineProgram()
	LineProgram();

	//setting buttons for specific program
	configure_buttons();

	//Configure ADC
	configure_adc();

	//start ADC
	adc_start(ADC);

	while(1);
}
