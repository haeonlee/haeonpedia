// 4-1. 대입, 덧셈, 뺄셈, 곱셈, 음수 연산

/*

산술 연산자
    종류: 더하기(+), 빼기(-), 곱하기(*), 나누기(/), 나머지(%)
    피연산자 개수: 2개의 피연산자 (단, - 연산자는 부호 바꾸는 역할할 땐 1개 피연산자)

대입 연산자(=)
    이용: 오른쪽 수식(e.g. 상수, 변수, 연산자 등 모두 포함)의 결과를 왼쪽 변수에 저장한다

*/

#include <stdio.h>

int main(void)
{
    int a, b;
    int sum, sub, mul, inv;

    a = 10; // 대입 연산(=)
    b = 20; // 대입 연산(=)
    sum = a + b ; // 더하기 연산(+) 후 대입 연산(=)
    sub = a - b ; // 빼기 연산(-) 후 대입 연산(=)
    mul = a * b ; // 곱하기 연산(*) 후 대입 연산(=)
    inv = -a ; // 음수 연산(-) 후 대입 연산(=)

    printf("a의 값 : %d, b의 값 : %d\n", a, b);
    printf("덧셈 : %d\n", sum);
    printf("뺄셈 : %d\n", sub);
    printf("곱셈 : %d\n", mul);
    printf("a의 음수 연산 : %d\n", inv);

    return 0;
}

/* 실행 결과

a의 값 : 10, b의 값 : 20
덧셈 : 30
뺄셈 : -10
곱셈 : 200
a의 음수 연산 : -10

*/