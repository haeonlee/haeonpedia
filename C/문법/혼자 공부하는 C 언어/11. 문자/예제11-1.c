// 11-1. 대문자를 소문자로 변경

#include <stdio.h>

int main(void)
{
    char small, cap = 'G';

    if ((cap >= 'A') && (cap <= 'Z'))   // 대문자 범위라면
    {
        small = cap + ('a' - 'A');  // 대소문자의 차이를 더해 소문자로 변환
    }

    printf("대문자 : %c %c", cap, '\n');    // '\n'을 %c로 출력하면 줄이 바뀐다
    printf("소문자 : %c", small);

    return 0;
}

/* 실행 결과

대문자 : G 
소문자 : g

*/