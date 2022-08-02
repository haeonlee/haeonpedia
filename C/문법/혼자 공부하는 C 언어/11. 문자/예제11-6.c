// 11-6. getchar 함수를 사용한 문자열 입력

#include <stdio.h>

void my_gets(char *str, int size);

int main(void)
{
    char str[7];

    my_gets(str, sizeof(str));
    printf("입력한 문자열 : %s\n", str);

    return 0;
}

void my_gets(char *str, int size)
{
    int ch;     // getchar 함수의 반환값을 저장할 변수
    int i = 0;

    ch = getchar(); // 최초로 문자를 입력: 이때 모든 문자를 버퍼에 저장
    while ((ch != '\n') && (i < size-1))    // 배열의 크기만큼 입력
    {
        str[i] = ch;    // 입력한 문자를 배열에 저장
        i++;            // 첨자 증가
        ch = getchar(); // getchar() 함수가 반복 사용되며, 버퍼로부터 문자를 하나씩 갖고 옴
    }

    str[i] = '\0';      // 입력된 문자열의 끝에 널 문자를 저장
}

/* 실행 결과

a boy
입력한 문자열 : a boy

BE happy!
입력한 문자열 : BE hap

*/