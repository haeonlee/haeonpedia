// 4-3. 증감 연산자의 연산

/*

증가 연산자(++)
    (a = a + 1)을 ++a; 로 간단하게 표현 가능
    활용: for문, while문, do while문 같은 반복문

감소 연산자(--)
    (a = a - 1)을 --a;로 간단하게 표현 가능

*/

#include <stdio.h>

int main(void)
{
    int a = 10, b = 10;

    ++a;
    --b;

    printf("a : %d\n", a);
    printf("b : %d\n", b);

    return 0;
}

/* 실행 결과

a : 11
b : 9

*/