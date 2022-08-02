/*
DATE: 2022. 03. 19. SAT
PAGE: 40p
주제: 산술 연산자(Arithmetic Operator)
포인트: 산술 연산자 이해하기
*/

#include <stdio.h>
int main() {
    int a, b;
    a = 10; 
    /* =은 대입 연산자(Assignment Operator)로 우측의 값을 좌측에 대입함
    대입 연산자는 뒤부터 해석을 함: 가령 a=b=c=d=5라면 d=5부터 시작해서 a=b까지 차례로 해석하는 셈 */
    b = 3;
    printf("a + b 는: %d \n", a + b);
    printf("a - b 는: %d \n", a - b);
    printf("a * b 는: %d \n", a * b);
    printf("a / b 는: %d \n", a / b); // 정수 부분만 남아서 3.3333에서 3만 남음
    printf("a %% b는: %d \n", a % b);
    /* %는 나눈 나머지를 표시하기 때문에 정수형 데이터에서만 연산 가능
    %%는 %를 '표시'하기 위한 방법, %는 %f나 %d 등으로 활용되기 때문에 혼동 방지를 위해 % 하나로는 표시가 안 됨 */
    return 0;
}