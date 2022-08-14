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

int x, y, z;
#define SCAN_NUMS(void) scanf("수식 입력(종료 Ctrl+Z) : %d %c %d", &x, &y, &z)

#define SUM(a, b) ((a) + (b))
#define SUB(a, b) ((a) - (b))
#define MUL(a, b) ((a) * (b))
#define DIV(a, b) ((a) / (b))

int main(void)
{
    while (1)
    {
        SCAN_NUMS();
        switch (y)
        {
        case '+':
            printf("%d %c %d = %d", x, y, z, SUM(x, z));

        case '-':
            printf("%d %c %d = %d", x, y, z, SUB(x, z));

        case '*':
            printf("%d %c %d = %d", x, y, z, MUL(x, z));

        case '/':
            printf("%d %c %d = %d", x, y, z, DIV(x, z));
        }
    }
}