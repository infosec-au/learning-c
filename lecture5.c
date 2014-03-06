// Shubham Shah
// Lecture 5 code
// Simple C Syntax

#include <stdio.h>
#include <stdlib.h>

int main (int argc, const char * argv[]) {
	printf("Hello, World\n");

	int magicNumber;
	
	magicNumber = 4;
	magicNumber = 9001;

	scanf("%d", &magicNumber);
	if (magicNumber > 9000) {
		// printf("I like Danes!\n");
		if (magicNumber <= 9001) {
			// printf("I really love you man!\n");
		} else {
			printf("You guessed wrong!\n");
		}
	}
	
	printf("the magic number is %d\n", magicNumber);
	return EXIT_SUCCESS;
}