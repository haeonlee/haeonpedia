// 9-3. 포인터를 사용한 두 정수의 합과 평균 계산

/* 

포인터가 어떤 변수를 가리키게 되면, 그 이후에는 간접 참조 연산자를 통해 가리키는 변수를 자유롭게 사용 가능

포인터의 선언과 동시에 주소 초기화
    int *pt; pt = &total; 을 
    int *pt = &total; 로 한 번에 작성 가능

*/

#include <stdio.h>

int main(void)
{
    int a = 10, b = 15, total;  // 변수 선언과 초기화
    double avg;                 // 평균을 저장할 변수
    int *pa, *pb;               // 포인터 동시 선언
    int *pt = &total;           // 포인터 선언과 초기화
    double *pg = &avg;          // double형 포인터 선언과 초기화

    pa = &a;                    // 포인터 pa에 변수 a의 주소 대입
    pb = &b;                    // 포인터 pb에 변수 b의 주소 대입

    *pt = *pa + *pb;            // a 값과 b 값을 더해 total에 저장
    *pg = *pt / 2.0;            // total 값을 2로 나눈 값을 avg에 저장

    printf("두 정수의 값 : %d, %d\n", *pa, *pb);
    printf("두 정수의 합 : %d\n", *pt);
    printf("두 정수의 평균 : %.1lf\n", *pg);

    return 0;
}

/* 실행 결과

두 정수의 값 : 10, 15
두 정수의 합 : 25
두 정수의 평균 : 12.5

*/