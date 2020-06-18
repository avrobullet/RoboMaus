#include <asf.h>
#include <proj.h>

#define ENA IOPORT_CREATE_PIN( PIOA, 18 ) //PIN 4:EXT1
#define IN1 IOPORT_CREATE_PIN( PIOA, 24 ) //PIN 5:EXT1
#define IN2 IOPORT_CREATE_PIN( PIOA, 23 ) //PIN 7:EXT1
#define ENB IOPORT_CREATE_PIN( PIOA, 3 )  //PIN 11:EXT1
#define IN3 IOPORT_CREATE_PIN( PIOA, 21 ) //PIN 13:EXT1
#define IN4 IOPORT_CREATE_PIN( PIOA, 11 ) //PIN 15:EXT1

void motor1_forward()
{
	bool state = true;

	ioport_set_pin_level( ENA, state );
	ioport_set_pin_level( IN1, state );
	ioport_set_pin_level( IN2, !state );
}
void motor2_forward()
{
	bool state = true;

	ioport_set_pin_level( ENB, state );
	ioport_set_pin_level( IN3, state );
	ioport_set_pin_level( IN4, !state );
}
void motor1_backward()
{
	bool state = false;

	ioport_set_pin_level( ENA, !state );
	ioport_set_pin_level( IN1, state );
	ioport_set_pin_level( IN2, !state );
}
void motor2_backward()
{
	bool state = false;

	ioport_set_pin_level( ENB, !state );
	ioport_set_pin_level( IN3, state );
	ioport_set_pin_level( IN4, !state );
}
void motor1_stop()
{
	bool state = true;

	ioport_set_pin_level( ENA, state );
	ioport_set_pin_level( IN1, !state );
	ioport_set_pin_level( IN2, !state );
}
void motor2_stop()
{
	bool state = true;

	ioport_set_pin_level( ENB, state );
	ioport_set_pin_level( IN3, !state );
	ioport_set_pin_level( IN4, !state );
}
