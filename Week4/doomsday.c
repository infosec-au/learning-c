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
 
#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7

int dayOfWeek (int doomsday, int leapYear, int month, int day);
int doomsdayCalculations (int doomsday, int doomsdayOfMonth, int day);
void runUnitTests (void);

int main (int argc, char *argv[]) {
    runUnitTests();
    return EXIT_SUCCESS;
}

int dayOfWeek (int doomsday, int leapYear, int month, int day) {

    // Function which computes the correct doomsday date for any given month
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
    // Calculates the difference in days, modulo 7
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

void testPrint(int testGroup) {

   printf("Group %d has passed - you're awesome!\n",testGroup);
}


void runUnitTests (void) {
   printf("Testing group 1\n");
   assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);
   testPrint(1); 

   printf("Testing group 2\n");
   assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);
   testPrint(2); 

   printf("Testing group 3\n");
   assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  1,   3) == THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   3,  27) == TUESDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   1,   4) == MONDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  1,   4) == TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  3,  21) == FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  2,  1) == SUNDAY);
   testPrint(3);

   printf("Testing group 4\n");
   assert (dayOfWeek (THURSDAY, TRUE, 2, 29) == THURSDAY);
   assert (dayOfWeek (THURSDAY, TRUE, 2, 28) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 2, 28) == THURSDAY);
   assert (dayOfWeek (THURSDAY, TRUE, 7, 1) == MONDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 12, 18) == WEDNESDAY);
   assert (dayOfWeek (FRIDAY, FALSE, 2, 10) == MONDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 10, 21) == WEDNESDAY);
   assert (dayOfWeek (MONDAY, FALSE, 3, 1) == TUESDAY);
   assert (dayOfWeek (FRIDAY, FALSE, 2, 26) == WEDNESDAY);
   assert (dayOfWeek (FRIDAY, FALSE, 2, 11) == TUESDAY);
   testPrint(4);

   printf("Testing group 5\n");
   assert (dayOfWeek (TUESDAY, TRUE, 2, 27) == SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 2,  22) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY, TRUE, 1, 3) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY, TRUE, 1, 11) == THURSDAY);
   assert (dayOfWeek (THURSDAY, TRUE, 2, 1) == THURSDAY);
   assert (dayOfWeek (THURSDAY, TRUE, 2, 29) == THURSDAY);
   assert (dayOfWeek (THURSDAY, TRUE, 2, 17) == SATURDAY);
   assert (dayOfWeek (THURSDAY, TRUE, 2, 18) == SUNDAY);
    
   testPrint(5);

   printf("Testing group 6\n");
   assert (dayOfWeek (FRIDAY, TRUE, 1, 1) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 2, 29) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 3, 30) == SATURDAY);
   assert (dayOfWeek (TUESDAY, TRUE, 4, 24) == MONDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 12, 31) == TUESDAY);
   assert (dayOfWeek (SATURDAY, TRUE, 1, 5) == SUNDAY);
   assert (dayOfWeek (MONDAY, TRUE, 10, 18) == TUESDAY);
   assert (dayOfWeek (MONDAY, FALSE, 11, 12) == SATURDAY);

   testPrint(6);

   printf("Testing group 7\n");
   assert (dayOfWeek (MONDAY, TRUE, 2, 15) == MONDAY);
   assert (dayOfWeek (MONDAY, TRUE, 1, 4) == MONDAY);
   assert (dayOfWeek (MONDAY, TRUE, 4, 4) == MONDAY);
   assert (dayOfWeek (MONDAY, TRUE, 2, 29) == MONDAY);
   assert (dayOfWeek (MONDAY, FALSE, 2, 28) == MONDAY);
   assert (dayOfWeek (MONDAY, TRUE, 3, 1) == TUESDAY);
   assert (dayOfWeek (FRIDAY, FALSE, 6, 6) == FRIDAY); 
   assert (dayOfWeek (TUESDAY, TRUE, 4, 1) == SATURDAY);
   assert (dayOfWeek (TUESDAY, TRUE, 12, 25) == MONDAY);
   assert (dayOfWeek (TUESDAY, FALSE, 4, 1) == SATURDAY);

   testPrint(7);

   printf("Testing group 8\n");
   assert (dayOfWeek (THURSDAY, TRUE, 3, 2) == SATURDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 1, 1) == TUESDAY);
   assert (dayOfWeek (SATURDAY, TRUE, 10, 10) == SATURDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 3, 13) == FRIDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 11, 4) == MONDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 7, 22) == MONDAY);
   assert (dayOfWeek (FRIDAY, TRUE, 3, 15) == SATURDAY);
   assert (dayOfWeek (FRIDAY, FALSE, 5, 12) == MONDAY);
   assert (dayOfWeek (FRIDAY, FALSE, 7, 2) == WEDNESDAY);
   assert (dayOfWeek (SUNDAY, TRUE, 1, 31) == SATURDAY);
   testPrint(8);

   printf("Testing group 9\n");
   assert (dayOfWeek (THURSDAY, TRUE, 1, 6) == SATURDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 6, 10) == SUNDAY); 
   assert (dayOfWeek (THURSDAY, TRUE, 10, 1) == TUESDAY);
   assert (dayOfWeek (SATURDAY,  TRUE,  2,  3)  == MONDAY);
   assert (dayOfWeek (FRIDAY, TRUE, 11, 29) == SATURDAY);
   assert (dayOfWeek (FRIDAY, FALSE, 12, 12) == FRIDAY);
   assert (dayOfWeek (FRIDAY, TRUE, 3, 19) == WEDNESDAY);
   assert (dayOfWeek (FRIDAY, TRUE, 6, 6) == FRIDAY);
   assert (dayOfWeek (TUESDAY, TRUE, 3, 14) == TUESDAY);
   assert (dayOfWeek (TUESDAY, TRUE, 3, 15) == WEDNESDAY);
   assert (dayOfWeek (TUESDAY, TRUE, 8 , 28) == MONDAY);
   testPrint(9);
   
   assert (dayOfWeek (THURSDAY, TRUE, 10, 3) == THURSDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 7, 6) == SATURDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 10, 16) == TUESDAY);
   assert (dayOfWeek (SUNDAY, FALSE, 2,8) == MONDAY);
   
   printf("Testing group 10 -- tutor birthdays\n");
   assert (dayOfWeek (SATURDAY, TRUE, 5, 15) == FRIDAY);
   assert (dayOfWeek (THURSDAY, TRUE, 5, 26) == SUNDAY);
   testPrint(10);
   printf ("All tests passed - You are Awesome!\n");
}