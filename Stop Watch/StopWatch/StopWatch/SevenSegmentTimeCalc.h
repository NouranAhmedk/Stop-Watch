/*
 * SevenSegmentTimeCalc.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Nouran
 */

#ifndef SEVENSEGMENTTIMECALC_H_
#define SEVENSEGMENTTIMECALC_H_
// Some Declarations
typedef unsigned char uint8;
volatile uint8 incrementFlag;
volatile struct Time {
    uint8 hour_one;
    uint8 hour_zero;
    uint8 minute_one;
    uint8 minute_zero;
    uint8 second_one;
    uint8 second_zero;
} *TimeCalculation;
void SevenSegmentTimecalculations(void);
#endif /* SEVENSEGMENTTIMECALC_H_ */
