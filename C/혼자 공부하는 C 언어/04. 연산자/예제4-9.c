// 4-9. sizeof 연산자의 사용 예

/*

sizeof연산자

피연산자의 크기를 바이트 단위로 계산해서 알려줌
피연산자 개수: 1개
피연산자의 대상: 변수, 상수, 수식, 자료형, 배열, 문자열 등

*/

#include <stdio.h>

int main(void)
{
    int a = 10;
    double b = 3.4;

    printf("int형 변수의 크기 : %d\n", sizeof(a));
    printf("double형 변수의 크기 : %d\n", sizeof(b));
    printf("정수형 상수의 크기 : %d\n", sizeof(10)); // 4바이트로 표현할 수 없는 상수를 넣으면 8바이트가 되기도 함
    printf("수식의 결괏값의 크기 : %d\n", sizeof(1.5 + 3.4)); // 결괏값이 실수이므로 8바이트, 정수 연산식이면 결괏값 크기가 4바이트 되기도 함
    printf("char 자료형의 크기 : %d\n", sizeof(char));
    printf("문자열의 크기 : %d\n", sizeof("A")); // 끝에 널 문자 \0이 삽입되므로 2바이트
    printf("문자열의 크기 : %d\n", sizeof("ABCD"));

    return 0;
}

/* 실행 결과

int형 변수의 크기 : 4
double형 변수의 크기 : 8
정수형 상수의 크기 : 4
수식의 결괏값의 크기 : 8
char 자료형의 크기 : 1
문자열의 크기 : 2
문자열의 크기 : 5

*/
