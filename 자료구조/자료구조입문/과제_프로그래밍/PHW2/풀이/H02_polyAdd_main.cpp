#include "H02_polyAdd.h"

int allocSize;	   // size of the allocated memory for each test
int allocSizeMax;  // max allocated mem size among those of all tests
				   // 모든 테스트 중에서 최대로 크게 할당된 메모리 사이즈

int main(void) {
	int T;	// T : # of test cases
	int  nA, nB, nD = 0; // # of terms for each polynomial
	polyPtr A, B, D = NULL; // (coef, expon) array header

	if (scanf("%d", &T) == EOF)		// read # of test cases
		WRONG_INPUT	// empty input file

	allocSizeMax = 0;
	for (int t = 1; t <= T; t++) {
		allocSize = 0;

		readPolyAB(&nA, &A, &nB, &B);	// read A and B

		nD = allocPolyD(nA, A, nB, B, &D);		// allcate D as needed

		if (allocSizeMax < allocSize)
			allocSizeMax = allocSize;		// renewal of max alloc size

		addPoly(nA, A, nB, B, nD, D);		// D = A + B

		printPoly(t, nA, A, nB, B, nD, D);	// print the result

		freeAllocMemory(nA, &A, nB, &B, nD, &D);
	}
	printf("\nMax allocated memory size = %d bytes\n", allocSizeMax);
	return(EXIT_SUCCESS);
}

void printPoly(int t, int nA, polyPtr A, int nB, polyPtr B, int nD, polyPtr D) {
	if (t > 1) { 
		printf("\n");
	}
	printf("Test %d\n", t);
	printPolyS(nA, A, "A");
	printPolyS(nB, B, "B");
	printPolyS(nD, D, "D = A + B");
}

void printPolyS(int np, polyPtr P, const char *polyName) {
	printf("Polynomial %s : ",polyName);
	if (np == 0) {
		printf("zero polynomial\n");
	}
	else {
		printf("terms = %d\n", np);
		if (P[0].expon == 0)
			printf("%d", P[0].coef);
		else if (P[0].expon == 1)
			printf("%dX", P[0].coef);
		else
			printf("%dX^%d", P[0].coef, P[0].expon);

		for (int i = 1; i < np; i++) {
			if (P[i].expon == 0)
				printf("%+d", P[i].coef);
			else if (P[i].expon == 1)
				printf("%+dX", P[i].coef);
			else
				printf("%+dX^%d", P[i].coef, P[i].expon);

		}
		printf("\n");
	}
}

void freeAllocMemory(int nA, polyPtr* pA, int nB, polyPtr* pB,
	int nD, polyPtr* pD) {
	free(*pA);
	free(*pB);
	free(*pD);
	allocSize -= nA * sizeof(poly);
	allocSize -= nB * sizeof(poly);
	allocSize -= nD * sizeof(poly);
	*pA = *pB = *pD = NULL;
	if (allocSize != 0) {
		fprintf(stderr, "Memory size calculation error\n");
		//exit(EXIT_FAILURE);
	}
}