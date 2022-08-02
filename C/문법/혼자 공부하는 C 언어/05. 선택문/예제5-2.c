// 5-2. if ~ else문의 사용

/* 

if ~ else문의 규칙

    1. if ~ else문의 else에는 조건을 사용하지 않습니다
    2. 중괄호 사용: 실행할 문장이 두 문장 이상이면 반드시 중괄호로 묶을 것
    3. 경우에 따라 if문 두 번을 사용하는 것보다 if ~ else문을 한 번 사용하는 것이 좋다:
    왜냐면 if ~ else를 쓰면 검사를 한 번만 하니까

*/

#include <stdio.h>

int main(void)
{
    int a = 10;

    if (a >= 0)
    {
        a = 1;  // a가 0보다 크거나 같으면 a에 1 대입
    }
    else
    {
        a = -1; // a가 0보다 작으면 a에 -1 대입
    }

    printf("a : %d\n", a);

    return 0;
}

/* 실행 결과

a : 1

*/