#include <stdio.h>

int main(void)
{
    int ary1[4] = { 1, 2, 3, 4 };   // 1차원 배열의 선언과 초기화
    int ary2[4] = { 11, 12, 13, 14 };
    int ary3[4] = { 21, 22, 23, 24 };

    int *pary[3] = { ary1, ary2, ary3 };    // 포인터 배열에 각 배열명 초기화

    int i, j;
    int whiteSum = 0, blackSum = 0;

    for (i=0; i<3; i+=2)	// whiteSum 계산을 위한 for문 (1)
	{
		for (j=0; j<4; j+=2)
		{
			whiteSum += pary[i][j];
		}
	}

	for (i=1; i<3; i+=2)	// whiteSum 계산을 위한 for문 (2)
	{
		for (j=1; j<4; j+=2)
		{
			whiteSum += pary[i][j];
		}
	}

	for (i=0; i<3; i+=2)	// blackSum 계산을 위한 for문 (1)
	{
		for (j=1; j<4; j+=2)
		{
			blackSum += pary[i][j];
		}
	}

	for (i=1; i<3; i+=2)	// blackSum 계산을 위한 for문 (2)
	{
		for (j=0; j<4; j+=2)
		{
			blackSum += pary[i][j];
		}
	}




/*
	for (i=0; i<3; i+=2)	// whiteSum 계산을 위한 for문
	{
		for (j=0; j<4; j+=2)
		{
            printf("whiteSum 출력 시작\n");
            printf("%d, %d, %d\n", i, j, pary[i][j]);
			whiteSum += pary[i][j];
		}
	}


	for (i=1; i<3; i+=2)	// blackSum 계산을 위한 for문
	{
		for (j=1; j<4; j+=2)
		{
            printf("blackSum 출력 시작\n");
            printf("%d, %d, %d\n", i, j, pary[i][j]);
			blackSum += pary[i][j];
		}
	}
*/

    printf("%d\n", whiteSum);
    printf("%d\n", blackSum);
    printf("%d\n", whiteSum - blackSum);

	return 0;
}