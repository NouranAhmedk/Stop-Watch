/*
 * ISR.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Nouran
 */
#include<avr/io.h>
#include<avr/interrupt.h>
#include "SevenSegmentTimeCalc.h"
/* Timer One Interrupt Service Routine */
ISR(TIMER1_COMPA_vect) {
	incrementFlag = 1;                         //ISR only sets a flag to indicate that an increment is needed
}
/* External INT1 Interrupt Service Routine */
ISR(INT1_vect) {
	TCCR1B &= ~(1 << CS10) & ~(1 << CS12);     //Stop Watch time should be paused. by making CS10 = 0 and CS12 = 0 and we use OR equal to save other values of this register
}
/* External INT0 Interrupt Service Routine */
ISR(INT0_vect) {                               // Stop Watch time should be reset by making the timer values equal to zero
	TimeCalculation->hour_one = 0;
	TimeCalculation->hour_zero = 0;
	TimeCalculation->minute_one = 0;
	TimeCalculation->minute_zero = 0;
	TimeCalculation->second_one = 0;
	TimeCalculation->second_zero = 0;
}
/* External INT2 Interrupt Service Routine */
ISR(INT2_vect) {
	TCCR1B |= (1 << CS12) | (1 << CS10);      //Stop Watch time should be Resume. by making CS10 = 1 and CS12 = 1 and we use OR equal to save other values of this register
}


