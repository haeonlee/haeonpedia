//  07-1. 함수의 작성과 사용
/*  3. 187cm를 미터 단위로 환산하여 출력하는 프로그램을 작성하세요.
    단, cm를 m로 반환하는 함수를 만들고 함수 호출을 통해 구현합니다. */

#include <stdio.h>

double centi_to_meter(int cm); // 함수 선언

int main(void)
{
    double res; // 함수 반환값을 저장할 변수

    res = centi_to_meter(187);  // 함수 호출, 반환값을 res에 저장
    printf("%.2lfm\n", res);

    return 0;
}

double centi_to_meter(int cm)
{
    double temp;    // 필요한 변수 선언

    temp = (double)cm / (double)100;  // 매개변수 cm의 값을 m 단위로 환산
    /*  답지: temp = cm / 100.0 */
    /*  MEMO: 나는 cm는 int형이고, temp는 double형이니 형 변환을 해 줘야 한다고 해서 저렇게 썼다.
        물론 하나만 실수여도 자동 형 변환이 된다는 건 알았지만, 왠지 정확하게(?) 하는 게 좋을 것 같아서.
        어떻게 하는 게 더 효율적인 방법인지 궁금하다. */
    /*  결론: 명시적으로 늘 쓰면서 코딩하자!
        근데 (double)100보다는 100.0이 훨씬 코드가 깔끔한 것 같다. 상수는 직접 실수로 바꿔서 쓰자. */

    return temp;    // 환산된 값 반환
}

/* 실행 결과

1.87m

*/