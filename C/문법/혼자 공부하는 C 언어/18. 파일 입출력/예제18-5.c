// 18-5. stdin과 stdout을 사용한 문자 입출력

/*

    파일 포인터를 인수로 받는 함수

        stdin, stdout, stderr을 직접 fgetc 함수나 fputc 함수 등의 인수로 사용합니다.

*/

#include <stdio.h>

int main(void)
{
    int ch;

    while (1)
    {
        ch = fgetc(stdin);      // 키보드에서 문자 입력
        if (ch == EOF)
        {
            break;
        }
        fputc(ch, stdout);      // 모니터로 출력
        
        // 하나의 문자를 반복적으로 입출력하지만 스트림 파일의 버퍼를 이용하므로
        // 문자열을 한 줄씩 입출력하는 기능을 수행하게 됩니다
    
    }

    return 0;
}

/* 실행 결과

rabbit
rabbit
turtle
turtle
^Z

*/