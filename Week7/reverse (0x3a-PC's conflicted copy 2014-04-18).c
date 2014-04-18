// Shubham Shah, z5019981, Apr 18th 2014
// Reverses a string given into the program
// Demonstrates the use of malloc()
// COMP1917
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
 
char *reverse (char *message);
 
int main(int argc, char *argv[]) {
    assert(strcmp(reverse("hello"), "olleh") == 0);
    assert(strcmp(reverse("helloooooooooooooooooo"), "oooooooooooooooooolleh") == 0);
    assert(strcmp(reverse("hello man how are you"), "uoy era woh nam olleh") == 0);
    assert(strcmp(reverse("*&^$#@!tset"), "test!@#$^&*") == 0);
    assert(strcmp(reverse("tacocat"), "tacocat") == 0);
    printf("%s\n", reverse("hello"));
}
 
char *reverse (char *message) {
    int lengthOfString = strlen(message);
    int positionOne = 0;
 
    char *reversedString = malloc(lengthOfString--);
    // As the index for reversedString increases,
    // put in contents of the message with a decreased
    // index. Very compact, but still works.
    while (0 <= lengthOfString) {
        reversedString[positionOne++] = message[lengthOfString--];
    }
    reversedString[positionOne] = '\0';
    free(reversedString);
    return reversedString;
}