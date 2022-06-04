// 03-2. 확인문제 2 (p.81)
/* 프로그램의 빈칸을 채워 보세요. */

// 결과: 수정 없이 바로 맞힘

#include <stdio.h>

int main(void)
{
    char fruit[20];
    int cnt;

    printf("좋아하는 과일 : ");
    scanf("%s", fruit);
    printf("몇 개 : ");
    scanf("%d", &cnt);
    printf("%s를 %d개 드립니다.", fruit, cnt);

    return 0;
}