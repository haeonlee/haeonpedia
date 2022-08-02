// 4-2. 몫과 나머지를 구하는 연산

/*

나눗셈 연산(/)
    나눗셈 연산은 결괏값이 정수 또는 실수가 될 수 있으므로,
    그 값을 저장하는 변수도 그에 맞게 사용해야 한다

    c.f. 정수 / 실수와 같이 피연산자의 형태가 다른 경우는 4장 <형 변환 연산자>에서 다룰 예정

나머지 연산자(%)
    실수 연산에는 나머지 개념이 없으므로 정수 사이에서만 사용해야 함
    (다시 말해, 피연산자로는 반드시 정수만 사용해야 한다는 말)

*/

#include <stdio.h>

int main(void)
{
    double apple; // 실수
    int banana; // 정수
    int orange; // 정수

    apple = 5.0 / 2.0; // 실수와 실수의 나누기 연산
    banana = 5 / 2; // 정수와 정수의 나누기 연산
    orange = 5 % 2; // 정수와 정수의 나머지 연산(%)

    printf("apple : %.1lf\n", apple);
    printf("banana : %d\n", banana);
    printf("orange : %d\n", orange);

    return 0;
}

/* 실행 결과

apple : 2.5
banana : 2
orange : 1

*/