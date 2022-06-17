// 08-1. 배열의 선언과 사용
/* 3. 다음과 같이 초기화된 A 배열의 값을 복사하여 B 배열에 채운 후 출력하는 프로그램을 작성해 보세요. */

// MEMO: 코딩하면서 나머지 연산을 은근히 잘 사용하는 것 같다! 잘 기억해 두자.

#include <stdio.h>

int main(void)
{
    int A[3] = {1, 2, 3};
    int B[10];
    int i;

    for (i=0; i<(sizeof(B)/sizeof(B[0])); i++)
    {
        B[i] = A[(i%3)];    // A 배열 인덱스가 0~2를 갖도록 나머지 연산자 사용
    }

    for (i=0; i<(sizeof(B)/sizeof(B[0])); i++)
    {
        printf("%5d", B[i]); // B 배열 출력
    }

    return 0;
}

/* 실행 결과

    1    2    3    1    2    3    1    2    3    1

*/