// 11-3. getchar 함수와 putchar 함수 사용

/*

scanf 함수와 printf 함수
    문자 뿐만 아니라 숫자도 입출력
    따라서, 문자만 입력하는 함수에 비해 크기가 큼

getchar 함수와 putchar 함수: 문자 전용 입출력 함수

    int getchar(void);  // 매개변수가 없고 입력한 문자를 반환합니다
        반환값은 필요에 따라 char형 변수나 배열에 옮겨 문자나 문자열로 사용
        getchar 함수도 scanf 함수와 마찬가지로 공백 문자, 탭 문자, 개행 문자를 입력하는데 제외 옵션이 없음

    int putcher(int);   // 출력할 문자를 인수로 줍니다
        문자 상수나 문자의 아스키 코드 값을 인수로 주면 해당 문자를 화면에 출력
        만약 출력 과정에서 에러가 발생하면 -1을 반환

여기서 잠깐. getchar 함수의 반환형이 int형인 이유는 무엇일까요?
    문자 이외의 값도 반환하기 때문
    e.g. 문자의 입력을 끝내기 위해 ctrl+z를 누르면 -1을 반환하는데, 이를 문자와 구분하기 위해 int형이 필요
*/

#include <stdio.h>

int main(void)
{
    int ch;

    ch = getchar();
    printf("입력한 문자 : ");
    putchar(ch);    // 입력한 문자 출력
    putchar('\n');  // 개행 문자 출력

    return 0;
}

/* 실행 결과

A
입력한 문자 : A

*/