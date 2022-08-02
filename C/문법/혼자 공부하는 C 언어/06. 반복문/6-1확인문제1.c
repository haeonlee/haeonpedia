// 06-1. while문, for문, do ~ while문
// 확인문제1. 다음 그림과 실행 순서가 같도록 반복문을 작성하세요.

// do ~ while문의 사용: 일단 입력은 받고, 조건식에 대하여 판단할 때 요긴하다!

#include <stdio.h>

int main(void)
{
    int a;

    do
    {
    scanf("%d", &a);
    } while( a < 0);
}

/* 내 답변: do ~ while문을 써야 하는데 while문을 씀

int a = -1; // while문을 실행은 해야 하니까 일단 0보다 작은 값 아무 거나 넣음

    while ( a < 0)
    {
        scanf("%d", &a);
    }

    return 0;

*/