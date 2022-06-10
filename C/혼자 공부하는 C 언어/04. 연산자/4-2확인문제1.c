// 4-2
// 1. short형과 long형의 자료형의 크기를 비교하여 크기가 큰 자료형이 무엇인지 출력하세요.

#include <stdio.h>

int main(void)
{
    int res;    // 결과 변수

    res = ( sizeof(short) > sizeof(long) ) ? 1 : 0;
    // sizeof의 피연산자로 자료형의 이름을 사용하여 크기를 바이트 단위로 계산한다
    // short형의 크기가 long형보다 크면 참이므로 1, 그렇지 않으면 0을 res에 저장한다

    printf("%s\n", ((res = 0) ? "short" : "long"));
    
    return 0;
}