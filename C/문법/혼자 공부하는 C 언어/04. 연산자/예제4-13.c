// 4-13. 비트 연산식의 결과

/*

비트 연산자: 데이터를 비트 단위로 연산, 데이터를 비트로 정확히 표현할 수 있는 정수에만 사용 가능
    비트 논리 연산자: &, |, ^
    비트 이동 연산자: >>, <<

c.f. 비트 연산자는 복합대입 연산자로 이용 가능함
    기호: &=, |=, ^=, >>=, <<=
    e.g. a = a << 2;를 a <<= 2; 와 같이 사용 가능함

*/

#include <stdio.h>

int main(void)
{
    int a = 10; // 비트열 00000000 00000000 00000000 00001010
    int b = 12; // 비트열 00000000 00000000 00000000 00001100

    printf("a & b : %d\n", a & b);  // 비트별 논리곱 연산자: 두 비트 다 1일 때만 1
    printf("a ^ b : %d\n", a ^ b);  // 비트별 배타적 논리합 연산자: 두 비트가 서로 다른 경우만 1
    printf("a | b : %d\n", a | b);  // 비트별 논리합 연산자: 두 비트 중 하나만 1이어도 1
    printf("~a : %d\n", ~a);    // 비트별 부정 연산자: 1은 0으로, 0은 1로
    printf("a << 1 : %d\n", a << 1);    // 우측으로 1칸 이동, 오른쪽 남는 비트는 0으로 채워짐
    printf("a >> 2 : %d\n", a >> 2);    // 좌측으로 2칸 이동, 왼쪽 남는 비트는 부호 비트로 채워짐
                                        // 따라서 양수는 0, 음수는 1로 채워짐
                                        // unsigned형이라면 부호 비트는 의미 없으므로 항상 0으로 채워짐

    return 0;
}

/* 실행 결과

a & b : 8
a ^ b : 6
a | b : 14
~a : -11
a << 1 : 20
a >> 2 : 2

*/