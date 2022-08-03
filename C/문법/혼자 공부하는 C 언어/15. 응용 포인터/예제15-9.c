// 15-9. void 포인터의 사용

/*

    void 포인터
        주소는 가리키는 자료형이 일치하는 포인터에만 대입이 가능
        따라서 가리키는 자료형이 다른 주소를 저장하는 경우라면, void 포인터를 사용

        void 포인터는 가리키는 자료형이 정해지지 않은 포인터인 셈
        - 따라서, 어떤 주소든 저장할 수 있음
        - 같은 이유로, 간접 참조 연산이나 정수를 더하는 포인터 연산이 불가능
            - 왜냐하면 연산을 하려면 몇 바이트를 어떤 형태로 읽어야 하는지 알아야 하기 때문


    void 포인터의 선언

        void *vp;
        (1) void는 가리키는 자료형이 정해지지 않았다는 뜻
        (2) *vp는 vp는 포인터라는 뜻이다

    
    void 포인터의 사용

        사용할 땐 원하는 형태로 변환하여 사용

        (int *)vp -> (int *)형으로 형 변환
        (double *)vp -> (double *)형으로 형 변환

        형 변환을 한 뒤엔, 간접 참조 연산은 물론 정수 연산도 가능하다

        (1) 간접 참조 연산: *(int *)vp
        (2) 정수 연산: printf("a의 주소 + 1의 값 : %d\n", (int *)vp + 1);


    여기서 잠깐. void 포인터가 형 변환을 하지 않는 경우도 있나요?

        대입 연산을 할 땐 형 변환 없이 void 포인터를 다른 포인터에 대입할 수 있습니다.
        그래도 항상 병시적으로 형 변환을 하여 사용하는 것이 좋습니다.
        

*/

#include <stdio.h>

int main(void)
{
    int a = 10;
    double b = 3.5;
    void *vp;

    vp = &a;    // int형 변수의 주소 저장
    printf("a : %d\n", *(int *)vp);

    vp = &b;    // double형 변수의 주소 저장
    printf("b : %.1lf\n", *(double *)vp);

    return 0;
}

/* 실행 결과

a : 10
b : 3.5

*/