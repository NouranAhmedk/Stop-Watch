/*
 * SevenSegmentDisplay.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Nouran
 */
#include<avr/io.h>
#include<util/delay.h>
#include"SevenSegmentTimeCalc.h"
#include"SevenSegmentDisplay.h"
void SevenSegmentInit(void) {
	// Initialization of SevenSegments and decoder
	DDRC |= 0x0F;
	DDRA |= 0x3F;
}
void SevenSegmentDisplay(void) {
		// Applying Multiplexing method
		PORTA = (PORTA & 0xC0) | (1 << 0);  // PORTA = 0xC0
		PORTC = (PORTC & 0xF0) | (TimeCalculation->second_zero & 0x0F);
		_delay_ms(SevenSegmentDelay);

		PORTA = (PORTA & 0xC0) | (1 << 1);  //PORTA = 0xC1
		PORTC = (PORTC & 0xF0) | (TimeCalculation->second_one & 0x0F);
		_delay_ms(SevenSegmentDelay);

		PORTA = (PORTA & 0xC0) | (1 << 2);  //PORTA = 0xC4
		PORTC = (PORTC & 0xF0) | (TimeCalculation->minute_zero & 0x0F);
		_delay_ms(SevenSegmentDelay);

		PORTA = (PORTA & 0xC0) | (1 << 3);  //PORTA = 0xC8
		PORTC = (PORTC & 0xF0) | (TimeCalculation->minute_one & 0x0F);
		_delay_ms(SevenSegmentDelay);

		PORTA = (PORTA & 0xC0) | (1 << 4);  //PORTA = 0xD0
		PORTC = (PORTC & 0xF0) | (TimeCalculation->hour_zero & 0x0F);
		_delay_ms(SevenSegmentDelay);

		PORTA = (PORTA & 0xC0) | (1 << 5);  //PORTA = 0xE0
		PORTC = (PORTC & 0xF0) | (TimeCalculation->hour_one & 0x0F);
		_delay_ms(SevenSegmentDelay);
}
