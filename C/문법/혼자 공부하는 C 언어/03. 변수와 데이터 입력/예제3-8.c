// 3-8. const를 사용한 변수

/* const를 사용한 변수는 초기화된 값을 바꿀 수 없습니다.
따라서 const를 사용하면 선언과 동시에 초기화를 해야 합니다. (그렇지 않으면 쓰레기 값이 계속 사용됨)

선언: const 자료형 변수명 = 값;
 */

#include <stdio.h>

int main(void)
{
    int income = 0; // 소득액 초기화
    double tax; // 세금
    const double tax_rate = 0.12; // 세율 초기화

    income = 456; // 소득액 저장
    tax = income * tax_rate; // 세금 계산
    printf("세금은 : %.1lf입니다.\n", tax);

    return 0;
}

/* 실행 결과
세금은 : 54.7입니다.
*/