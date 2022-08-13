// 19-8. 두 정수의 평균을 구하는 프로그램

/*

    분할 컴파일

        하나의 프로그램을 여러 사람이 나누어 개발할 수 있다면 개발 기간을 줄일 수 있습니다.
        더불어 여러 개의 소스 파일로 나누어 각각 독립적으로 컴파일하면,
        디버깅하기 쉽고 유지보수와 코드 재활용에 유리합니다.

        그러나
        (1) 개별적으로 코드를 작성하고 컴파일 및 에러 수정을 할 수 있어야 합니다.
        (2) 각 개발자들 간의 데이터 공유와 코드 재활용이 가능해야 합니다.

    C언어의 분할 컴파일

        C언어는 분할 컴파일을 통해 여러 개의 소스 코드를 각각 독립적으로 작성하고, 컴파일할 수 있습니다.
        또한 컴파일된 개체 파일을 링크하여 하나의 큰 프로그램으로 만들 수 있습니다.
        또한 extern 선언을 통해 파일들 간에 데이터를 공유하고
        전처리 지시자로 코드를 쉽게 재활용할 수 있습니다.

    분할 컴파일할 때 주의점

        주의1. 각 파일을 독립적으로 컴파일할 수 있도록 필요한 선언을 포함해야 합니다

            e.g.
            main.c에서 input_data와 average 함수를 호출하므로, 반드시 함수 선언을 해야 함.
            sub.c에서 printf와 scanf 함수를 사용하므로 그 원형이 있는 stdio.h 헤더 파일을 포함해야 함.

        주의2. 소스 파일들은 같은 프로젝트 안에서 모든 파일을 관리하는 편이 좋습니다

            다른 디렉터리에 있어도 컴파일과 링크엔 문제가 없으나,
            소스 파일들을 같은 프로젝트 안에서 관리하도록 하세요.


*/

// 파일명: main.c
// main 함수 정의

#include <stdio.h>

void input_data(int *, int *);
double average(int, int);

int main(void)
{
    int a, b;
    double avg;

    input_data(&a, &b);
    avg = average(a, b);
    printf("%d와 %d의 평균 : %.1lf\n", a, b, avg);

    return 0;
}

// 파일명: sub.c
// input_data, average 함수 정의

#include <stdio.h>

void input_data(int *pa, int *pb)
{
    printf("두 정수 입력 : ");
    scanf("%d%d", pa, pb);
}

double average(int a, int b)
{
    int tot;
    double avg;

    tot = a + b;
    avg = tot / 2.0;

    return avg;
}