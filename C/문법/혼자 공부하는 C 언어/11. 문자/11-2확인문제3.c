// 11-2. 버퍼를 사용하는 입력 함수
/*
    3. 다음은 키보드로 입력한 문장에서 소문자의 개수를 세어 출력합니다.
    빈칸을 채워서 프로그램을 완성하세요.
*/

#include <stdio.h>
int main(void)
{
    int ch;
    int cnt = 0;
    ch = getchar();

    while (ch != '\n')
    {
        if (ch >= 'a' && ch <= 'z') cnt++;
        ch = getchar();
    }

    printf("소문자의 개수 : %d\n", cnt);

    return 0;
}

/* 실행 결과

HonGongClove
소문자의 개수 : 9

*/