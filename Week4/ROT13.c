// Shubham Shah
// 27th March 2014
// ROT13 Encryption program
// Each character gets shifted 13 letters
// Where a => z (a maps to z)

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

char encode (char letter);
void testEncode ();
int main (int argc, char * argv[]) {
    testEncode();
    return EXIT_SUCCESS;
}

char encode (char letter) {
    char encodedLetter = letter;


    if ((encodedLetter >= 'A' && encodedLetter <= 'Z')) {
        if (encodedLetter < 'N') {
            encodedLetter +=13;
        } else if (encodedLetter >= 'N') {
            encodedLetter -=13;
        }
    } else if ((encodedLetter >= 'a' && encodedLetter <= 'z')) {    
        if (encodedLetter >= 'n') {
            encodedLetter -= 13;
        } else if (encodedLetter < 'n') {
            encodedLetter += 13;
        }
    } else {
        encodedLetter = letter;
    }

    return encodedLetter;

}

void testEncode (void) {
    assert (encode ('a') == 'n');
    assert (encode ('n') == 'a');
    assert (encode ('f') == 's');
    assert (encode ('A') == 'N');
    assert (encode ('N') == 'A');
    assert (encode ('F') == 'S');
    printf("%s", "All tests passed!\n");
}
