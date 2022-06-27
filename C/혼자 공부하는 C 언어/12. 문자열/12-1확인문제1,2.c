// 12-1. 문자열과 포인터
/*
    1. 실행결과를 참고하여 프로그램의 빈칸을 채웁니다

        내가 쓴 답: *ps
        실제 답안: char *ps // 초기화를 한 문장이었음

        #include <stdio.h>
        int main(void)
        {
            char *ps = "applepie";
            ps += 5;
            printf("%s", ps);
            return 0;
        }
        실행 결과: pie


    2. 다음과 같이 배열과 포인터가 선언되어 있을 때, 실행결과가 다른 것을 고르세요.

        내가 쓴 답: 답안 못 고름

        char str[20] = "apple";
        char *pa = str;
        char *pb = "pineapple";

        (1) printf("%s", "apple");
            apple

        (2) printf("%s", str[0]);
            str[0]은 char형 배열의 첫 번째 요소며 'a'가 저장,
            따라서 printf 함수의 인수로 소문자 a의 아스키 코드 값인 97이 전달되며
            printf 함수는 97번지부터 널 문자가 나올 때까지 문자열을 출력
            메모리 97번지가 어떤 용도로 사용될지 알 수 없으므로 실행 결과는 예상할 수 없음

        (3) printf("%s", pa);
            apple

        (4) printf("%s", pb + 4);
            apple

*/