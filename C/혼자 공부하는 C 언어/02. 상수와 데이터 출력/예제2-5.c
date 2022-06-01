#include <stdio.h>

int main(void)
{
    printf("%d\n", 12); // 10진수 정수 상수 출력
    printf("%d\n", 014); // 8진수 정수 상수 출력
    printf("%d\n", 0xc); // 16진수 정수 상수 출력

    printf("%o\n", 12); // 10진수 12를 8진수로 출력
    printf("%x\n", 12); // 10진수 12를 16진수 소문자로 출력
    printf("%X\n", 12); // 10진수 12를 16진수 대문자로 출력

    return 0;
}