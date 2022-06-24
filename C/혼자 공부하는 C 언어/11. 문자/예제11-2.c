// 11-2. 공백이나 제어 문자의 입력

/*

%c 변환 문자
    알파벳이나 숫자 모양 문자 등 형태가 있는 문자도 입력
    공백(space), 탭 문자(tab), 개행 문자(enter)와 같은 제어 문자도 입력

여기서 잠깐. scanf에서 화이트 스페이스(white space, 스페이스바, 탭, 엔터 등을 일컫음)를 방지하는 방법은 없나요?
    scanf 함수는 %c 앞에 화이트 스페이스를 사용하면 문자도 분리하여 입력할 수 있습니다.
    예를 들어 scanf(" %c %c", &ch1, &ch2);
    위처럼 코드를 짜면 scanf 함수는 입력 문자 중에서 화이트 스페이스는 무시하고 그 외 문자만 입력합니다. 

*/

#include <stdio.h>

int main(void)
{
    char ch1, ch2;

    scanf(" %c %c", &ch1, &ch2);    // 이렇게 하면 white space는 입력되지 않아요
    printf("[%c%c]", ch1, ch2);

    return 0;
}

