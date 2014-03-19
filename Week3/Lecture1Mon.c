// The encryption of a<=>z and m<=>n
// 17th March 2014
// Shubham Shah

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char encrypt (char plain);
void unitTestMe();

int main (int argc, char * argv[]) {
	//unitTestMe();
	char letterToEncrypt = 'a';
	char encryptedLetter = encrypt (letterToEncrypt);
	printf ("%c encrypted is %c \n", letterToEncrypt, encryptedLetter);
	return EXIT_SUCCESS;
}

char encrypt (char plain) {
	char encrypted;
	encrypted = plain + 25;
	return encrypted;
}

void unitTestMe (void) {
	assert('a' == 'z');
	assert('z' == 'a');
	assert('m' == 'n');
	assert('n' == 'm');
}