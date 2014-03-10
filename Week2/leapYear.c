// Shubham Shah
// Basic Leap Year Checker
// For the LeapYearProgram Exercise
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define START_OF_GREG_CALENDAR 1582

int main (int argc, const char * argv[]) {
   
   int year;
    
   printf ("please enter the year you are interested in\n");

   scanf("%d", &year);

   // Notice this only works if the year is >= 1582
   // Because the gregorian calendar only came into effect in 1582.

   assert (year >= START_OF_GREG_CALENDAR);

   // Checks if the year modulo 4 is 0, however the year modulo 100 is not 0
   if ((year % 4 == 0) && (year % 100 != 0)) {
   // If this condition matches, it is a leap year
        printf("%d is a leap year!\n", year);
   // Additionally, if the year is divisible by 400 with 0 remainder, it is also a leap year
   } else if ((year % 400 == 0)) {
        printf("%d is a leap year!\n", year);
   // If none of these conditions match, it is not a leap year
   } else {
        printf("%d is not a leap year!\n", year);
   }

   return EXIT_SUCCESS;
}