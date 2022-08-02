// 7-5. 재귀호출 함수

/*

재귀호출 함수(recursive call function): 자기 자신을 호출하는 함수

*/

#include <stdio.h>

void fruit(void);   // 함수 선언

int main(void)
{
    fruit();    // 함수 호출

    return 0;
}

void fruit(void)    // 재귀호출 함수 정의
{
    printf("apple\n");
    fruit();    // 자신을 다시 호출
}

/* 실행 결과

apple
apple
apple
...

끝나지 않고 계속 apple을 출력한다: 무한하게 울리는 메아리처럼.

*/