// 12-9. strncpy 함수를 사용한 문자열 복사

/*

    strncpy 함수: 원하는 개수의 문자만을 복사

        strncpy(복사 받을 배열명, 복사할 문자열, 복사할 문자 수);
        strncpy(str, "apple-pie", 5);

*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[20] = "mango tree";

    strncpy(str, "apple-pie", 5);

    // str[5] = '\0';

    printf("%s\n", str);

    return 0;
}

/* 실행 결과

apple tree

널 문자는 저장되지 않음: 따라서, str 배열에서 mango만 apple로 바뀜

만약 apple만 저장하고 싶다면?
str[5] = '\0'; 를 넣어야 함

*/