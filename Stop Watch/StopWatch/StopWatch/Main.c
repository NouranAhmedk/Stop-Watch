/*
 * Main.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Nouran
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
// Including Header Files used in this Project
#include "SevenSegmentDisplay.h"
#include "SevenSegmentTimeCalc.h"
#include "Timer1_COMP_Init.h"
#include "interrupts.h"
#include "ISR.h"

volatile struct Time currentTime = {0, 0, 0, 0, 0, 0}; // Initialize Structure values with zeros to set Second = 0, Minutes = 0, Hours = 0

int main(void) {
    TimeCalculation = &currentTime;
    SevenSegmentInit();
    Timer1_COMP_Init();
	INT1_Init();
	INT0_Init();
	INT2_Init();
	PORTC &= 0xF0;
	PORTA &= 0xC0;
	while (1) {
		SevenSegmentTimecalculations();
	    SevenSegmentDisplay();
	}

    return 0;
}
