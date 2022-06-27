// 12-4. gets 함수로 한 줄의 문자열 입력

/* 
    scanf 함수: 공백 포함된 문자열 한 번에 입력 불가

    gets 함수: 중간에 공백이나 탭 문자를 포함하여 문자열 한 줄을 입력
        공백 포함된 문자열 한 번에 입력 가능

        gets 함수 원형
        char *gets(char *str)

    중요1. 버퍼에서 개행 문자를 가져오지만 배열에는 널 문자로 바꿔 저장합니다.
    중요2. 배열의 크기보다 큰 문자열을 입력하지 마세요
    중요3. gets 함수는 enter만 눌러도 입력을 끝냅니다.
        cf. scanf 함수는 문자열을 입력하기 전에 space bar, tab, enter를 눌러도 입력을 기다림
            왜냐면 저것들을 문자열을 구분하는 용도로만 쓸 뿐, 데이터로 받아들이지 않아서
*/

#include <stdio.h>

int main(void)
{
    char str[80];

    printf("공백이 포함된 문자열 입력 : ");
    gets(str);  // 배열명으로 주고 함수 호출
    printf("입력한 문자열은 %s입니다.", str);

    return 0;
}

/* 실행 결과

공백이 포함된 문자열 입력 : apple jam
입력한 문자열은 apple jam입니다.

*/