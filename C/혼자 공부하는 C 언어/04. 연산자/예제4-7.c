// 4-7. 연산의 결괏값을 사용하는 방법

/* 

연산을 실행한 다음, 연산의 결괏값은 변수에 저장하면 버려집니다.
따라서 연산 결과를 곧바로 사용하거나, 대입 연산을 통해 다른 변수에 저장해야 합니다.

*/

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20, res;

    a + b; // 연산 결과는 버려짐
    printf("%d + %d = %d\n", a, b, a+b); // 연산 결과를 바로 출력에 사용

    res = a + b; // 연산 결과는 변수에 저장
    printf("%d + %d = %d\n", a, b, res); // 저장된 값을 계속 사용

    return 0;
}

/* 실행 결과

10 + 20 = 30
10 + 20 = 30

16행에서 경고 메시지 발생 (사유: 값 사용되지도 않았는데 왜 써?)
warning: expression result unused [-Wunused-value]

*/