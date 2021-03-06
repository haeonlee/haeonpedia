// 5-1. if문의 기본 형식

/* 

읽기 쉬운 코드를 위한 규칙: if문

1. 중괄호: 특히, 실행할 문장이 두 문장 이상이면 반드시 중괄호로 묶을 것
2. 들여쓰기

*/

#include <stdio.h>

int main(void)
{
    int a = 20;
    int b = 0;

    if (a> 10)  // 조건식 : a가 10보다 크므로 조건식은 참
    {
        b = a;  // 실행문 : b = a 대입문 실행
    }

    printf("a : %d, b: %d\n", a, b);    // 대입이 수행되면 두 값은 같음

    return 0;
}



/* 실행 결과

a : 20, b: 20

*/