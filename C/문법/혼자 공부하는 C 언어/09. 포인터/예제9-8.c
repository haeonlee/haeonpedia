// 9-8. 다른 함수의 변수 사용하기
// swap 함수에서 main 함수의 a, b를 이름으로 직접 사용하는 방법

#include <stdio.h>

void swap(void);    // 두 변수의 값을 바꾸는 함수 선언

int main(void)
{
    int a = 10, b = 20;

    swap();
    printf("a: %d, b: %d\n", a, b);

    return 0;
}

void swap(void)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

/* 실행 결과

에러 메시지 발생
'a' 'b' 선언되지 않은 식별자입니다

    함수 안에 선언된 변수명은 사용 범위가 함수 내부로 제한

*/