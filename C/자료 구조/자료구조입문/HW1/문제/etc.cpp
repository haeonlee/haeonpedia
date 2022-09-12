// HW01
//
// 주의: 아래 작성해야할 부분외 다른 곳을 수정하거나, 코드를 추가하면 0점 입니다.
// 
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

#define EVEN  1
#define ODD   0

#define MALLOC(ptr, type, size) \
// ********************************
// 이 매크로의 나머지 부분을 완성하세요.
// ********************************

#define WRONG_INPUT { \
 fprintf(stderr, "Wrong Input\n"); \
 exit(EXIT_FAILURE); \
}

int** inputArrayData(int R, int* C, int *allocSize) {
	int** L = NULL;
	// ********************************
	// 아래 기능을 갖는 함수를 작성하세요
	// 
	// 입력: row size R (main에서 읽었음)
	//      나머지 data는 입력 파일로부터 읽는다.
	// 출력: 값이 저장된 2차원 배열 L과 column size
	// 1. Column size C를 읽는다.
	// 2. L에 2차원 배열을 할당받는다.
	// 3. 파일에서 배열 값을 읽는다.
	// 4. 데이터가 부족하면 WRONG_INPUT을 호출하여 실행을 중지한다.
	// 5. L과 column size를 반환.
	// ********************************

	return L;
}

int getSumDiff(int** L, int R, int C) {
	int whiteSum = 0, blackSum = 0;
	// ********************************
	// 아래 기능을 갖는 함수를 작성하세요.
	// 
	// 입력: R x C 2차원 정수 배열
	// 계산해야할 값:
	// whiteSum = 체스 보드의 하얀색 칸에 있는 정수들의 합
	// blackSum = 체스 보드의 검정색 칸에 있는 정수들의 합
	// 출력: whiteSum - blackSum을 반환
	// ********************************

	return (whiteSum - blackSum);
}

void freeL2(int** L2, int R, int C, int *allocSize) {
	for (int r = 0; r < R; r++) {
		free(L2[r]);
		*allocSize -= C * sizeof(int);
	}
	free(L2);
	*allocSize -= R * sizeof(int*);
}