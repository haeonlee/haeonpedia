// 17-6. 구조체 포인터의 사용

/*

    구조체
        장점: 어떤 대상과 관련된 데이터를 달라도 하나로 묶어 처리할 수 있음.
        단점: 데이터의 종류가 많을 땐 구조체 변수의 크기가 커짐.


    공용체
        공용체를 쓰면 하나의 공간을 여러 멤버가 공유하여 최소한의 메모리만 사용할 수 있습니다.


    구조체 포인터와 -> 연산자

        구조체 변수는 그 안의 여러 개의 변수를 버로 가질 수 있으나, 그 자신은 단지 하나의 변수입니다.
        따라서 구조체 변수에 주소 연산자를 사용하면 특정 멤버의 주소가 아니라 구조체 변수 전체의 주소가 구해집니다.
        또한 그 값을 저장할 때는 구조체 포인터를 사용합니다.

        구조체 포인터 선언
            struct score *ps = &yuni;
                가리키는 것은 struct score 구조체

        간접 멤버 연산자(->) 사용
            ps -> eng

*/

#include <stdio.h>

struct score
{
    int kor;
    int eng;
    int math;
};

int main(void)
{
    struct score yuni = { 90, 80, 70 };
    struct score *ps = &yuni;          // 구조체 포인터에 주소 저장

    printf("국어 : %d\n", (*ps).kor);   // 구조체 포인터로 멤버 접근
    printf("영어 : %d\n", ps -> eng);   // -> 연산자 사용
    printf("수학 : %d\n", ps -> math);

    return 0;
}

/* 실행 결과

국어 : 90
영어 : 80
수학 : 70

*/