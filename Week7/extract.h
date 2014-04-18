// extract.h
// funtions and types used by extract.c
// richard buckland
// 13 April 2014
// do not alter or submit this file, 
// we'll use our own copy when marking it
 
typedef struct _triordinate {
    double x;
    double y;
    int z;
} triordinate;
 
triordinate extract (char *message);
 
double myAtoD (char *message);
 
long myAtoL (char *message);