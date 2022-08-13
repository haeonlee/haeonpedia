// 19-9. 전역 변수에 extern과 static을 사용한 프로그램

/*

    분할 컴파일에서 extern과 static의 용도

        프로그램을 여러 파일로 나누면, 각 파일들이 전역 변수를 공유하기 쉽지 않습니다.
        이땐 특별한 선언이 필요합니다.

        1. extern 선언: 다른 파일에서 선언된 전역 변수를 사용할 때
        2. static 선언: 다른 파일에서 전역 변수를 공유하지 못하게 할 때
            - 다른 파일에서 잘못 호출할 가능성을 사전에 차단
            - 다른 파일에서 같은 이름의 함수 또는 변수를 정의할 수 있음
            - static 선언은 변수에서도 가능함
                static int input_data(void) {...}


    여기서 잠깐. 컴파일러가 전역 변수를 처리하는 방식

        컴파일러가 둘 이상의 파일에 같은 이름의 전역 변수를 허용하는 경우
        - 기본적으로 둘 이상의 파일에 같은 이름의 전여 변수를 사용할 수 없습니다.
        - 그러나 일부 컴파일러는 하나의 전역 변수를 제외한 나머지를 자동으로 extern 선언하여,
          전역 변수를 공유하기도 합니다.
        - 이는 컴파일러마다 처리 방식이 다를 수 있으므로 항상 명시적으로 extern 선언을 하는 것이 좋습니다.

        컴파일러가 extern 선언에 초기화를 허용하는 경우
        - extern 선언은 저장 공간을 메모리에 할당하지 않으므로 초기화할 수 없습니다.
        - 만약 초기화를 허용하는 컴파일러라면,
          extern 선언을 독립된 전역 변수의 선언으로 간주하고 변수의 저장 공간을 활당합니다.
        - 컴파일러마다 처리 방식으로 다를 수 있으므로, extern 선언을 한 경우는 초기화하지 않도록 주의하세요.

*/

/*

    각 파일에 작성한 함수의 기능

    main.c 파일
    - main 함수: input_data, average, print_data 함수를 호출합니다
    - print_data 함수: 입력한 양수의 개수, 전체 양수의 합과 평균을 출력합니다

    input.c 파일
    - input_data 함수: 음수가 입력될 때까지 양수를 반복 입력하여 그 합을 반환합니다

    average.c 파일
    - average 함수: 입력한 양수의 평균을 구해 반환합니다

*/


// 파일명: main.c
// main, print_data 함수 정의

#include <stdio.h>

int input_data(void);       // 양수를 입력하고 그 합을 반환
double average(void);       // 평균을 구하는 함수
void print_data(double);    // 출력 함수

int count = 0;              // 입력한 양수의 수 누적
static int total = 0;       // 입력한 양수의 합
                            // static 선언으로 하나의 소스 파일에서만 사용 가능

int main(void)
{
    double avg;

    total = input_data();
    avg = average();
    print_data(avg);

    return 0;
}

void print_data(double avg)
{
    printf("입력한 양수의 개수 : %d\n", count);
    printf("전체의 합과 평균 : %d, %.1lf\n", total, avg);
}


// 파일명: input.c
// input_data 함수 정의

#include <stdio.h>

extern int count;       // main.c 파일의 전역 변수 count 공유
int total = 0;          // 전역 파일 선언
                        // 앞선 main.c의 total과는 별개의 변수인 셈

int input_data(void)
{
    int pos;

    while (1)
    {
        printf("양수 입력 : ");
        scanf("%d", &pos);
        if (pos < 0) break;
        count++;
        total += pos;
    }

    return total;   // 전역 변수 total의 값 반환
}


// 파일명: average.c
// average 함수 정의

extern int count;
extern int total;       // input.c의 total과 전역 변수 공유

double average(void)
{
    return total / (double)count;
}

