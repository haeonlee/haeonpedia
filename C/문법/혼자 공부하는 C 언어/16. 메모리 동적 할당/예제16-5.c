// 16-5. 동적 할당 영역의 문자열을 함수로 출력

/*

    동적 할당 영역에 저장한 문자열을 함수로 처리하는 예

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char **ps);

int main(void)
{
    char temp[80];
    char *str[21] = { 0 };
    /* 포인터 배열을 선언할 땐 쓰레기 값으로 가득차게 됩니다.
       만약 쓰레기 값이 참조 불가능한 코드 영역의 주소이고, 부주의로 이 값이 참조된다면 프로그램은 멈춥니다.
       따라서 포인터 배열은 선언과 동시에 널 포인터로 초기화하고 참조할 때도 널 포인터인지 검사하세요.
       물론 최소한 포인터 배열의 마지막 요소는 널 포인터의 자리로 남겨둬야 합니다. */

    int i = 0;

    while (i < 20)
    {
        printf("문자열을 입력하세요 : ");
        gets(temp);
        if (strcmp(temp, "end") == 0) break;
        str[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(str[i], temp);
        i++;
    }

    print_str(str);

    for (i = 0; str[i] != NULL; i++)    // 널 포인터인지 검사
    {
        free(str[i]);
    }

    return 0;
}

void print_str(char **ps)   // 이중 포인터 선언, 포인터 함수의 주소를 받아야 하니까
{
    while (*ps != NULL)     // 포인터 배열의 값이 널 포인터가 아닌 동안 반복
    {
        printf("%s\n", *ps);
        ps++;   // ps가 다음 배열 요소를 가리킴
        /* 배열명을 포인터에 저장하면 포인터 자신의 값을 바꿀 수 있으므로, ps 값을 바꾸며 배열 요소를 이동함 */
    }
}

/* 실행 결과

문자열을 입력하세요 : hi
문자열을 입력하세요 : happy
문자열을 입력하세요 : love
문자열을 입력하세요 : end
hi
happy
love

*/
