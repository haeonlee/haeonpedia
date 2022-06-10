// 4-10. 복합대입 연산자

/*

복합 대입 연산자: 연산 결과를 다시 피연산자에 저장
기호: +=, -=, *=, /=, %=

*/

#include <stdio.h>

int main(void)
{
    int a = 10, b= 20;
    int res = 2;

    a += 20; // a와 20을 더해서 a에 저장(+=)
    res *= b + 10; // b에 10을 더한 결괏값에 res를 곱해서 res에 저장

    printf("a = %d, b = %d\n", a, b);
    printf("res = %d\n", res);

    return 0;

}

/* 실행 결과 

a = 30, b = 20
res = 60

*/