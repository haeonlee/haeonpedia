// 8-5. 문자열을 대입하는 strcpy 함수

/*

strcpy 함수: char형 배열에 새로운 문자열을 저장하는 함수
    저장할 문자열의 길이를 파악하여 딱 그 길이만큼 char형 배열에 복사
    끝에 널 문자도 자동으로 삽입

    strcpy(저장될_배열명, "문자열");
    strcpy(저장될_배열명, 저장할_배열명);

여기서 잠깐. strcpy 함수를 사용한 코드가 컴파일되지 않을 때
    첫 줄에 #define_CRT_SECURE_NO_WARNINGS 라는 문장을 삽입할 것

여기서 잠깐. 배열에 대입 연산자는 왜 사용할 수 없을까요? (p.226)

    char str[80];
    str = "apple";
    이렇게 쓰면 오류가 발생함

    why? 대입 연산자의 왼쪽에 사용한 배열명이 컴파일 과정에서 배열이 할동된 메모리의 주소 값으로 바뀌기 때문입니다.
    예를 들어 str 배열이 메모리 100번지부터 할당되었다면 다음과 같이 대입하는 것과 같습니다.

    100 = "apple";
    100은 상수기 때문에 대입 연산자의 왼쪽에 올 수 없습니다.
    그렇기 때문에 위처럼 쓰면 오류가 나는 것입니다.

    cf. 반면, strcpy 함수는 그 위치로 이동하여 메모리 공간을 사용하도록 구현돼 있기 때문입니다.

*/

#include <stdio.h>
#include <string.h> // 문자열 관련 함수 원형을 모아놓은 헤더 파일

int main(void)
{
    char str1[80] = "cat";
    char str2[80];

    strcpy(str1, "tiger");  // str1 배열에 "tiger" 복사
    strcpy(str2, str1);     // str2 배열에 str1 배열의 문자열 복사
    printf("%s, %s\n", str1, str2);

    return 0;
}

/* 실행 결과

tiger, tiger

*/