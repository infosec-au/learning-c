#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
    // Creates array with 26 spaces
    // Sets all frequencies to 0 for all letters
    int frequency[26] = {0};
    float letterCount = 0.0;
    int ch;
    float proportion;
     
     
    while (1) {
        ch = getchar();
        if (ch == EOF) {
            break; // breaks aren't officially allowed, but eh y not
        }
     
        // Assuming input from a-z or A-Z
        if ('a' <= ch && ch <= 'z') {      
            frequency[ch-'a']++;
            letterCount++;
        }
        else if ('A' <= ch && ch <= 'Z') {
            frequency[ch-'A']++;
            letterCount++;
        }
    }

    for (ch = 0; ch < 26; ch++) {
        proportion = (frequency[ch] / letterCount) * 100;
        printf("[+] %c occurs %d amount of times : %f percent of the contents.\n", (ch+97), frequency[ch], proportion);
    }
}