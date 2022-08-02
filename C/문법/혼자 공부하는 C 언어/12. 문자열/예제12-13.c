// 12-13. strcpy와 기능이 같은 함수 구현

/*

    직접 만드는 strcpy 함수

    strcpy 함수는 문자열이 저장된 메모리에서 첫 번째 문자의 주소를 인수로 받음

*/

#include <stdio.h>

char *my_strcpy(char *pd, char *ps);    // 함수 선언

int main(void)
{
    char str[80] = "strawberry";

    printf("바꾸기 전 문자열 : %s\n", str);
    my_strcpy(str, "apple");            // 문자열 "apple" 복사
    printf("바꾼 후 문자열 : %s\n", str);
    printf("다른 문자열 대입 : %s\n", my_strcpy(str, "kiwi"));  // 반환 값으로 출력

    return 0;

}

char *my_strcpy(char *pd, char *ps)
{
    char *po = pd;  // pd 값을 나중에 반환하기 위해 보관

    while (*ps != '\0')
    {
        *pd = *ps;  // ps가 가리키는 문자를 pd가 가리키는 문자에 대입
        pd++;
        ps++;
    }
    *pd = '\0';     // 복사가 모두 끝난 후, 복사 받을 곳에 널 문자로 마무리
                    // 이 과정을 생각하면 기존 문자열에 앞 부분만 덮어쓴 형식으로 나옴

    return po;      // 복사가 끝난 저장 공간의 시작 주소 반환
}

/* 실행 결과

바꾸기 전 문자열 : strawberry
바꾼 후 문자열 : apple
다른 문자열 대입 : kiwi

*/