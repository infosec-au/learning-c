// Shubham Shah
// 24th March 2014
// Produces the Danish flag using nested while loops

#include <stdio.h>
#include <stdlib.h>

#define DANISH_FLAG_LINE "** *********\n"

void showDanish (void);

int main (int argc, char * argv[]) {
    showDanish();
}

void showDanish (void) {
    int printCount = 0;
    while (printCount < 5) {
        while(printCount < 2) {
            printf(DANISH_FLAG_LINE);
            printCount++;
        }
        if (printCount == 2) {
            printf("\n");
            printCount++;
        }
        printf(DANISH_FLAG_LINE);
        printCount++;
    }
}