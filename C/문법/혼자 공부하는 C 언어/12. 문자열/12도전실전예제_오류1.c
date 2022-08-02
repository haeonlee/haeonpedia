// 12. 문자열
/*
    도전 실전 예제. 단어 정렬 프로그램
    키보드로 세 단어를 입력하여 사전 순서대로 출력합니다.

    실행 결과
    세 단어 입력 : kiwi banana grape
    banana, grape, kiwi
*/

/*
    프로그래밍 노트
    - 우선 대문자, 소문자를 구분해야 할까? 먼저 고민했고.
    - 문제를 풀면서, 포인터로 대소 관계를 미리 확정한 다음에 방향만 요리조리 바꿔야겠다고 생각했다.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80];
    char str2[80];
    char str3[80];
    char *max;
    char *mid;
    char *min;

    printf("세 단어 입력 : ");
    scanf("%s%s%s", str1, str2, str3);

    if ( strcmp(str1, str2) == -1 )
    {
        max = str1;
        mid = str2;
    }

    else
    {
        max = str2;
        mid = str1;
    }
        

    if ( strcmp(*mid, str3) == -1 )
        min = str3;

    else
    {
        mid = str3;
        min = *mid;
    }
        
        
    if ( strcmp(*max, *mid) == 1 )
    {
        mid = *max;
        max = *mid;
    }

    printf("%s, %s, %s", *max, *mid, *min);

}