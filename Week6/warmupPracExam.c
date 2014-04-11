// Warm Up Prac Exam
// Shubham Shah
// 8th of April 2014
// Prints a square based off an odd number

#include <stdio.h>
#include <stdlib.h>

#define UNDERSCORE "_"
#define HASH "#"
int main(int argc, char * argv[]) {
    int countPrints = 0;
    int userInput;

    scanf("%d", &userInput);

    while (countPrints != userInput) {
        printf("%s", UNDERSCORE);
        countPrints+=1;
    }
}