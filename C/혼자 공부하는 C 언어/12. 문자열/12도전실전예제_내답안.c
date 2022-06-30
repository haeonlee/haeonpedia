/*
    프로그래밍 노트
    - 문제를 풀면서, 포인터로 대소 관계를 미리 확정한 다음에 방향만 요리조리 바꿔야겠다고 생각했다.
    - 아까는 포인터의 방향을 if문 중간에 설정했다면, 지금은 처음부터 초기화를 하기로 했다.
    - 내가 3개의 대소 관계를 비교해서 블록을 순서대로 넣는 효율적인 알고리즘을 제대로 파악 못 하고 있다는 생각이 들었다.
    - 포인터를 없애기로 했다.
*/


#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80];
    char str2[80];
    char str3[80];
    char resp[80];

    printf("세 단어 입력 : ");
    scanf("%s%s%s", str1, str2, str3);

    if ( strcmp(str1, str2) >= 0 )
    {
        strcpy(resp, str1);
        strcpy(str1, str2);
        strcpy(str2, resp);
    }

    if ( strcmp(str1, str3) >= 0 )
    {
        strcpy(resp, str1);
        strcpy(str1, str3);
        strcpy(str3, resp);
    }

    if ( strcmp(str2, str3) >= 0 )
    {
        strcpy(resp, str2);
        strcpy(str2, str3);
        strcpy(str3, resp);
    }

    printf("%s, %s, %s", str1, str2, str3);
    
    return 0;

}