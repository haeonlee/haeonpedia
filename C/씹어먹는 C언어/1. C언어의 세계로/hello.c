#include <stdio.h> 
/* <studio.h>를 포함: 표준 입출력 헤더STandard Input Output header의 약자
<studio.h>는 화면에 출력하고, 키보드로부터 입력을 받아들이는 것을 담당함
물론, 이 파일 하나에 모든 내용이 다 구현돼 있는 건 아님
자세한 내용은 나중에 배우게 됨
*/
// 정수(integer)형을 반환하는 메인 함수
int main() {
    printf("Hello, World! \n"); // 문장 끝 세미콜론
    // 화면에 괄호 안 내용을 출력할 수 있게 해 주는 printf 함수
    // \n은 개행 문자(=줄 바꿈), \는 escape character
    return 0; // 0을 반환(return), 프로그램이 무사 종료
    // 문장 끝 세미콜론
    // 단, 함수의 선언 부분인 int main()이나 헤더파일 선언 부분인 #include <stdio.h> 뒤엔 ; 안 붙임
} // 중괄호로 main 함수의 시작과 끝을 알림

/* MAC VScode에서 C언어 작업 환경 구성하기
extension 설치: C/C++, codelldb, code runner */