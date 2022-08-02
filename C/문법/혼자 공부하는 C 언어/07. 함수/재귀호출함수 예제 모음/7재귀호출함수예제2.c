// 예제2. 입력 받은 숫자의 높은 자릿수부터 차례로 출력하라.
// 출처: https://m.blog.naver.com/fewus28/220966348725

/* 입력을 '3408'로 했다면, 
   출력은
   '3
    4
    0
    8'

    주의: int 범위의 정수가 입력됐다고 가정하고, %d를 이용하여 입력 받아 저장할 것. (%c 또는 %s 사용 금지) */


#include <stdio.h>

void print_num(double num);

int main(void)
{
    int num;
    double temp;

    printf("정수 입력 : ");
    scanf("%d", &num);

    temp = (double)num;

    while (temp > 1)
    {
        temp = temp / 10;
    }

    print_num(temp);

}


void print_num(double num)
{
    if (((num-(int)num))==0) // 내 답안: if (((num-(int)num)) == 0)
        return;

    else
        num = num*10;
        printf("%lf\n", num);
        printf("%d\n", (int)num); 
        num = num-(int)num;
        print_num(num);
}

/* 실행 결과

정수 입력 : 3408
3
4
0
7
9
9
9
9
... (무한 소수 값이 출력됐다)

접근법 자체는 맞는 것 같은데 실수 저장 방식 자체의 문젠지 지저분한 숫자가 출력됐다.

*이때 사용한 코드

void print_num(double num)
{
    if (((num-(int)num)) == 0)
        return;

    else
        num = num*10;
        printf("%lf\n", num);
        printf("%d\n", (int)num);
        num = num-(int)num;
        print_num(num);

}

*/


/* 오류 원인 파악하기

정수 입력 : 3408
3.408000
3
4.080000
4
0.800000
0
8.000000
7
10.000000
9
10.000000
9
10.000000
9
10.000000
9

printf("%lf", num)을 넣어 오류 원인을 추적해 봤다.
8.00000
을 7로 받아 적은 모습을 볼 수 있다.

실수 저장 자체의 문제가 맞았다.

*/



/* 프로그래밍 노트

일단, 얘를 어떻게 재귀 함수 구조로 만들어야 하는지 감이 안 온다.
printf 자체를 함수 안에 넣어야 할 것 같긴 하다. 

근데 입력 받은 수의 자릿수를 어떻게 알 수 있을까? if문으로 나눠야 하나?
만약에 123412340 같은 것들이 있다면 그것도 조건문으로 나눠야 할 텐데 너무 번거롭지 않나?

내가 생각했을 땐 제일 먼저
3408을 
0.3408로 만들고 -
- * 10 해서 3 출력
- *10 해서 4 출력
- *10 해서 0 출력
- * 10 해서 8 출력 - return;

*/