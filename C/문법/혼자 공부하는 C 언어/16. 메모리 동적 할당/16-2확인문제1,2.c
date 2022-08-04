// 16-2. 동적 할당 저장 공간의 활용

/* 

    문제 바로 아래에 답안을 쓰도록 하겠습니다.
    내 답안은 아래서 볼 수 있지만, 아예 다르게 풀었다.
    여러 개념들이 중첩돼서 꼬인 것 같다. 특히 포인터랑 배열 개념이 엉망이다.
    복습을 하긴 해야 하는데, 일단 19과까지 다 끝내고 생각하자.

    확인 문제 1. 4행 5열의 행렬의 값을 저장할 2차원 배열을 동적 할당하는 코드를 작성하세요.

        int **matrix = (int **)malloc(4 * sizeof(int *));
        // 포인터 배열로 사용할 공간의 동적 할당
        for (i = 0; i < 4; i++)
        {
            matrix[i] = (int *) malloc(5 * sizeof(int));
            // 각 행을 동적 할당하여 포인터 배열에 연결
        }

    확인 문제 2. 1번에서 만든 동적 할당 영역을 반환하는 코드를 작성하세요.

        for (i = 0; i < 4; i++)     // 각 행의 동적 할당 영역 반환
        {
            free(matrix[i]);
        }
        free(matrix);               // 포인터 배열로 사용한 동적 할당 영역 반환

    
    아이디어 기록
    - 일단은 배열[4][5]로 포인터 선언하고, 동적 할당 공간으로 각 4byte 선언하기
    - 물론, for문을 써야 하겠지요?
    - 그리고 다른 함수 만들어서 matrix로 이중 포인터 매개변수로 쓰고...
    - 각각 저장할 수 있도록 쓰기 함수 쓰세용

    - 반환 함수도 for문 써서 사용하세요

*/


// 아래는 내 답안

#include <stdio.h>
#include <stdlib.h>

void write_num(int **matrix);

int main(void)
{
    int *pa[4][5];
    int i, j;

    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            pa[i][j] = (int *)malloc(sizeof(int));
        }
    }

    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            free(pa[i][j]);
        }
    }
}

void write_num(int **matrix)
{
    int num;
    int i, j;

    printf("값을 입력하세요 : ");
    scanf("%d", &num);

    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            matrix[i][j] = num;
        }
    }
}

