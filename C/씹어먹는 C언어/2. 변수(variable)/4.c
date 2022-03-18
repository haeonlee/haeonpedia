/*
DATE: 2022. 03. 18. FRI
PAGE: 36p
주제: printf의 또 다른 형식
포인트: "%전체자리수.소수점이하자리수" 사용하기
*/

#include <stdio.h>
int main() {
    float a = 3.141592f;
    double b = 3.141592;
    int c = 123;
    printf("a : %.2f \n", a); // 소수점 이하 둘째 자리까지 출력
    printf("c : %5d \n", c); // 숫자의 자리수를 5자리로 출력
    printf("b : %6.3f \n", b); // 전체 자리수(소수점 이하랑 점까지 포함)는 6자리, 소수점 이하 3자리
    return 0;
}

