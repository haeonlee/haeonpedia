// 12-7. 문자열을 출력하는 puts와 fputs 함수

/*

    문자열을 출력하는 puts, fputs 함수

        화면의 문자열만을 출력할 때는 전용 출력 함수인 puts와 fputs를 사용합니다.
        1. 둘 모두 정상 출력된 경우는 0을 반환, 출력에 실패하면 -1(EOF)을 반환
        2. 둘 모두 문자열의 시작 위치부터 널 문자가 나올 때까지 모든 문자를 출력

        puts 함수 원형
            int puts(const char *str)   // 문자열을 출력하고 자동 줄 바꿈
            
            c.f. 포인터에 const 쓰는 이유: *str = 어쩌고; 같은 방식으로
                 간접 참조 해서 값 바꿀 수 없다는 소리다. (예제 9-4에서 상세 설명) 
                 문자열 상수와 같이 직접 메모리에 접근해서 바꾸면 안 되는(애초에 읽기 전용으로 저장돼 있음)
                 녀석들을 받을 때 이렇게 자주 한다고 함.

        fputs 함수 원형
            int fputs(const char *str, FILE *stream)    // 문자열을 출력하고 줄 바꾸지 않음

*/

#include <stdio.h>

int main(void)
{
    char str[80] = "apple juice";   // 배열에 문자열 초기화
    char *ps = "banana";

    puts(str);  // apple juice 출력하고 줄 바꿈
    fputs(ps, stdout);  // banana만 출력
    puts("milk");   // banana에 이어 milk 출력

    return 0;
}

/* 실행 결과

apple juice
bananamilk

*/