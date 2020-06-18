#include <stdint-gcc.h>

#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

void Button_Handler(uint32_t id, uint32_t mask);

void configure_buttons(void);

#endif /* BUTTON_DRIVER_H_ */
