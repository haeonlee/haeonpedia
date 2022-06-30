// 12-10. strcat, strncat 함수를 사용한 문자열 붙이기

/*

    strcat, strncat 함수: 배열에 있는 문자열 뒤에 다른 문자열을 이어 붙임, 일종의 더하기 연산자

        이어 붙인 뒤, 뒤에 널 문자를 저장하여 문자열을 완성함

        strcat: 문자열을 이어 붙임
        strncat: 지정한 문자의 개수만큼 붙임

        주의1. strcat 함수는 메모리를 침범할 수 있습니다.
        주의2. strcat 함수를 사용할 땐 배열을 초기화해야 합니다.
            strcat 함수로 붙여넣기를 할 땐, 먼저 널 문자의 위치부터 찾으므로 반드시 초기화를 해야 합니다.
            배열이 초기화되지 않으면 쓰레기 값의 중간부터 붙여넣을 가능성이 큽니다.

            (1) 명시적으로 널 문자를 초기화
                char str[80] = {'\0'};
            (2) 널 문자의 아스키 코드 값으로 초기화
                char str[80] = {0};
            (3) 큰 따옴표 안에 아무 것도 없으므로 널 문자만 초기화
                char str[80] = "";
            (4) 첫 번째 배열 요소만 별도로 초기화
                str[0] = '\0';

*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80] = "straw";

    strcat(str, "berry");    // str 배열에 문자열 붙이기
    printf("%s\n", str);
    strncat(str, "piece", 3);    // str 배열에 3개의 문자 붙이기
    printf("%s\n", str);

    return 0;
}

/* 실행 결과

strawberry
strawberrypie

*/