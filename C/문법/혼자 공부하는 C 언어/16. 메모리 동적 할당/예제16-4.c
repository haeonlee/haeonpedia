// 16-4. 3개의 문자열을 저장하기 위한 동적 할당

/*

    동적 할당을 사용한 문자열 처리

        동적 할당은 프로그램의 효율을 높이기 위한 하나의 방법으로 사용됩니다.
        예를 들어 입력할 문자열의 길이를 알 수 없는 경우
        무조건 큰 배열을 선언하는 것은 저장 공간의 낭비를 초래할 수 있습니다.
        
        동적 할당을 하면 입력되는 문자열의 길이에 맞게 저장 공간을 사용할 수 있습니다.
        예제를 통해 길이가 다른 여러 개의 문자열을 효율적으로 처리하는 방법을 생각해 보겠습니다.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char temp[80];      // 임시 char 배열
    char *str[3];       // 동적 할당 영역을 연결할 포인터 배열
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("문자열을 입력하세요 : ");
        gets(temp);                                 // 문자열 입력
        str[i] = (char *)malloc(strlen(temp) + 1);  // 문자열 저장 공간 할당, 널 문자 포함
        strcpy(str[i], temp);                       // 동적 할당 영역에 문자열 복사
    }

    for (i = 0; i < 3; i++)
    {
        printf("%s\n", str[i]);
    }

    for (i = 0; i < 3; i++)
    {
        free(str[i]);
    }

    return 0;
}

/* 실행 결과

문자열을 입력하세요 : Hi
문자열을 입력하세요 : Let me introduce
문자열을 입력하세요 : Hello
Hi
Let me introduce
Hello

*/