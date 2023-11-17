/*
 * Timer1_COMP_Init.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Nouran
 */
#include<avr/io.h>
#include <avr/interrupt.h>
/* Description:
 * For System Clock = 1Mhz and prescaler F_CPU/1024.
 * Timer frequency will be around 1Khz, Ttimer = 1ms
 * For compare value approximability equals to (977) the timer will generate compare match interrupt every 1sec.
 * Compare interrupt will be generated every 1sec.
 */
void Timer1_COMP_Init(void) {

	TCNT1 = 0;                              // Set Timer1 initial value to 0
	OCR1A = 977;                            // Set Timer compare value to 977
	TIMSK = (1 << OCIE1A);                  // Enable Timer1 Compare Interrupt
	sei();
	/* Configure timer1 control register
	 * 1. Non PWM mode FOC1A for Register A =1
	 * 2. CTC Mode WGM012 where Top value = OCR1A
	 * 3. No need for OC0 in this example so COM1A1/COM1B1 = 0, COM1A0/COM1B0 = 0
	 * 4. clock = F_CPU/1024 CS12=1 CSCS11=0 CS10=1
	 */
	TCCR1A = (1 << FOC1A);
	TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);

}

