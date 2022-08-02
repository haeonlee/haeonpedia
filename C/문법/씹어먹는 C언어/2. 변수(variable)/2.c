/*
DATE: 2022. 03. 18. FRI
PAGE: 34p
주제: 서식 지정자의 이해
포인트: 서식 지정자를 이용해 n진수로 표현하기
*/

#include <stdio.h>
int main() {
    int a;
    a = 127;
    printf("a의 값은 %d 진수로 %o 입니다. \n", 8, a);
    printf("a의 값은 %d 진수로 %d 입니다. \n", 10, a); 
    printf("a의 값은 %d 진수로 %x 입니다. \n", 16, a);
    return 0;
}

/* %o, %d, %x는 인자(a)의 값을 출력하는 형식 */
