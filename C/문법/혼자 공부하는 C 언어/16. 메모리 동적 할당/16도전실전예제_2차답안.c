// 16. 메모리 동적 할당

/*

    도전 실전 예제. 소수(prime number) 계산 프로그램

    키보드로 양수를 입력한 후에 입력한 수까지의 모든 소수를 출력합니다.
    2부터 한 줄에 5개씩 출력하며 소수가 아닌 수는 X를 출력합니다.
    입력한 수에 따라 적절한 크기의 배열을 동적 할당하여 사용합니다.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, cnt;
    int num;
    int row = (int)((num + 2) / 5);

    int **matrix = (int **)malloc(sizeof(int *) * row);
    
    for (i=0; i<row; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * 5);
    }

    matrix[0][0] = cnt;
    printf("%d", matrix[0][0]);

    /*

    printf("양수 입력 : ");
    scanf("%d", &num);

    for (i=0; i<row; i++)
    {
        for(j=0; j<5; j++)
        {
            matrix[i][j] = cnt;
            cnt++;
        }
    }

    

    for (i=0; i<row; i++)
    {
        for(j=0; j<5; j++)
        {
            printf("%5d", matrix[i][j]);
        }
    }

    */

   return 0;

}
