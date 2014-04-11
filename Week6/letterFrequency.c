#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
    // Creates array with 26 spaces
    // Sets all frequencies to 0 for all letters
    int frequency[26] = {0};
    double letterCount = 0.0;
    int ch;
    double proportion;
    int byteSize = 0;
    int lowerLetterCount = 0;
    int upperLetterCount = 0;
    int lfCount = 0;
    double vowelProportion = 0;
    double vowelCount = 0;
    double letterKCount = 0.0;
     
    while (1) {
        ch = getchar();
        if (ch == EOF) {
            break; // breaks aren't officially allowed, but eh y not
        }
        byteSize++;
        // Assuming input from a-z or A-Z
        if ('a' <= ch && ch <= 'z') {      
            frequency[ch-'a']++;
            letterCount++;
            lowerLetterCount++;
        } else if ('A' <= ch && ch <= 'Z') {
            frequency[ch-'a']++;
            letterCount++;
            upperLetterCount++;
        } else if (ch == 10) {
            lfCount++;
        }
        if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U') {
            vowelCount++;
        }
        if (ch == 'k' || ch == 'K') {
            letterKCount++;
        }

    }

    for (ch = 0; ch < 26; ch++) {
        
        proportion = (frequency[ch] / letterCount) * 100;
        printf("[+] %c occurs %d amount of times : %f percent of the contents.\n", (ch+97), frequency[ch], proportion);
    }
    printf("Total Byte Size was: %d\n", byteSize);
    printf("Total lowercase letters: %d\n", lowerLetterCount);
    printf("Total uppercase letters: %d\n", upperLetterCount);
    printf("Total number of LF characters: %d\n", lfCount);
    vowelProportion = (vowelCount / letterCount) * 100;
    printf("Vowel proportion: %f\n", vowelProportion);
    printf("k or K count: %f\n", (letterKCount / letterCount) * 100);
    // (frequency[0] + frequency[4] + frequency[8] + frequency[14] + frequency[20])
}