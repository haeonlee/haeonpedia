// 6-3. do ~ while문을 사용한 반복문

/*

do ~ while문: 일단 반복할 문장을 수행한 후에 조건을 검사

do
{
    실행문;
} while (조건식);

*이때 반드시 while 마지막에 세미콜론을 넣으세요.

실행 순서
1. 실행문 -> 조건식
2. 조건식 -> 실행문

*/

#include <stdio.h>

int main(void)
{
    int a = 1;

    do
    {
        a = a * 2;
    } while (a < 10);
    printf("a : %d\n", a);

    return 0;
    
}

/* 실행 결과

a : 16

*/