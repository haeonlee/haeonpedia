// 8-4. 문자열을 저장하는 char형 배열

/* 

char형 배열에 문자열 저장
    주의: 저장할 문자열의 길이보다 최소한 하나 이상 크게 배열을 선언할 것
    왜냐하면 널 문자(\0)를 저장해야 해요

    1. 문자 상수로 하나씩 초기화
    char str[80] = {'a','p','p','l','e'};

    2. 문자열 상수로 한 번에 초기화
    char str[80] = "apple";

널 문자의 용도
    남는 배열 요소엔 자동으로 널 문자(null character, \0)이 채워집니다.
    널 문자는 '문자열의 끝을 표시하는 용도'로 사용됩니다.
    따라서, 배열의 크기와 상관없이 정확하게 문자열을 출력할 수 있는 것입니다.

    주의: 초기화하지 않은 상태에서 배열 요소에 직접 문자를 대입한다면,
    반드시 마지막 문자 다음에 널 문자를 입력할 것 (p.223)

char형 배열 선언 시 주의할 점
    주의1. 배열의 크기는 최대한 넉넉하게 선언해야 합니다
    주의2. 배열 요소의 개수는 최소한 '문자열 길이+1'이어야 합니다: 널 문자 때문에

*/

#include <stdio.h>

int main(void)
{
    char str[80] = "applejam";

    printf("최초 문자열 : %s\n", str);
    printf("문자열 입력 : ");
    scanf("%s", str);
    printf("입력 후 문자열 : %s\n", str);

    return 0;
}

/* 실행 결과

최초 문자열 : applejam
문자열 입력 : grape
입력 후 문자열 : grape

*/