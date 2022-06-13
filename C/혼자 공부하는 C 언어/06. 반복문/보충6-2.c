//  보충 6-2. break로 무한 반복문 빠져나오기
/*  실제 예제는 아니지만, 중첩 반복문을 이해하는 데에 도움이 될 것 같아서
    p.173 참고하여 직접 예제 문제를 프로그래밍 해 봤습니다. */

/* break

반복을 끝낼 땐 조건에 따라 break를 사용합니다.

*/

/* 무한반복문의 예시

while(1)
{
    printf("Be happy!\n");
}

for (;;)
{
    printf("Be happy!\n");
}

*/

#include <stdio.h>

int main(void)
{
    int count = 0;
    while (1)
    {
        printf("Be happy!\n");
        count++;    // 반복될 때마다 1씩 증가
        if (count == 5) break;  // count의 값이 5가 되면 break로 반복 종료
    }
}