// 15-6. 2차원 배열의 값을 출력하는 함수

/*

    2차원 배열 요소의 두 가지 의미

        int ary[3][4];
        (1) 논리적 배열 요소의 개수는? 3개
        (2) 물리적 배열 요소의 개수는? 12개
    

    2차원 배열의 요소를 참조하는 원리 (p. 432 참고)
        
        2차원 배열은 1차원 배열과 같이 모든 저장 공간이 메모리에 연속으로 할당됩니다.
        이 공간을 2차원의 논리적 공간으로 사용할 수 있는 것은 배열명이 1차원 배열의 주소로,
        1차원 배열 전체를 가리키기 때문입니다.
        따라서 배열 포인터를 쓰면 1차원 물리적 공간을 2차원의 논리적 구조로 사용할 수 있습니다.
        
*/

#include <stdio.h>

void print_ary(int (*)[4]);

int main(void)
{
    int ary[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    print_ary(ary); // 배열명을 인수로 주고 함수 호출
    // 2차원 배열명을 인수로 주면 함수에는 첫 번째 부분 배열의 주소가 전달
    // 따라서, 이 값을 저장하기 위한 매개변수로 포인터를 선언해야 함

    return 0;
}

void print_ary(int (*pa)[4])   // 매개변수는 배열 포인터
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pa[i][j]);    // pa를 2차원 배열처럼 사용
        }

        printf("\n");
    }
}

/* 실행 결과

    1    2    3    4
    5    6    7    8
    9   10   11   12

*/