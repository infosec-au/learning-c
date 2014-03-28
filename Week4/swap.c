// Shubham Shah
// 27th March 2014
// Takes in two integers "first" and "second" and then swaps them
// For Example:
// first = 5 and second = 9, after swap, it would be:
// first = 9 and second = 5
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap (int* first, int* second);
void swapUnitTests ();

int main (int argc, char * argv[]) {
    swapUnitTests();
    return EXIT_SUCCESS;
}

void swap (int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void swapUnitTests () {
    int first = 5;
    int second = 9;
    swap (&first, &second);
    assert (first == 9);
    assert (second == 5);
}
