/*
DATE: 2022. 03. 18. FRI
PAGE: 34p
주제: 실수형 변수
포인트: 실수형 변수를 선언하고, %f에 실수 값을 넣기
*/

#include <stdio.h>
int main() {
    float a = 3.141592f; 
    /* float형 변수를 선언할 땐, 반드시 숫자 뒤에 f를 붙이자
    why: f를 안 붙이면 double형 변수로 인식하여, 문제가 생길 수 있음 */
    double b = 3.141592;
    printf("a : %f \n", a); // 실수형 변수 출력은 %f
    printf("b : %f \n", b);

    /* 주의: %f로 출력할 땐 언제나 소수점을 뒤에 붙여줄 것 */
    printf("%f", 1.0); // 제대로 출력
    // cf. printf("%f", 1); -> 이렇게 하면 오류 나옴
    return 0;
}