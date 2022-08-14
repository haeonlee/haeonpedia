// 19. 전처리와 분할 컴파일

/*

    도전 실전 예제. 사칙연산 계산기 프로그램
    
    사칙연산 수식을 입력하면 그 결과를 출력하는 프로그램을 작성합니다.
    단, 수식을 입력하는 함수와 사칙연산 함수를 매크로 함수로 작성하세요.

*/

/* 

    오류 보고
    아예 가만히 있고 실행 자체가 안 됨

*/

#include <stdio.h>

#define SCAN_NUMS(x, y, z) scanf("%d %c %d", &x, &y, &z)

#define SUM(a, b) ((a) + (b))
#define SUB(a, b) ((a) - (b))
#define MUL(a, b) ((a) * (b))
#define DIV(a, b) ((a) / (b))

int main(void)
{
    int x, z;
    char y;

    while (1)
    {
        printf("수식 입력(종료 Ctrl+Z) : ");
        SCAN_NUMS(x, y, z);
        switch (y)
        {
        case '+':
            printf("%d %c %d = %d\n", x, y, z, SUM(x, z));
            break;

        case '-':
            printf("%d %c %d = %d\n", x, y, z, SUB(x, z));
            break;

        case '*':
            printf("%d %c %d = %d\n", x, y, z, MUL(x, z));
            break;

        case '/':
            printf("%d %c %d = %d\n", x, y, z, DIV(x, z));
            break;
        }
    }

    return 0;
}

/* 실행 결과

수식 입력(종료 Ctrl+Z) : 10 + 20
10 + 20 = 30
수식 입력(종료 Ctrl+Z) : 10 - 4
10 - 4 = 6
수식 입력(종료 Ctrl+Z) : 10 * 5
10 * 5 = 50
수식 입력(종료 Ctrl+Z) : 10 / 4
10 / 4 = 2
수식 입력(종료 Ctrl+Z) : ^Z
zsh: suspended  

*/