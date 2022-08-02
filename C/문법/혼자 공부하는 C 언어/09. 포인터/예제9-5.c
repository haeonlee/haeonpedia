// 9-5. 주소와 포인터의 크기

/*

포인터: 주소를 저장하는 일정한 크기의 메모리 공간
    - 포인터는 변수이므로 값을 언제든지 바꿀 수 있음: 다른 주소 저장, 포인터끼리 대입 등
    - but 일반 변수와는 달리 대입 연산에 엄격한 기준이 적용

주소와 포인터의 차이
    - 주소(상수): 변수에 할당된 메모리 저장 공간의 시작 주소 값 자체
    - 포인터(변수): 그 값으 저장하는 또 다른 메모리 공간
    따라서 특정 변수의 주소 값은 바뀌지 않지만, 포인터는 다른 주소를 대입하여 그 값을 바꿀 수 있음

    1. 포인터의 값은 변할 수 있음
    2. 두 포인터가 같은 주소를 저장하는 것(즉, 하나의 변수를 동시에 가리키는 일)도 가능
    3. 간접 참조 연산자 사용 가능
        *pa = 10;   // pa가 가리키는 변수 a에 10 대입
        printf("%d", *pb);  // pb가 가리키는 변수 a 값 10 출력
        (pa와 pb가 모두 변수 a를 가리키고 있는 경우)

주소와 포인터의 크기
    모든 주소와 포인터는 가리키는 자료형에 관계없이 크기가 같다

*/

#include <stdio.h>

int main(void)
{
    char ch;
    int in;
    double db;

    char *pc = &ch;
    int *pi = &in;
    double *pd = &db;

    printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));
    printf("int형 변수의 주소 크기 : %d\n", sizeof(&in));
    printf("double형 변수의 주소 크기 : %d\n", sizeof(&db));

    printf("char * 포인터의 크기 : %d\n", sizeof(pc));
    printf("int * 포인터의 크기 : %d\n", sizeof(pi));
    printf("double * 포인터의 크기 : %d\n", sizeof(pd));

    printf("char * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pc));
    printf("int * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pi));
    printf("double * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pd));

    return 0;

}

/* 실행 결과

char형 변수의 주소 크기 : 8
int형 변수의 주소 크기 : 8
double형 변수의 주소 크기 : 8
char * 포인터의 크기 : 8
int * 포인터의 크기 : 8
double * 포인터의 크기 : 8
char * 포인터가 가리키는 변수의 크기 : 1
int * 포인터가 가리키는 변수의 크기 : 4
double * 포인터가 가리키는 변수의 크기 : 8

*/