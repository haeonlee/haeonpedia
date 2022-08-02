// 13-4. auto 지역 변수와 static 지역 변수의 비교

/*

    정적 지역 변수(static variable)
        - 지역 변수를 선언할 때 static 예약어를 사용
        - 정적 지역 변수는 선언된 블록 안에서만 사용하는 전역 변수와 같습니다
          : 저장 공간 할당, 초기화 방법, 메모리 존재 기간이 전역 변수와 같음
        - 지역 변수와 저장 공간이 메모리에 존재하는 기간이 다릅니다: 선언된 함수가 반환돼도 계속 저장 공간을 유지
        - 따라서, 하나의 함수가 여러 번 호출되는 경우에 같은 변수 공유 가능

        - 사용하면 좋은 경우: 프로그램이 끝날 때까지 저장 공간을 유지하면서 특정 함수에서만 쓰는 경우

*/

#include <stdio.h>

void auto_func(void);
void static_func(void);

int main(void)
{
    int i;

    printf("일반 지역 변수(auto)를 사용한 함수...\n");

    for (i = 0; i < 3; i++)
    {
        auto_func();
    }

    printf("정적 지역 변수(static)을 사용한 함수...\n");
    for (i = 0; i < 3; i++)
    {
        static_func();
    }

    return 0;
}

void auto_func(void)
{
    auto int a = 0;
    a++;
    printf("%d\n", a);
}

void static_func(void)
{
    static int a;
    a++;
    printf("%d\n", a);
}

/*

일반 지역 변수(auto)를 사용한 함수...
1
1
1
정적 지역 변수(static)을 사용한 함수...
1
2
3

*/