// B. 선택 정렬 알고리즘
// B-1. 배열의 값을 오름차순으로 정렬

/*

    정렬은 데이터를 일정한 규칙에 따라 나열합니다.

        (1) 오름차순 정렬(ascending sort): 작은 값부터 큰 값 순서로 나열
        (2) 내림차순 정렬(selection sort): 큰 값부터 정렬

*/

#include <stdio.h>

int main(void)
{
    int a[5] = { 3, 2, 1, 6, 5 };
    int i, j, temp;

    for (i = 0; i < 4; i++)         // 가장 작은 값을 구하는 과정 반복 횟수
    {
        for ( j = i + 1; j < 5; j++ )   // 첫 번째 비교 대상은 기준 요소 다음부터 시작
        {
            if (a[i] > a[j])        // 기준 요소 a[i]와 나머지 요소 a[j] 비교
            {
                temp = a[i];        // 교환 작업
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        printf("%5d", a[i]);
    }

    return 0;

}

/* 실행 결과

    1    2    3    5    6

*/