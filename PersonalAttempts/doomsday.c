/* 	Shubham Shah
	March 12th 2014
	This program takes in any date after START_GREGORIAN_CALENDAR and
	
	Returns the number of days until next Thursday.
	
	** For example: 16th March 2014 (2014, 3, 16), Friday on the 9th March, Friday on the 16th March
	Hence, Sat, Sun, Mon, Tues, Wed, Thurs = 6 days till Thursday
	
	** For example: 15th March 2014 (2014, 3, 15), Friday on the 9th of March, Thursday on 15th March
	Hence, Friday, Sat, Sun, Mon, Tues, Wed, Thurs = 7 days till Thursday
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define START_OF_GREG_CALENDAR 1582


// Declaring isLeapYear function
int isLeapYear (int year);

int main(int argc, const * char argv[]) {

// This code is incomplete and is ONLY meant to be a boilerplate for the Doomsday task.

}


// Function to check whether or not a year is a leap year
int isLeapYear (int year) {
   // Checks if the year modulo 4 is 0, however the year modulo 100 is not 0
   if ((year % 4 == 0) && (year % 100 != 0)) {
   // If this condition matches, it is a leap year
        return 1;
   // Additionally, if the year is divisible by 400 with 0 remainder, it is also a leap year
   } else if ((year % 400 == 0)) {
        return 1;
   // If none of these conditions match, it is not a leap year
   } else {
        return 0;
   }
}

int daysToNextThursday (int year, int month, int day) {
	// Uses the doomsday function to find the doomsday of the given year
	int doomsday = yearToDoomsday (year);
	// Checks if the year which was passed to the daysToNextThursday was a leap year via isLeapYear function
	int leapYear = isLeapYear (year);
	// Returns the day of the week, in which the date given by the user is
	int weekDay = dayOfWeek (doomsday, leapYear, month, day);
	
}