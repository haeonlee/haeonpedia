// 9-7. 포인터를 사용한 두 변수의 값 교환

/*
포인터를 사용하는 이유

    포인터의 장점: 임베디드 프로그래밍 등 메모리에 직접 접근하는 경우, 동적 할당한 메모리를 사용하는 경우
    포인터의 단점: 추가적인 변수 선언이 필요하고, 주소 연산(&), 간접 참조 연산(*) 등 각종 연산을 수행해야 함

*/

#include <stdio.h>

void swap(int *pa, int *pb);    // 두 변수의 값을 바꾸는 함수의 선언

int main(void)
{
    int a = 10, b = 20;
    
    swap(&a, &b);       // a, b의 주소를 인수로 주고 함수 호출
    printf("a: %d, b: %d\n", a, b);

    return 0;
}

void swap(int *pa, int *pb)     // 매개변수로 포인터 선언
{
    int temp;

    temp = *pa;
    *pa = *pb;      // pa가 가리키는 변수에 pb가 가리키는 변수의 값 저장
    *pb = temp;     // pb가 가리키는 변수에 temp 값 저장
}

/* 실행 결과 

a: 20, b: 10

    교환 작업은 swap 함수 안에서 포인터를 통해 진행,
    그러나 실제로 바뀌는 값은 main 함수의 변수 a와 b

*/

