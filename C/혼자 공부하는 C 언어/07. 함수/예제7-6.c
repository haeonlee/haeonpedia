// 7-6. 3번 실행되는 재귀호출 함수
// 용도. 매개변수와 if문을 사용하면 호출 횟수를 원하는 만큼 조절할 수 있다.

#include <stdio.h>

void fruit(int count);   // 함수 선언

int main(void)
{
    fruit(1);    // 처음 호출하므로 1을 인수로 준다

    return 0;
}

void fruit(int count)    // 재귀호출 함수 정의
{
    printf("apple\n");
    if (count == 3) return; // 호출 횟수가 3이면 반환하고 끝낸다
    fruit(count + 1);    // 재호출할 때 호출 횟수를 1 증가
}

/* 실행 결과

apple
apple
apple

*/