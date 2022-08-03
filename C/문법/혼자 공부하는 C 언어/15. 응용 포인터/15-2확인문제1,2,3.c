// 15-2. 함수 포인터와 void 포인터

/*

    확인 문제1. 다음과 같이 선언된 함수가 있을 때 대입 연산이 가능하도록 함수 포인터를 선언하세요.

        double div(int, int);
        void prn(char *);
        int *save(int);

        (1) double (*fpa)(int, int);
        (2) void (*fpb)(char *);


        (3) int (*fpc)(int); (오답)

        정답: (3) int *(*fpc)(int);
        이유: 왜냐면 int *형을 가리켜야 하니까

        fpa = div;
        fpb = prn;
        fpc = save;


    확인 문제2. 다음의 배열과 포인터가 있을 때 포인터 vp로 세 번째 배열 요소의 값 30을 출력하세요.


        내 답안

        #include <stdio.h>

        int main(void)
        {
            int ary[5] = { 10, 20, 30, 40, 50 };
            void *vp = ary;

            printf("%d", *(int *)vp + 2); // 이렇게 쓰면 첫 번째 요소에서 +2가 되어 12 출력

            return 0;
        }

        두 번째 답안
        printf("%d", *((int *)vp + 2));     // 30 출력ㅋㅋ 기쁘당

        또 다른 답 (답지 답안)
        printf("%d", ((int *)vp)[2]);

        ary[2] = *(ary +2)니까...


    확인 문제3. 다음 프로그램의 실행결과를 예상해보세요.

        #include <stdio.h>

        int add(int a, int b) { return (a + b); }
        int sub(int a, int b) { return (a - b); }
        int mul(int a, int b) { return (a * b); }

        int main(void)
        {
            int (*pary[3])(int, int) = { add, sub, mul }
            int i, res = 0;

            for ( i = 0; i < 3; i++)
            {
                res += pary[i](2, 1);
            }

            printf("%d", res);

            return 0;
        }

        실행 결과 : 6

*/