// 15-8. 함수 포인터로 원하는 함수를 호출하는 프로그램

/*

    함수 포인터의 활용

        함수 포인터는 함수의 형태만 같으면 기능과 상관없이 모든 함수에 사용할 수 있습니다.
        따라서 형태가 같은 다양한 기능의 함수를 선택적으로 호출할 때 사용합니다.


    여기서 잠깐. 어떤 경우에 함수 포인터를 써야 할까요?

        (1) func 함수(필요한 함수를 직접 호출하여 사용하는 기능)만 따로 만드는 경우에,
            만드는 시점에서 어떤 함수를 쓸 건지 결정할 수 없다면
            일단 함수 포인터를 쓰고 나중에 func 함수를 호출하는 곳에서 그 기능을 다른 함수로 구현할 수 있습니다
        
        (2) 하나의 프로그램이 여러 개의 파일로 분리되어 있는 경우
            다른 파일에 있는 정적 함수(static function)을 호출하는 방법

*/

#include <stdio.h>

void func(int (*fp)(int, int));
int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);

int main(void)
{
    int sel;

    printf("01 두 정수의 합\n");
    printf("02 두 정수의 곱\n");
    printf("03 두 정수 중에서 큰 값 계산\n");
    printf("원하는 연산을 선택하세요 : ");
    scanf("%d", &sel);

    switch(sel)
    {
        case 1: func(sum); break;
        case 2: func(mul); break;
        case 3: func(max); break;
    }

    return 0;
}

void func(int (*fp)(int, int))
{
    int a, b;
    int res;

    printf("두 정수의 값을 입력하세요 : ");
    scanf("%d%d", &a, &b);
    res = fp(a, b);
    printf("결괏값은 : %d\n", res);
}

int sum(int a, int b)
{
    return (a + b);
}

int mul(int a, int b)
{
    return (a * b);
}

int max(int a, int b)
{
    if (a > b) return a;
    else return b;
}

/* 실행 결과 

01 두 정수의 합
02 두 정수의 곱
03 두 정수 중에서 큰 값 계산
원하는 연산을 선택하세요 : 2
두 정수의 값을 입력하세요 : 3 4
결괏값은 : 12

*/