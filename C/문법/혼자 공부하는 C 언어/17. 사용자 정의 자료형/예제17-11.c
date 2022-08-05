// 17-11. 열거형을 사용한 프로그램

/*

    열거형: 변수에 저장할 수 있는 정수 값을 기호로 정의하여 나열

        열거형 선언

            예약어 열거형이름 {열거형 변수에 저장할 수 있는 기호화된 정수 값들};
            enum season {SPRING, SUMMER, FALL, WINTER};

            이때, 컴파일러는 멤버를 0부터 차례로 하나씩 큰 정수로 바꿉니다.
            즉, SPRING은 0, WINTER는 3입니다.
            열거형 멤버는 어차피 정수로 취급되므로(계절 이름은 읽기 쉽게 하기 위한 기호일 뿐)
            정수 상수를 써서도 코딩을 할 수 있습니다.

            만약 이를 바꾸고 싶다면
            enum season {SPRING = 5, SUMMER, FALL = 10, WINTER};
            이라고 하면 됩니다.
            특별히 지정을 안 한 경우는, 설정된 멤버보다 하나씩 큰 정수로 바뀝니다.
            즉, SUMMER는 6, WINTER는 11이 됩니다.

*/

#include <stdio.h>

enum season {SPRING, SUMMER, FALL, WINTER};     // 열거형 선언

int main(void)
{
    enum season ss;     // 열거형 변수 선언
    char *pc = NULL;    // 문자열을 저장할 포인터

    ss = SPRING;        // 열거 멤버의 값 대입
    switch (ss)         // 열거 멤버 판단
    {
        case SPRING:
            pc = "inline"; break;

        case SUMMER:
            pc = "swimming"; break;
        
        case FALL:
            pc = "trip"; break;
        
        case WINTER:
            pc = "skiing"; break;
    }

    printf("나의 레저 활동 => %s\n", pc);

    return 0;
}

/* 실행 결과

나의 레저 활동 => inline

*/