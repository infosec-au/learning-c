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
 
#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define JANUARYDOOMSDAY 3
#define FEBURARYDOOMSDAY 28
#define MARCHDOOMSDAY 7
#define APRILDOOMSDAY 4
#define MAYDOOMSDAY 9
#define JUNEDOOMSDAY 6
#define JULYDOOMSDAY 11
#define AUGUSTDOOMSDAY 8
#define SEPTEMBERDOOMSDAY 5
#define OCTOBERDOOMSDAY 10
#define NOVEMBERDOOMSDAY 7
#define DECEMBERDOOMSDAY 12
 
#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7
 
int dayOfWeek (int doomsday, int leapYear, int month, int day);
int doomsdayCalculations (int doomsdayOfMonth, int doomsdayOfWeek, int startDay);
 
int main (int argc, char *argv[]) {
    // int dayOfWeekResult;
    // dayOfWeekResult = dayOfWeek (FRIDAY, TRUE, 1, 20);
    // printf("%d\n", dayOfWeekResult);
    // assert (dayOfWeek (FRIDAY, TRUE, 1, 20) == SUNDAY);
    // assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
    // assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
    // assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
    // assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
    // assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
    // assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
    // assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
    // assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
    // assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
    // assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);

    // assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
    // assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
    // assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
    // assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
    printf("%d",dayOfWeek (FRIDAY,    FALSE, 12, 20));
    assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
    // assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
    // assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
    // assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
    // assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
    // assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);

    // assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
    // assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
    // assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);

    printf ("all tests passed - You are awesome!\n");
    return EXIT_SUCCESS;
}
 
 
// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.
 
int dayOfWeek (int doomsday, int leapYear, int month, int day) {
    int dayOfWeekRes;

    // int lyear = JANUARYDOOMSDAY + 1;
    // printf("%d", lyear);

    if (month == 1) {
        if (leapYear) {
            dayOfWeekRes = doomsdayCalculations ((JANUARYDOOMSDAY + 1), doomsday, day);
        } else {
            dayOfWeekRes = doomsdayCalculations (JANUARYDOOMSDAY, doomsday, day);
        }
    }

    if (month == 2) {
        if (leapYear) {
            dayOfWeekRes = doomsdayCalculations ((FEBURARYDOOMSDAY + 1), doomsday, day);
        } else {
            dayOfWeekRes = doomsdayCalculations (FEBURARYDOOMSDAY, doomsday, day);
        }
    }

    if (month == 3) {
        dayOfWeekRes = doomsdayCalculations (MARCHDOOMSDAY, doomsday, day);
    }

    if (month == 4) {
        dayOfWeekRes = doomsdayCalculations (APRILDOOMSDAY, doomsday, day);
    }

    if (month == 5) {
        dayOfWeekRes = doomsdayCalculations (MAYDOOMSDAY, doomsday, day);
    }

    if (month == 6) {
        dayOfWeekRes = doomsdayCalculations (JUNEDOOMSDAY, doomsday, day);
    }

    if (month == 7) {
        dayOfWeekRes = doomsdayCalculations (JULYDOOMSDAY, doomsday, day);
    }

    if (month == 8) {
        dayOfWeekRes = doomsdayCalculations (AUGUSTDOOMSDAY, doomsday, day);
    }

    if (month == 9) {
        dayOfWeekRes = doomsdayCalculations (SEPTEMBERDOOMSDAY, doomsday, day);
    }

    if (month == 10) {
        dayOfWeekRes = doomsdayCalculations (OCTOBERDOOMSDAY, doomsday, day);
    }

    if (month == 11) {
        dayOfWeekRes = doomsdayCalculations (NOVEMBERDOOMSDAY, doomsday, day);
    }

    if (month == 12) {
        dayOfWeekRes = doomsdayCalculations (DECEMBERDOOMSDAY, doomsday, day);
    }
    return dayOfWeekRes;

}



int doomsdayCalculations (int doomsdayOfMonth, int doomsdayOfWeek, int startDay) {


    int daysTillDesiredDateAsMultipleOfSeven;
    int remainingDays;


    int doomsdayResult = 0;



      // if the doomsday of January is smaller than the requested day
      if (doomsdayOfMonth < startDay) {

        // Add 7 to the January Doomsday until it is larger than day requested
        while (doomsdayOfMonth < startDay) {
          doomsdayOfMonth += 7;
        }
        // Take 7 off, to get to the highest possible number which has been formed by adding a multiple of 7
        daysTillDesiredDateAsMultipleOfSeven = doomsdayOfMonth - 7;
        // How many days should I add to my doomsday, to get the actual day value of the requested date
        remainingDays = startDay - daysTillDesiredDateAsMultipleOfSeven;

        doomsdayResult = doomsdayOfWeek + remainingDays;

      }
      // if the doomsday of January is larger than the requested day
      if (doomsdayOfMonth > startDay) {

        // Subtract 7 from the January Doomsday until is is smaller than the day requested
        while (doomsdayOfMonth > startDay) {
          doomsdayOfMonth -= 7;
        }
        // Add 7 to answer, to get the lowest possible number which has been formed by subtracting a multiple of 7
        daysTillDesiredDateAsMultipleOfSeven = doomsdayOfMonth + 7;
        // How many days should I subtract off doomsday, to get the actual value of the requested date
        remainingDays = daysTillDesiredDateAsMultipleOfSeven - startDay;
        
        doomsdayResult = doomsdayOfWeek - remainingDays;

      }
    //printf("%d", doomsdayResult);
    return doomsdayResult;
}
