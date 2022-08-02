// 좀 더 알아보기. 직접 구현해보는 gets 함수
// p.332

#include <stdio.h>

int main(void)
{
    int i = 0;
    char str[20];
    char ch;    // 입력한 문자를 받아둘 임시 변수

    do
    {
        ch = getchar();     // 일단 문자 하나 입력
        str[i] = ch;        // 배열에 저장
        i++;                // 첨자 증가
    } while (ch != '\n');   // 입력한 문자가 개행이면 종료

    str[--i] = '\0';        // 개행 문자가 입력된 위치에 널 문자 저장
    // printf("%s", str);
    // printf 함수는 실제로 잘됐는지 확인해 보려고 잠깐 넣은 거
    return 0;
}

/*

c.f. 아예 함수를 만든 경우 

void my_gets(char *ps)
{
    char ch;
    wile ((ch = getchar()) != '\n')
    {
        *ps = ch;
        ps++;
    }

    *ps = '\0'
}

*/