// 4-8. 형 변환 연산자가 필요한 경우

/* 

형 변환 연산자

피연산자의 값을 원하는 형태로 바꿈 (e.g. 정수 -> 실수)
형태를 바꿀 땐 피연산자의 값을 복사하여 일시적으로 형태를 바꾸므로,
연산 후 메모리에 있는 피연산자의 형태가 값은 변하지 않음

(자료형)피연산자

피연산자 개수: 1개

cf. 자동 형 변환

피연산자가 2개 이상이라면 피연산자의 형태는 같아야 함,
따라서 컴파일러가 컴파일 과정에서 피연산자끼리의 형태를 통일시키는 것을 자동 형 변환이라고 함

기본 규칙: 크기가 작은 값이 크기가 큰 값으로 바뀜
e.g. 정수(4바이트), 실수(8바이트) -> 실수(8바이트), 실수(8바이트)

but. 대입 연산은 메모리에 값을 저장하므로 무조건 좌항에 변수형에 맞게 저장됨

그러나 가능하면 자동 형 변환 될 가능성을 고려하지 말고,
피연산자의 형태를 같게 사용하는 것을 추천

*/

#include <stdio.h>

int main(void)
{
    int a = 20, b = 3;
    double res;

    res = ((double)a / (double)b); // (double)을 사용해 a와 b를 실수 값으로 변환
    /* 이유: 소수점 이하까지 값을 구하려면 연산 대상이 정수가 아니라 실수여야 한다 */
    /* 처음부터 a와 b을 double형으로 넣으면 편하다는 건 오해,
    double형은 저장 공간이 크고 연산 속도가 느리며, 오차가 발생하므로
    int형을 기본적으로 쓰고 필요할 때만 double형을 쓰는 것이 좋음 */

    printf("a = %d, b = %d\n", a, b);
    printf("a / b의 결과 : %.1lf\n", res);

    a = (int)res;
    printf("(int) %.1lf의 결과 : %d\n", res, a); // (int)값을 이용해 res의 값에서 정수 부분만 추림
    /* 반올림 하지 않고 무조건 버림 */

    return 0;
}

/* 실행 결과

a = 20, b = 3
a / b의 결과 : 6.7
(int) 6.7의 결과 : 6

*/