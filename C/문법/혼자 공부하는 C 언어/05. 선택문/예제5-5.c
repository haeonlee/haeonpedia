// 5-5. 중첩 if문에서 중괄호가 반드시 필요한 경우

/*

point: 컴파일러는 if문이 중첩된 경우 else를 가장 가까운 if와 연결한다.

*/

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;

    if (a < 0)  // a가 0보다 작지만
    {
        if (b > 0)  // b가 0보다 크면 ok 출력
        {
            printf("ok");
        }
    }
    else    // a가 0 이상이면 ok 출력
    {
        printf("ok");
    }

    return 0;
}

/* 실행 결과

ok

*/