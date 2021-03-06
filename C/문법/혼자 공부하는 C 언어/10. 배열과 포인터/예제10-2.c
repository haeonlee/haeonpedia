// 10-2. 배열명처럼 사용되는 포인터

/*

배열명과 포인터의 차이

    차이점1. sizeof 연산의 결과가 다릅니다
        sizeof(배열명): 배열 전체의 크기
        sizeof(포인터): 포인터 하나의 크기

        int ary[3];
        int *pa = ary;
        sizeof(ary);    // 12바이트, 배열 전체 크기
        sizeof(pa);     // 4바이트, 포인터 하나의 크기

    차이점2. 변수와 상수의 차이가 있습니다
        포인터는 값을 바꿀 수 있지만, 배열명은 상수이므로 값을 바꿀 수 없습니다
        pa = pa + 1; pa++; 과 같은 건 가능
        ary = ary + 1; ary++ 과 같은 건 불가능

*/

#include <stdio.h>

int main(void)
{
    int ary[3];         // 배열 선언
    int *pa = ary;      // 포인터에 배열명 저장
    /* 이렇게 하면 배열명이 ary가 되는 셈 */
    int i;              // 반복 제어 변수

    *pa = 10;           // 첫 번째 배열 요소에 10 대입
    *(pa + 1) = 20;
    pa[2] = pa[0] + pa[1];  // 대괄호를 써서 pa를 배열명처럼 사용

    for (i = 0; i < 3; i++)
    {
        printf("%5d", pa[i]);
    }

    return 0;
}

/* 실행 결과

   10   20   30

*/