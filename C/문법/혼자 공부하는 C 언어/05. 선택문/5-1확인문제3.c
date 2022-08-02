// 5-1. if문
/*  3. 키가 187.5cm 이상이고 몸무게가 80.0kg 미만이면 ok를 출력하고
    그 이외의 경우에는 cancel을 출력하는 프로그램을 작성하세요.
    키는 179.5, 몸무게는 75.0으로 double형 변수에 초기화합니다.
*/

#include <stdio.h>
int main(void)
{
    double height = 179.5;  // 키를 저장할 변수 선언과 초기화
    double weight = 75.0;   // 몸무게를 저장할 변수 선언과 초기화
    if ( (height >= 187.5) && (weight <= 80.0) ) // 키가 187.5 이상이고 몸무게가 80 미만
    {
        printf("ok\n"); // ok 출력
    }
    else    // 그 이외의 경우
    {
        printf("cancel\n"); // cancle 출력
    }

    return 0;
}

/* 실행 결과

cancel

*/