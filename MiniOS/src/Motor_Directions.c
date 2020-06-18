#include <asf.h>
#include <proj.h>

#define ENA IOPORT_CREATE_PIN( PIOA, 17 ) //PIN 3:EXT1
#define IN1 IOPORT_CREATE_PIN( PIOA, 24 ) //PIN 5:EXT1
#define IN2 IOPORT_CREATE_PIN( PIOA, 23 ) //PIN 7:EXT1
#define ENB IOPORT_CREATE_PIN( PIOA, 3 ) 	//PIN 11:EXT1
#define IN3 IOPORT_CREATE_PIN( PIOA, 21 ) //PIN 13:EXT1
#define IN4 IOPORT_CREATE_PIN( PIOA, 11 ) //PIN 15:EXT1

void Motor_Forward()
{
	// Insert application code here, after the board has been initialized.
	ioport_set_pin_dir( ENA, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( IN1, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( IN2, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( ENB, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( IN3, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( IN4, IOPORT_DIR_OUTPUT );

	// This skeleton code simply sets the LED to the state of the button.

	motor1_forward();
	motor2_forward();
}

void Motor_Reverse()
{
	// Insert application code here, after the board has been initialized.
	ioport_set_pin_dir( ENA, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( IN1, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( IN2, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( ENB, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( IN3, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( IN4, IOPORT_DIR_OUTPUT );

	motor1_backward();
	motor2_backward();
}
void Motor_Stop()
{
	// Insert application code here, after the board has been initialized.
	ioport_set_pin_dir( ENA, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( IN1, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( IN2, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( ENB, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( IN3, IOPORT_DIR_OUTPUT );
	ioport_set_pin_dir( IN4, IOPORT_DIR_OUTPUT );

	motor1_stop();
	motor2_stop();
}
