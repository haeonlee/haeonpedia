// 4-5. 관계 연산의 결괏값 확인

/*

대소 관계 연산자
- 기호: < 또는 > 를 사용
- 피연산자 개수: 2개
- 연산의 결괏값: 1 또는 0

동등 관계 연산자
- 기호: ==(같다) 또는 !=(같지 않다) 를 사용
- 피연산자 개수: 2개
- 연산의 결괏값: 1 또는 0

*/

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20, c = 10;
    int res; // 결괏값을 저장할 변수

    res = (a > b); // 10 > 20은 거짓이므로 결괏값은 0
    printf("a > b : %d\n", res);
    res = (a >= b); // 10 >= 20은 거짓이므로 결괏값은 0
    printf("a > b : %d\n", res);
    res = (a < b); // 10 < 20은 참이므로 결괏값은 1
    printf("a < b : %d\n", res);
    res = (a <= b); // 10 <= 20은 참이므로 결괏값은 1
    printf("a > b : %d\n", res);
    res = (a <= c); // 10 <= 10은 참이므로 결괏값은 1
    printf("a <= c : %d\n", res);
    res = (a == b); // 10 == 20은 거짓이므로 결괏값은 0
    printf("a == b: %d\n", res);
    res = (a != c); // 10 != 10은 거짓이므로 결괏값은 0
    printf("a != c: %d\n", res); 

    return 0;
}

/* 실행 결과

a > b : 0
a > b : 0
a < b : 1
a > b : 1
a <= c : 1
a == b: 0
a != c: 0

*/