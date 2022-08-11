// 19-1. 전처리 지시자

/*

    확인 문제 1. 다음 중에서 설명이 옳지 않은 문장을 고르세요.

        (1) 소스 파일과 전처리 후의 파일은 형태가 같은 텍스트 파일입니다.
        (2) 전처리 지시자 include는 파일의 내용을 단순히 복사한다.
        (3) 매크로 함수를 많이 사용하면 실행 속도는 빨라지나 프로그램의 크기가 커진다.
        (4) #ifndef 지시자는 수식과 매크로명을 모두 조건식으로 쓸 수 있다.


        내 답안
        (4) #ifndef 지시자는 수식과 매크로명을 모두 조건식으로 쓸 수 있다.
            -> 매크로명만 쓸 수 있음


    확인 문제 2. 다음과 같이 매크로 함수가 정의되어 있는 때 출력문의 결과를 적어보세요.

        #define SUM(x, y) x+y
        printf("%d", SUM(20, 5) * 3);

        내 답안
        20 + 5 * 3 = 20 + 15 = 35


    확인 문제 3. 다음 조건부 컴파일 명령을 사용한 프로그램의 실행결과를 적어보세요.

        #include <stdio.h>
        #define DEBUG
        #define LEVEL 2

        int main(void)
        {
            int flag;

        #ifndef DEBUG
            flag = 0;
        #elif LEVEL == 1
            flag = 1;
        #elif defined(MAX_LEVEL) && (LEVEL == 2)
            flag = 2;
        #else
            flag = 3;
        #endif
            printf("%d", flag);

            return 0;
        } 

        내 답안
        3

*/