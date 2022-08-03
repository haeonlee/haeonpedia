// 15-7. 함수 포인터를 사용한 함수 호출

/*

    함수 포인터
        함수의 주소를 이용해 포인터로 함수의 기능을 사용
        이때, 함수명은 함수 정의가 있는 메모리의 시작 위치다
        함수명이 주소이므로 포인터에 저장하면 함수를 다양한 방식으로 호출할 수 있음

    함수의 형태
        int sum(int, int);
        함수의 형태가 곧 함수 포인터가 가리키는 형태이다

    함수 포인터의 형태
        int (*fp)(int, int);
        
        (1) int (int, int)는 가리키는 것이 int (*fp)(int, int)라는 뜻이다
        (2) (*fp)는 fp가 포인터라는 뜻이다

        cf. int *fp(int, int);
            두 정수를 인수로 받고 주소를 반환하는 함수의 선언    

*/

#include <stdio.h>

int sum(int, int);  // 함수 선언

int main(void)
{
    int (*fp)(int, int);    // 함수 포인터 선언
    int res;

    fp = sum;               // 함수명을 함수 포인터에 저장
                            // 왜냐하면 함수명이 곧 함수의 주소이므로
    res = fp(10, 20);       // 함수 포인터로 함수 호출
    printf("result : %d\n", res);   // 반환값 출력

    return 0;
}

int sum(int a, int b)   // 함수 정의
{
    return (a + b);
}

/* 실행 결과

result : 30

*/