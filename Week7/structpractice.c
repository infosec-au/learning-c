// Some code demonstrating the usage of structs
// Felt like I needed to revisit them
// #real-talk, #Cshouldnthavehashtagsceptfordefines
// Shubham Shah on the 17th of April 2014

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
    // Typedef's are like templates which
    // can group different types together
    // They are cool.
    
    typedef struct _twitter {
        char *hashtag1;
        char *hashtag2;
        char *hashtag3;
    } twitter;

    twitter realtalk;

    realtalk.hashtag1 = "#realtalk";
    realtalk.hashtag2 = "#eshay";
    realtalk.hashtag3 = "#eshayadlay";

    printf("OMG! %s, Twitter is for %s. %s.\n", realtalk.hashtag3, realtalk.hashtag1, realtalk.hashtag2);

    twitter faketalk = {"#forrealz", "#faketalk", "#hekker"};

    printf("aye bro are u %s, u sure u aint %s? Are u a %s?\n", faketalk.hashtag1, faketalk.hashtag2, faketalk.hashtag3);

    return EXIT_SUCCESS;
}