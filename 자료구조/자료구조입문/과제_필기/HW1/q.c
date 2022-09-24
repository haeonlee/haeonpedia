#include <stdio.h>

int s200874Sorted(int A[], int n);

int main(void)
{
    int A1[5] = { 1, 2, 2, 4, 5 };  // non-decreasing order
    int A2[5] = { 1, 2, 4, 3, 3 };  // non-decreasing order가 아님

    int num1 = s200874Sorted(A1, 5);
    int num2 = s200874Sorted(A2, 5);

    printf("A1의 반환 값: %d\n", num1);
    printf("A2의 반환 값: %d\n", num2);

    return 0;
}

int s200874Sorted(int A[], int n)
{
    if (n > 1)
    {
        if ( A[n-1] >= A[n-2] )     // 뒤부터 비교
        {
            n = n-1;                // n을 하나 줄여서, 재귀 호출할 준비
            s200874Sorted(A, n);    // 재귀 호출
        }

        else
        {
            return 0;               // non-decreasing order가 아님: 0 반환
        }
    }

    else
    {
        return 1;                   // non-decreasing order임: 1 반환
    }
}