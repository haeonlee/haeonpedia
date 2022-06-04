// 3-10. scanf 함수를 사용한 연속 입력

/*

scanf 함수에 여러 변수를 동시에 입력하는 경우
scanf("%변환문자%변환문자", &a, &b);

1. 변환 문자는 큰따옴표 안에 이어서 나열
2. 변수 사이는 콤마로 구분

*/

#include <stdio.h>

int main(void)
{
    int age; // 나이는 정수형
    double height; // 키는 실수형

    printf("나이와 키를 입력하세요 : "); // 입력 안내 메시지 출력
    scanf("%d%lf", &age, &height); // 나이와 키를 함께 입력
    /* 입력 값은 스페이스바 또는 tab, enter로 구분 */
    printf("나이는 %d살, 키는 %.1lfcm입니다\n", age, height); // 입력값 출력

    return 0;
}

/* 실행 결과
나이와 키를 입력하세요 : 24 161.7
나이는 24살, 키는 161.7cm입니다
*/