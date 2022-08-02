// 07-1. 함수의 작성과 사용
// 1. 다음은 두 실수의 평균을 구하는 함수를 호출하는 코드입니다. 함수 정의에서 빈칸에 적당한 내용을 채우세요.

#include <stdio.h>

double average(double a, double b);

int main(void)
{
    double res;
    res = average(1.5, 3.4);
    printf("%0.2lf", res);
}

double average(double a, double b)
{
    double temp;
    temp = a + b;
    return(temp/2.0);
}

/* 실행 결과

2.45

*/