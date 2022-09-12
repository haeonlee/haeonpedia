// HW01
//
// 이 파일을 수정하거나 뭔가를 추가하면 안됩니다
//
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

int** inputArrayData(int R, int* C, int *allocSize);
int   getSumDiff(int** L, int R, int C);
void  freeL2(int** L2, int R, int C, int* allocSize);

int main(void) {
	int** L2;		// 2d array pointer
	int   R, C;     // R x C array
	int   allocSize;
	int   sumDiff;  // whiteSum - blackSum
	int   T = 0;	// test vector num

	while (scanf("%d", &R) != EOF) {
		L2 = inputArrayData(R, &C, &allocSize);
		sumDiff = getSumDiff(L2, R, C);
		printf("Test %d : sumDiff = %d (mem = %d bytes)\n", ++T, sumDiff, allocSize);
		freeL2(L2, R, C, &allocSize);
		if (allocSize != 0) {
			fprintf(stderr, "Memory size calculation error\n");
			exit(EXIT_FAILURE);
		}
	}
}
