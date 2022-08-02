// 12-8. strcpy 함수의 사용법

/*

문자열 연산
    - 문자열로 연산할 때는 문자열 연산에 사용하는 함수를 따로 사용해야 함

    char 배열: 다른 문자열로 바꿀 때 문자를 하나씩 옮겨야 함
        char str1[80] = "strawberry";
        str1[0] = 'a';
        str1[1] = 'p';
        str1[2] = 'p';
        str1[3] = 'l';
        str1[4] = 'e';
        str1[5] = '\0';

    strcpy 함수: string copy, 문자열을 한 번에 대입, 문자열 연산 함수
        - string.h 헤더 파일을 인클루드

        strcpy(복사받을곳, 복사할내용)

            첫 번째 인수: 복사 받을 곳의 배열명
                즉, char 배열 또는 그 배열명을 저장한 포인터만 가능
                특히 문자열 상수나 문자열 상수를 연결하고 있는 포인터를 사용하지 않도록 조심할 것

            두 번째 인수: 복사할 문자열, 따라서 복사할 문자열의 시작 위치
                즉, 배열명, 포인터, 문자열 상수 등을 인수로 사용할 수 있다.

        중요1. 첫 번째 인수는 char 배열이나 배열명을 저장한 포인터만 사용할 수 있습니다.
        중요2. 두 번째 인수는 문자열의 시작 위치를 알 수 있다면 어떤 것이든 사용할 수 있습니다.

*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80] = "strawberry";
    char str2[80] = "apple";
    char *ps1 = "banana";       // 포인터로 문자열 상수 연결
    char *ps2 = str2;           // 포인터로 배열 연결

    printf("최초 문자열 : %s\n", str1);
    strcpy(str1, str2);         // 다른 char 배열의 문자열 복사
    printf("바뀐 문자열 : %s\n", str1);

    strcpy(str1, ps1);          // 문자열 상수를 연결한 포인터 사용
    printf("바뀐 문자열 : %s\n", str1);

    strcpy(str1, ps2);          // 배열을 연결한 포인터 사용
    printf("바뀐 문자열 : %s\n", str1);

    strcpy(str1, "banana");
    printf("바뀐 문자열 : %s\n", str1);

    return 0;

}

/* 실행 결과

최초 문자열 : strawberry
바뀐 문자열 : apple
바뀐 문자열 : banana
바뀐 문자열 : apple
바뀐 문자열 : banana

*/