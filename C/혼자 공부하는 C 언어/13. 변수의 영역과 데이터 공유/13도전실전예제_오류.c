// 13. 변수의 영역과 데이터 공유

/*
    도전 실전 예제. 전역 변수 교환 프로그램
    2개의 전역 변수에 값을 입력하고 교환한 후에 출력하는 프로그램을 작성합니다.
    입력, 교환, 출력 작업은 다음에 제시된 함수 원형을 지켜 작성합니다.

    실행 결과
    두 정수 입력 : 10 20
    두 정수 출력 : 20, 10
*/

#include <stdio.h>

void input_data(int *pa, int *pb);
void swap_data(void);
void print_data(int a, int b);

int a, b;

int main(void)
{
    input_data(&a, &b);     // 전역 변수에 정수 값 입력
    swap_data();            // 두 변수 교환
    print_data(a, b);       // 교환된 변숫값 출력

    return 0;
}

void input_data(int *pa, int *pb)
{
    printf("두 정수 입력 : ");
    scanf("%d %d", *pa, *pb);   // 오류: scanf 함수엔 주소값을 넣어야지요!
}


void swap_data(void)
{
    int num;

    num = a;
    a = b;
    b = num;
}


void print_data(int a, int b)
{
    printf("두 정수 출력 : %d, %d", a, b);
}