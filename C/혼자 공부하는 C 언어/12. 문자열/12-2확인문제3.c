// 12-2. 문자열 연산 함수

/*

    확인 문제3. 키보드로 입력한 단어의 길이가 5자를 넘는 경우, 6자부터 별(*)을 출력하는 프로그램을 작성합니다.
    단어의 최대 길이는 15자로 제한합니다.

*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80];
    char newstr[80];
    int i;

    printf("단어 입력 : ");
    scanf("%s", str);

    strcpy(newstr, str);

    if (strlen(str) > 15)
        printf("입력 가능한 단어의 길이를 초과했습니다.");

    else if (strlen(str) > 5 )
    {
        for (i=5; i<(strlen(str)); i++)
        {
            newstr[i] = '*';
        }
        printf("입력한 단어 : %s, 생략한 단어 : %s", str, newstr);
    }
    
    else
        printf("입력한 단어 : %s, 생략한 단어 : %s", str, newstr);
}