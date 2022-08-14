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

#define SCAN_NUMS(char *x, *y, *z) scanf("수식 입력(종료 Ctrl+Z) : %d %c %d", &x, &y, &z)
// 이거 ㄹㅇ 개떡 같이 씀

#define SUM(a, b) ((a) + (b))
#define SUB(a, b) ((a) - (b))
#define MUL(a, b) ((a) * (b))
#define DIV(a, b) ((a) / (b))

int main(void)
{
    int x, y, z;    // y를 char로 분류하지 않음

    while (1)
    {
        SCAN_NUMS(&x, &y, &z); // 얘도 개떡임
        switch (y)
        {
        case '+':
            printf("%d %c %d = %d", x, y, z, SUM(x, z));
            // case문 쓸 땐 break를 써줘야지 딱 case 상황만 쓰고 감
            // break 안 쓰면 해당 케이스부터 시작해서 걔 아래에 있는 놈들 차례대로 다 씀

        case '-':
            printf("%d %c %d = %d", x, y, z, SUB(x, z));

        case '*':
            printf("%d %c %d = %d", x, y, z, MUL(x, z));

        case '/':
            printf("%d %c %d = %d", x, y, z, DIV(x, z));
        }
    }

    // return 0; 안 씀
}