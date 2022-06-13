// 5-6. switch ~ case문의 사용

/*

switch ~ case문의 사용
- 장점: 정수값에 따라 실행 문장을 선택하기에 좋은 구조
- 단점: 범위를 검사하는 경우엔 적합하지 않음

규칙1. 조건식은 정수식만 사용합니다: 정수형 상수나 변수를 사용 가능, 수식을 사용할 땐 결괏값이 정수여야 함
규칙2. 기본적으로 case는 break를 포함합니다.

여기서 잠깐. break는 어떤 역할을 하나요?
break는 해당 블록을 탈출하는 데 사용합니다. 이 절에서는 switch문을 빠져나올 때 사용합니다.

case와 default는 건너뛸 위치를 표시하는 레이블(lable)의 역할을 함
- 특히 default는 어디에 있어도 상관 없지만, 보통은 모든 case문을 적은 다음 마지막에 넣어 예외 상황을 처리할 때 사용

*/

/*

break의 생략

break는 필요에 따라 생략 가능: 그러나, 대부분은 break를 사용하므로 생략할 땐 주석을 자세히 달고 제한적으로 사용할 것
    e.g. 1등은 1등, 2등, 3등 상금을 동시에 받고, 2등은 2등, 3등 상금을 받아서
         다음 케이스로 이동해서 또 명령문을 수행해도 괜찮은 경우

*/

#include <stdio.h>

int main(void)
{
    int rank = 2, m = 0;

    switch (rank)   // rank의 값과 일치하는 상수를 가진 case의 위치로 건너 뜀
    {
    case 1: // rank의 값이 1이면 아래 수행하고 바로 printf문으로
        m = 300;
        break;
    case 2: // rank의 값이 2이면 아래 수행하고 바로 printf문으로
        m = 200;
        break;
    case 3: // rank의 값이 3이면 아래 수행하고 바로 printf문으로
        m = 100;
        break;
    default: // rank와 일치하는 case 값이 없으면 m=10 수행하고 printf문으로
        m = 10;
        break;
    }

    printf("m : %d\n", m);
    
    return 0;
}

/* 실행 결과

m : 200

*/