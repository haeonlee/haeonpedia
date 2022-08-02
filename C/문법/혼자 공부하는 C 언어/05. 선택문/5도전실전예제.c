// 5. 선택문(if, switch ~ case)
/*  도전1. 계산기 프로그램: 키보드로 수식을 입력하면 계산 결과를 출력하는 프로그램을 작성하세요.
    정수 사칙 연산만 입력 가능합니다.
    tip. 연산기호(+, -, *, /)도 하나의 문자입니다. */

/*  MEMO: 이렇게 하는 건가? 해서 코드 입력하니까 잘 돌아가긴 했는데,
    scanf 입력 방식을 잘 이해하지 못하고 있다는 생각이 들었다.
    나는 입력값 사이에 엔터나 스페이스바를 넣어야 하는 줄 알았음.
*/


#include <stdio.h>

int main(void)
{
    int a, b;
    char symbol;
    
    printf("사칙연산 입력(정수) : ");
    scanf("%d%c%d", &a, &symbol, &b);

    if (symbol == '+')
        printf("%d%c%d=%d", a, symbol, b, a+b);

    else if (symbol == '-')
        printf("%d%c%d=%d", a, symbol, b, a-b);

    else if (symbol == '*')
        printf("%d%c%d=%d", a, symbol, b, a*b);

    else if (symbol == '/')
        printf("%d%c%d=%d", a, symbol, b, a/b);

    else
        printf("다시 입력하세요. 입력 가능한 연산 기호는 +, -, *, /입니다.");

    return 0;
}

/* 답지

int main(void)
{
    int num1, num2, res;
    char op;

    printf("사칙 연산 입력(정수) : ");
    scanf_s("%d%c%d", &num1, &op, 1, &num2);    // scanf_s 함수의 경우
                                                // 문자나 문자열을 쓸 땐 바로 뒤에 크기를 적어줘야 함
                                                // op의 크기는 1이니까 1이라고 적기

    switch(op)
    {
        case '+': res = num1 + num2; break;
        case '-': res = num1 - num2; break;
        case '*': res = num1 * num2; break;
        case '/': res = num1 / num2; break;
    }

    printf("%d %c %d = %d\n", num1, op, num2, res);
}

*/