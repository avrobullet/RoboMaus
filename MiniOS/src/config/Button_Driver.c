/*
 * Button_Driver.c
 *
 * Created: 4/12/2016 11:09:24 AM
 *  Author: douglasa
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <asf.h>
#include <string.h>

void Button_Handler(uint32_t id, uint32_t mask)
{
	uint32_t led;
	if ( ID_PIOA == id && PIO_PA0 == mask ){ LineProgram(); }
	else if( ID_PIOC == id && PIO_PC29 == mask ){ Motor_Stop(); }
	else if( ID_PIOC == id && PIO_PC30 == mask ){ Motor_Reverse(); }
	else { return; }
	ioport_set_pin_level( led, !ioport_get_pin_level(led) );
}
const uint32_t irq_priority = 5;
void configure_buttons()
{
	//Configure Pushbutton 1
	pmc_enable_periph_clk(ID_PIOA);
	pio_set_debounce_filter(PIOA, PIN_PUSHBUTTON_1_MASK, 10);
	pio_handler_set(PIOA, ID_PIOA,
	PIN_PUSHBUTTON_1_MASK, PIN_PUSHBUTTON_1_ATTR, Button_Handler);
	NVIC_EnableIRQ((IRQn_Type) ID_PIOA);
	pio_handler_set_priority(PIOA, (IRQn_Type) ID_PIOA, irq_priority);
	pio_enable_interrupt(PIOA, PIN_PUSHBUTTON_1_MASK);

	//Configure Pushbutton 2
	pmc_enable_periph_clk(ID_PIOC);
	pio_set_debounce_filter(PIOC, PIN_PUSHBUTTON_2_MASK, 10);
	pio_handler_set(PIOC, ID_PIOC,
	PIN_PUSHBUTTON_2_MASK, PIN_PUSHBUTTON_2_ATTR, Button_Handler);
	NVIC_EnableIRQ((IRQn_Type) ID_PIOC);
	pio_handler_set_priority(PIOC, (IRQn_Type) ID_PIOC, irq_priority);
	pio_enable_interrupt(PIOC, PIN_PUSHBUTTON_2_MASK);

	//Configure Pushbutton 3
	pmc_enable_periph_clk(ID_PIOC);
	pio_set_debounce_filter(PIOC, PIN_PUSHBUTTON_3_MASK, 10);
	pio_handler_set(PIOC, ID_PIOC,
	PIN_PUSHBUTTON_3_MASK, PIN_PUSHBUTTON_3_ATTR, Button_Handler);
	NVIC_EnableIRQ((IRQn_Type) ID_PIOC);
	pio_handler_set_priority(PIOC, (IRQn_Type) ID_PIOC, irq_priority);
	pio_enable_interrupt(PIOC, PIN_PUSHBUTTON_3_MASK);
}