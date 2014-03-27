// Shubham Shah
// Leap Year Checker as a Function
// For the isleapyear exercise
// 10th of March 2014
 
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
 
#define START_OF_GREG_CALENDAR 1582
 
int isLeapYear (int year);
 
int main(int argc, char * argv[]) {
    int yearInput;
    int leapYearValue;

    printf("Check whether or not a year, is a leap year (must enter a number over 1582)\n");
    scanf("%d", &yearInput);
    assert(yearInput >= START_OF_GREG_CALENDAR);
    leapYearValue = isLeapYear(yearInput);
    if (leapYearValue == 1) {
        printf("%d is a leap year!\n", yearInput);
    } else {
        printf("%d is not a leap year!\n", yearInput);
    }
    return EXIT_SUCCESS;
}
 
int isLeapYear (int year) {
    int leapYearResult; 
    // Checks if the year modulo 4 is 0, however the year modulo 100 is not 0
    if ((year % 4 == 0) && (year % 100 != 0)) {
    // If this condition matches, it is a leap year
        leapYearResult = 1;
    // Additionally, if the year is divisible by 400 with 0 remainder, it is also a leap year
    } else if ((year % 400 == 0)) {
        leapYearResult = 1;
    // If none of these conditions match, it is not a leap year
    } else {
        leapYearResult = 0;
    }

    return leapYearResult;
}