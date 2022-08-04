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

            if (IsPrimeNumber(count) == 0)
            {
                matrix[i][j] = count;
            }

            if (IsPrimeNumber(count) == 1)
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

            if (matrix[i][j] == 'X')
            {
                printf("%5c", matrix[i][j]);
            }

            else
            {
                printf("%5d", matrix[i][j]);
            }
            

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
        if (num % i == 0)
        {
            return 1;
        }
    }

    return 0;
}