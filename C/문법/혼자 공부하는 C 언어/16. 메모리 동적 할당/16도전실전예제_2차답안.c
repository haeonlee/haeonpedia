// 16. 메모리 동적 할당

/*

    도전 실전 예제. 소수(prime number) 계산 프로그램

    키보드로 양수를 입력한 후에 입력한 수까지의 모든 소수를 출력합니다.
    2부터 한 줄에 5개씩 출력하며 소수가 아닌 수는 X를 출력합니다.
    입력한 수에 따라 적절한 크기의 배열을 동적 할당하여 사용합니다.

*/

/* 아이디어 노트

    소수 판별 함수를 만들까? 프로그램 내에 넣으니까, 너무 조잡한 느낌임.

    int IsPrimeNumber()
        반환값이 0이면, 소수가 아님
        반환값이 1이면, 소수임

*/

#include <stdio.h>
#include <stdlib.h>

int IsPrimeNumber(int num);

int main(void)
{
    int num;                                // 입력값 num

    printf("양수 입력 : ");
    scanf("%d", &num);

    int height = (int)((num + 2) / 5);      // 행렬에서 행 부분을 수식으로 표현
    int i, j;                               // for문 구동을 위한 변수 i, j;
    int count = 2;
    int count2 = 2;

    char **matrix = (char **)malloc(sizeof(char *) * height);

    for (i=0; i<height; i++)
    {
        matrix[i] = (char *)malloc(sizeof(char) * 5);
    }

    for (i=0; i<height; i++)
    {
        for (j=0; j<5; j++)
        {
            if (count == num) break;

            if (IsPrimeNumber(num) == 0)
            {
                matrix[i][j] = count;
            }

            if (IsPrimeNumber(num) == 1)
            {
                matrix[i][j] = 'X';
            }

            count++;
        }
    }

    for (i=0; i<height; i++)
    {
        for (j=0; j<5; j++)
        {
            if (count2 == num) break;
            printf("%5d", matrix[i][j]);
            count2++;
        }
        printf("\n");
    }

    for (j=0; j<5; j++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;

}

int IsPrimeNumber(int num)
{
    int i, count;

    for (i=2; i<num; i++)
    {
        if (num % 1 == 0)
        {
            count++;
            return 1;
        }
    }

    return 0;
}

/* 실행 결과

양수 입력 : 30
   88   88   88   88   88
   88   88   88   88   88
   88   88   88   88   88
   88   88   88   88   88
   88   88   88   88   88
   88   88   88

잉? 뜬금포로 88이 출력됨...
너는 도대체 어디서 나온 녀석이니?

*/

