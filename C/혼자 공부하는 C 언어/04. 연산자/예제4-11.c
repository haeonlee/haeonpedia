// 4-11. 콤마 연산자

/* 

콤마 연산자: 한 번에 여러 개의 수식을 차례로 나열해야 할 때 사용
    왼쪽부터 오른쪽으로 차례로 연산 수행
    오른쪽 피연산자가 최종 결괏값

*/

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;
    int res;

    res = (++a, ++b);   // 차례로 연산이 수행되며 결과적으로
                        // res에 저장되는 값은 증가된 b의 값이다
    
    printf("a: %d, b: %d\n", a, b);
    printf("res: %d\n", res);

    return 0;
}

/* 실행 결과

a: 11, b: 21
res: 21

*/