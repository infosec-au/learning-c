/*
*  doomsday.c
*  A program to test a function dayOfWeek which determines which
*  day of the week a particular date falls on.
*  (only for dates after the start of the Gregorian calendar).
*
*  Program stub created by Richard Buckland on 17/03/14
*  This program by Shubham Shah
*  Freely licensed under Creative Commons CC-BY-3.0
*
*
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define THURSDAY  0
#define FRIDAY    1
#define SATURDAY  2
#define SUNDAY    3
#define MONDAY    4
#define TUESDAY   5
#define WEDNESDAY 6

#define JAN_DOOMSDAY 3
#define FEB_DOOMSDAY 28
#define MAR_DOOMSDAY 7
#define APR_DOOMSDAY 4
#define MAY_DOOMSDAY 9
#define JUN_DOOMSDAY 6
#define JUL_DOOMSDAY 11
#define AUG_DOOMSDAY 8
#define SEP_DOOMSDAY 5
#define OCT_DOOMSDAY 10
#define NOV_DOOMSDAY 7
#define DEC_DOOMSDAY 12
 
#define TRUE          1
#define FALSE         0
#define DAYS_PER_WEEK 7

int dayOfWeek (int doomsday, int leapYear, int month, int day);
int doomsdayCalculations (int doomsday, int doomsdayOfMonth, int day);

int main (int argc, char *argv[]) {
    
    return EXIT_SUCCESS;
}

int dayOfWeek (int doomsday, int leapYear, int month, int day) {

    // Computes the correct doomsday date for any given month
    // then sends the date to doomsdayCalculations, to solve for dayOfWeek

    int dayOfWeek = 0;
    if (month == 1) {
        if (leapYear) {
            dayOfWeek = doomsdayCalculations (doomsday, (JAN_DOOMSDAY + 1), day);
        } else {
            dayOfWeek = doomsdayCalculations (doomsday, JAN_DOOMSDAY, day);
        }
    }

    if (month == 2) {
        if (leapYear) {
            dayOfWeek = doomsdayCalculations (doomsday, (FEB_DOOMSDAY + 1), day);
        } else {
            dayOfWeek = doomsdayCalculations (doomsday, FEB_DOOMSDAY, day);
        }
    }

    if (month == 3) {
        dayOfWeek = doomsdayCalculations (doomsday, MAR_DOOMSDAY, day);
    }

    if (month == 4) {
        dayOfWeek = doomsdayCalculations (doomsday, APR_DOOMSDAY, day);
    }

    if (month == 5) {
        dayOfWeek = doomsdayCalculations (doomsday, MAY_DOOMSDAY, day);
    }

    if (month == 6) {
        dayOfWeek = doomsdayCalculations (doomsday, JUN_DOOMSDAY, day);
    }

    if (month == 7) {
        dayOfWeek = doomsdayCalculations (doomsday, JUL_DOOMSDAY, day);
    }

    if (month == 8) {
        dayOfWeek = doomsdayCalculations (doomsday, AUG_DOOMSDAY, day);
    }

    if (month == 9) {
        dayOfWeek = doomsdayCalculations (doomsday, SEP_DOOMSDAY, day);
    }

    if (month == 10) {
        dayOfWeek = doomsdayCalculations (doomsday, OCT_DOOMSDAY, day);
    }

    if (month == 11) {
        dayOfWeek = doomsdayCalculations (doomsday, NOV_DOOMSDAY, day);
    }

    if (month == 12) {
        dayOfWeek = doomsdayCalculations (doomsday, DEC_DOOMSDAY, day);
    }

    return dayOfWeek;
}

int doomsdayCalculations (int doomsday, int doomsdayOfMonth, int day) {
    int doomsdayCalculationResult;
    // Calculates the remainder of difference in days when divided by 7
    int diffInDays = (day - doomsdayOfMonth) % DAYS_PER_WEEK;

    // In case we get a negative number for diffInDays,
    // we can add 7 until it is positive, as adding 7
    // will not affect the validity of the result
    while (diffInDays < 0) {
        diffInDays += DAYS_PER_WEEK;
    }
    // Final calculation to find the day of week
    doomsdayCalculationResult = (diffInDays + doomsday) % DAYS_PER_WEEK;

    return doomsdayCalculationResult;
}
