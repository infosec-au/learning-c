//
//  main.c
//  memory
//
//  Created by Richard Buckland on 20/11/12.
//
 
#include <stdio.h>
#include <stdlib.h>
 
long add (int x, int y);
 
int main(int argc, const char * argv[]) {
 
   int x;
   int y;
   long x1;
   long x2;
   long total;
   int oflow;
   int uflow;
   long *address;

   // x = 1;
   // address = &x;
   // printf("Value stored at %p is %u\n", address, *address);
   // y = 2;
   // address = &y;
   // printf("Value stored at %p is %u\n", address, *address);


   oflow = -99999999999;
   printf("%d", oflow);
   uflow = -999999;
   printf("%d", uflow);

   x1 = 1;
   address = &x1;
   printf("Value stored at %p is %ld\n", address, *address);
   x2 = 2;
   address = &x2;
   printf("Value stored at %p is %ld\n", address, *address);
   



   x = 40;
   printf("Size of int x where x=2 : %zu\n", sizeof(x));
   y = 2;
   printf("Size of int y where y=2 : %zu\n", sizeof(x));
   total = add (x, y);
   printf("Size of long total where total=x+y: %zu\n", sizeof(total));
 
   printf("the sum of %d and %d is %ld\n", x, y, total);
 
   char c ='a';
   printf("Size of char c where c = 'a': %zu\n", sizeof(c));
   unsigned long ul       = 0;
   printf("Size of unsigned long ul where ul = 0: %zu\n", sizeof(ul));
   unsigned int ui        = 1;
   printf("Size of unsigned int ui where ui = 1: %zu\n", sizeof(ui));
   unsigned long long ull = 2;
   printf("Size of unsigned long long ull where ull = 2: %zu\n", sizeof(ull));
   unsigned short us      = 3;
   printf("Size of unsigned short us where us = 3: %zu\n", sizeof(us));


   signed long sl       = 4;
   printf("Size of signed long sl where sl=4: %zu\n", sizeof(sl));
   signed int si        = 5;
   printf("Size of signed int si where si=5: %zu\n", sizeof(si));
   signed long long sll = 6;
   printf("Size of signed long long sll where sll=6: %zu\n", sizeof(sll));
   signed short ss      = 7;
   printf("Size of signed short ss where ss=6: %zu\n", sizeof(ss));

   long l       = 8;
   printf("Size of long l where l=8: %zu\n", sizeof(l));
   int i        = 9;
   printf("Size of int i where i=9: %zu\n", sizeof(i));
   long long ll = 10;
   printf("Size of long long ll where ll=10: %zu\n", sizeof(ll));
   short s      = 11;
   printf("Size of short s where s=11: %zu\n", sizeof(s));

   float f = 3.1;
   printf("Size of float f where f=3.1: %zu\n", sizeof(f));
   double d = 3.14;
   printf("Size of double d where d=3.14: %zu\n", sizeof(d));

   // add them all together just to make use of them so the compiler
   // doesn't grumble that they are unused in the program

   double grandTotal;
   grandTotal =  c +
                 ul + ui + ull + us +
                 sl + si + sll + ss +
                  l +  i +  ll +  s +
                  f + d;

   printf ("all these things added together make %f\n", grandTotal);

   return EXIT_SUCCESS;
}
 
long add (int x, int y) {
   long answer;
   answer = x + y;

   return answer;
}