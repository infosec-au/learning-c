// program demonstrating the use if
// statements in c
// unsw computing 1, week 2
// comp19117.com
 
#include <stdio.h>
#include <stdlib.h>
 
int main (int argc, char *argv[]) {
   int first;
   int second;
 
   first = 8;
   second = 10;

// if first is bigger than 7 and second is less than 3 : Danish happyish\n Flag
// if first is smaller than 7 but second is bigger than 8 : Danish Flag
// if first is smaller than 7 but second is bigger than 4 but smaller than 8 : Sallyish flag


   if (first > 7) {
      printf ("Danish\n");
      if (second < 3) {
         printf ("happy");
      }
   } else {
      if (second > 8) {
         printf ("Dan");
      } else if (second > 4) {
         printf ("Sally");
      } else {
         // print nothing
      }
   }
 
   if (second < 10) {
      printf ("ish\n");
   }
 
   if (first > second) {
      printf ("\nFlag\n");
   } else {
      printf ("Flag\n");
   }
 
   return EXIT_SUCCESS;
}