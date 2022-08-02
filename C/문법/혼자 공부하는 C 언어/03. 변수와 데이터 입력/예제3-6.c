// 3-6. char 배열에 문자열 저장

/*

문자열은 char형을 배열 형태로 만들어 저장
저장 방법: char 배열명[문자열길이+1] = 문자열;
출력 방법: %s

배열(array): 기본 자료형을 여러 개 묶어 사용하는 것(*8장에서 자세하게 다룸)

Q. 왜 문자열 길이보다 배열의 크기를 하나 더 크게 잡나요?
A. 컴파일러가 문자열의 끝에 \0(널 문자null character)을 자동으로 추가하기 때문
배열의 크기가 더 크더라도(e.g. 글자는 10글자인데 배열 크기는 20으로 배정) 문자열 끝엔 항상 널 문자가 있으므로,
printf 함수는 널 문자 이전까지 저장된 문자열만 출력.

*/

#include <stdio.h>

int main(void)
{
    char fruit[20]= "strawberry"; // char 배열 선언과 문자열 초기화
    
    printf("딸기 : %s\n", fruit); // 배열명으로 저장된 문자열 출력
    printf("딸기쨈 : %s %s\n", fruit, "jam"); // 문자열 상수를 직접 %s로 출력

    return 0;
}

/* 실행 결과
딸기 : strawberry
딸기쨈 : strawberry jam
*/