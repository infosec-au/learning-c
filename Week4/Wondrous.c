// Shubham Shah
// 23rd of March 2014
// Generates a wondrous sequence based off a single number input

// E.g.
// Input: 3
// Output: 3 10 5 16 8 4 2 1

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int printWondrous (int start);

int main (int argc, char * argv[]) {
    printWondrous (1);
    printWondrous (2);
    printWondrous (3);
    printWondrous (4);
    printWondrous (5);
    return EXIT_SUCCESS;
}

int printWondrous (int start) {
    int nextTerm = start;
    // Starts at 1 since it assumes that 1 term is already passed in
    int sequenceCount = 1;

    if (start == 1) {
            printf("%d\n", start);
    } else if (start != 1) {
            printf("%d ", nextTerm);
            while ((nextTerm != 0)) {
                if (nextTerm % 2 == 0 && nextTerm !=0) {
                    nextTerm = (nextTerm / 2);
                    if (nextTerm == 1) {
                        printf("%d\n", nextTerm);
                        // Set nextTerm to 0 to terminate loop
                        nextTerm = 0;
                        sequenceCount++;
                    } else {
                        printf("%d ", nextTerm);
                        sequenceCount++;
                    }
                    
                }
                if ((nextTerm % 2 != 0)) {
                    nextTerm = (nextTerm * 3 + 1);
                    if (nextTerm == 1) {
                        printf("%d\n", nextTerm);
                        sequenceCount++;
                    } else {
                        printf("%d ", nextTerm);
                        sequenceCount++;
                    }
                    
                }
            }
    }

    
    return sequenceCount;
}
