/*
 * SevenSegmentTimeCalc.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Nouran
 */
#include <avr/io.h>
#include "SevenSegmentTimeCalc.h"

// Time Calculations for seconds, minutes, hours
// Knowing the Limit of the Stopwatch 99:59:59
void SevenSegmentTimecalculations(void) {
    if (incrementFlag == 1) { // Checking the flag
        TimeCalculation->second_zero++;
        incrementFlag = 0;
    }

    if (TimeCalculation->second_zero == 10) {
        TimeCalculation->second_zero = 0;
        TimeCalculation->second_one += 1;
    }

    if (TimeCalculation->second_one == 6) {
        TimeCalculation->second_one = 0;
        TimeCalculation->minute_zero += 1;
    }

    if (TimeCalculation->minute_zero == 10) {
        TimeCalculation->minute_zero = 0;
        TimeCalculation->minute_one += 1;
    }

    if (TimeCalculation->minute_one == 6) {
        TimeCalculation->minute_one = 0;
        TimeCalculation->hour_zero += 1;
    }

    if (TimeCalculation->hour_zero == 10) {
        TimeCalculation->hour_zero = 0;
        TimeCalculation->hour_one += 1;
    }

    if (TimeCalculation->hour_one == 10) {
        TimeCalculation->hour_one = 0;
        TimeCalculation->hour_zero = 0;
        TimeCalculation->minute_one = 0;
        TimeCalculation->minute_zero = 0;
        TimeCalculation->second_one = 0;
        TimeCalculation->second_zero = 0;
    }
}
