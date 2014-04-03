#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LONG_STRING  "abcdefghijklmnopqrstuvwxyz\n"
#define SHORT_STRING "abcdefghij\n"

int main (int argc, char * argv[]) {
    char  *message = LONG_STRING;
    int len_long_string;
    int len_short_string;

    len_long_string = strlen(LONG_STRING);
    len_short_string = strlen(SHORT_STRING);

    printf("%s", message);
    printf("%p\n", message);
    printf("%d\n", len_long_string);
    printf("%d\n", len_short_string);
}