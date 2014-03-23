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
 
#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7
 
int dayOfWeek (int doomsday, int leapYear, int month, int day);
 
int main (int argc, char *argv[]) {
    int dayOfWeekResult;
    dayOfWeekResult = dayOfWeek (FRIDAY, TRUE, 1, 20);
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
    // assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
    // assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
    // assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
    // assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
    // assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
    // assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);

    // assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
    // assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
    // assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);

    // printf ("all tests passed - You are awesome!\n");
    // return EXIT_SUCCESS;
}
 
 
// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.
 
int dayOfWeek (int doomsday, int leapYear, int month, int day) {
    //int dayOfWeek;

    int januaryDoomsday;
    int februaryDoomsday;
    int marchDoomsday;
    int aprilDoomsday;
    int mayDoomsday;
    int juneDoomsday;
    int julyDoomsday;
    int augustDoomsday;
    int septemberDoomsday;
    int octoberDoomsday;
    int novemberDoomsday;
    int decemberDoomsday;


    int daysTillDesiredDateAsMultipleOfSeven;
    int remainingDays;


    int doomsdayResult;
    // Definition of Doomsday for every month with special case of Leap Year

    if (leapYear) {
      januaryDoomsday = 4;
      februaryDoomsday = 29;
    } else {
      januaryDoomsday = 3;
      februaryDoomsday = 28;
    }

    // Definition of Doomsday for every month, irrespective of Leap Year according to rule

    marchDoomsday = 7;
    aprilDoomsday = 4;
    mayDoomsday = 9;
    juneDoomsday = 6;
    julyDoomsday = 11;
    augustDoomsday = 8;
    septemberDoomsday = 5;
    octoberDoomsday = 10;
    novemberDoomsday = 7;
    decemberDoomsday = 12;

    // Set up logic to handle the month values passed in\

    // if month passed in is january
    if (month == 1) {


      // if the doomsday of January is smaller than the requested day
      if (januaryDoomsday < day) {

        // Add 7 to the January Doomsday until it is larger than day requested
        while (januaryDoomsday < day) {
          januaryDoomsday += 7;
        }
        // Take 7 off, to get to the highest possible number which has been formed by adding a multiple of 7
        daysTillDesiredDateAsMultipleOfSeven = januaryDoomsday - 7;
        // How many days should I add to my doomsday, to get the actual day value of the requested date
        remainingDays = day - daysTillDesiredDateAsMultipleOfSeven;

        doomsdayResult = doomsday + remainingDays;

      }
      // Reset variable values, in case they have been tampered with elsewhere
      if (leapYear) {
        januaryDoomsday = 4;
      } else {
        januaryDoomsday = 3;
      }

      // if the doomsday of January is larger than the requested day
      if (januaryDoomsday > day) {

        // Subtract 7 from the January Doomsday until is is smaller than the day requested
        while (januaryDoomsday > day) {
          januaryDoomsday -= 7;
        }
        // Add 7 to answer, to get the lowest possible number which has been formed by subtracting a multiple of 7
        daysTillDesiredDateAsMultipleOfSeven = januaryDoomsday + 7;
        // How many days should I subtract off doomsday, to get the actual value of the requested date
        remainingDays = daysTillDesiredDateAsMultipleOfSeven - day;
        
        doomsdayResult = doomsday - remainingDays;

      }
    }

    return doomsdayResult;

    // return (dayOfWeek);
}