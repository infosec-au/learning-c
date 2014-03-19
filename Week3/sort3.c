// Shubham Shah
// Takes in three inputs e.g. "8 5 2" and sorts them, each number on a newline
// 18th March 2014

#include <stdio.h>
#include <stdlib.h>

int sortNumbers (int numberToSort1, int numberToSort2, int numberToSort3);

int main (int argc, char * argv[]) {
	// Assigning integers for the three user inputs
	int numberToSort1;
	int numberToSort2;
	int numberToSort3;
	// Taking user input, and assigning above variables their respective values
	scanf ("%d %d %d", &numberToSort1, &numberToSort2, &numberToSort3);
	// Passing variable data for all three numbers into sortNumbers function
	
	sortNumbers (numberToSort1, numberToSort2, numberToSort3);

}

int sortNumbers (int numberToSort1, int numberToSort2, int numberToSort3) {
	// Declaring variables which will hold sorted values in ASC format
	int sortedNumber1;
	int sortedNumber2;
	int sortedNumber3;

	// A series of arithmetic checks lie below to confirm the order of the numbers

	if (numberToSort1 <= numberToSort2 && numberToSort1 <= numberToSort3) {
		sortedNumber1 = numberToSort1;
	}
	if (numberToSort2 <= numberToSort1 && numberToSort2 <= numberToSort3) {
		sortedNumber1 = numberToSort2;
	}
	if (numberToSort3 <= numberToSort1 && numberToSort3 <= numberToSort2) {
		sortedNumber1 = numberToSort3;
	}

	if (numberToSort1 >= numberToSort2 && numberToSort1 >= numberToSort3) {
		sortedNumber3 = numberToSort1;
	}
	if (numberToSort2 >= numberToSort1 && numberToSort2 >= numberToSort3) {
		sortedNumber3 = numberToSort2;
	}
	if (numberToSort3 >= numberToSort1 && numberToSort3 >= numberToSort2) {
		sortedNumber3 = numberToSort3;
	}

	if (numberToSort1 <= numberToSort2 && numberToSort1 >= numberToSort3) {
		sortedNumber2 = numberToSort1;
	}
	if (numberToSort2 <= numberToSort1 && numberToSort2 >= numberToSort3) {
		sortedNumber2 = numberToSort2;
	}
	if (numberToSort3 <= numberToSort1 && numberToSort3 >= numberToSort2) {
		sortedNumber2 = numberToSort3;
	}

	if (numberToSort1 >= numberToSort2 && numberToSort1 <= numberToSort3) {
		sortedNumber2 = numberToSort1;
	}
	if (numberToSort2 >= numberToSort1 && numberToSort2 <= numberToSort3) {
		sortedNumber2 = numberToSort2;
	}
	if (numberToSort3 >= numberToSort1 && numberToSort3 <= numberToSort2) {
		sortedNumber2 = numberToSort3;
	}

	// Prints sorted values in ascending order

	printf ("%d\n%d\n%d\n", sortedNumber1,sortedNumber2,sortedNumber3);

	return EXIT_SUCCESS;

}