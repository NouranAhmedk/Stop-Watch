/*
 * Interrupt.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Nouran
 */

#include<avr/io.h>
#include <avr/interrupt.h>

// Interrupt 1 Raising edge
/* External INT1 enable and configuration function */
void INT1_Init(void) {
	DDRD &= (~(1 << PD3));                   // Configure INT1/PD3 as input pin
	MCUCR |= (1 << ISC11) | (1 << ISC10);    // Trigger INT1 with the raising edge
	GICR |= (1 << INT1); 				     // Enable external interrupt pin INT1
}

// Both Interrupt 0 & Interrupt 2 Falling edge
//*****************************************************************************
/* External INT0 enable and configuration function */
void INT0_Init(void) {
	DDRD &= (~(1 << PD2));                  // Configure INT0/PD2 as input pin
	MCUCR |= (1 << ISC01);                  // Trigger INT0 with the raising edge
	GICR |= (1 << INT0);                    // Enable external interrupt pin INT0
	PORTD |= (1 << PD2);                    // Internal  pull-up resistor
}

/* External INT2 enable and configuration function */
void INT2_Init(void) {
	DDRB &= (~(1 << PD2));                  // Configure INT2/PB2 as input pin
	GICR |= (1 << INT2);                    // Enable external interrupt pin INT2
	PORTB |= (1 << PD2);                    // Internal  pull-up resistor
	                                        // IN register MCUCSR If ISC2 is written to zero, a falling edge on INT2 activates the interrupt.
}


