// Shubham Shah
// Leap year checker
// 6th March 2014

#include <stdio.h>
#include <stdlib.h>

int main (int argc, const char * argv[]) {
	// dateYear is the year being tested. E.g. 2011
	int dateYear;
	
	// isLeapYear indicates whether or not a dateYear is a leap year. 
	// 0 = not a leap year, 1 = a leap year
	
	int isLeapYear = 0;

	// Taking in input from the user for the year to check
	scanf("%d", &dateYear);

	
	// if dateYear can be divided by 4 with no remainder
	// OR if dateYear divided by 400 with no remainder
	// then set isLeapYear to 1
	
	if (dateYear % 4 == 0 || dateYear % 400 == 0) {
		isLeapYear = 1;
		if (dateYear % 100 == 0) {
			// However, if the dateYear is divisible by 100 with no remainder,
			// set isLeapYear back to 0
			isLeapYear = 0;
		}
	}
	// Prints 0 if the input number is not a leap year
	// Prints 1 if the input number is a leap year
	printf("%d", isLeapYear);
}