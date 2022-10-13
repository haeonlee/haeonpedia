#include <stdio.h>

int s200874Sorted(int A[], int n);

int main(void)
{
    int A1[5] = { 1, 2, 2, 4, 5 };
    int A2[5] = { 1, 2, 4, 3, 3 };

    int num = s200874Sorted(A2, 5);

    printf("반환 값: %d\n", num);

    return 0;
}

int s200874Sorted(int A[], int n)
{
    if (n > 1)
    {
        printf("%d >= %d\n", A[n-1], A[n-2]);
        if ( A[n-1] >= A[n-2] ) // 뒤부터 비교
        {
            n = n-1;            // n을 하나 줄여서, 재귀 호출할 준비
            printf("다음에 계산할 n은 : %d\n", n);
            s200874Sorted(A, n);
            printf("비정상적인 출력입니다.\n");
            return -1;
        }

        else
        {
            printf("줄어드는 정렬입니다.\n");
            return 0;
        }
    }

    else
    {
        printf("줄어들지 않는 정렬입니다.\n");
        return 1;
    }
}