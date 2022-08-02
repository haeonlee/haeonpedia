// 12-1. 문자열과 포인터
/* 3. 다음 프로그램의 문제점을 찾고 // 필요한 문장을 추가하여 바르게 실행되도록 수정합니다. */

/* MEMO: 문제 의도는 파악했으나, 정확한 코드는 기억 X */

#include <stdio.h>
int main(void)
{
    char ani[20];
    char why[80];
    printf("좋아하는 동물 : ");
    scanf("%s", ani);
    fgetc(stdin); // 필요한 문장
    printf("좋아하는 이유 : ");
    fgets(why, sizeof(why), stdin);
    printf("%s is %s", ani, why);
    
    return 0;
}



