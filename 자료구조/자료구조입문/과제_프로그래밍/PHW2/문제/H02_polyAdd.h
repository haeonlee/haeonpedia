#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(ptr, type, size) \
 if (!((ptr)=(type)malloc(size))) {\
   printf("Insufficient memory"); \
   exit(EXIT_FAILURE); \
 }

#define COMPARE(x, y) \
  (((x)<(y)) ? -1 : ((x) == (y)) ? 0 : 1)

#define WRONG_INPUT { \
 printf("Wrong Input\n"); \
 exit(EXIT_FAILURE); \
}

typedef struct {
	int coef;
	int expon;
} poly;
typedef poly* polyPtr;

// read polynomials A and B from the input
void readPolyAB(int* pnA, polyPtr *pA, int* pnB, polyPtr *pB);

// Allocate storage for the resuting polynomial D (= A + B)
int  allocPolyD(int nA, polyPtr A, int nB, polyPtr B, polyPtr* pD);

// Calcuate A+B and store the result to D
void addPoly(int nA, polyPtr A, int nB, polyPtr B, int nD, polyPtr D);

// free allocated memeory for A, B, and D
void freeAllocMemory(int nA, polyPtr* pA, int nB, polyPtr* pB,
	 int nD, polyPtr* pD);

// see
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170
void printPoly(int t, int nA, polyPtr A, int nB, polyPtr B, int nD, polyPtr D);
void printPolyS(int np, polyPtr P, const char* polyName);