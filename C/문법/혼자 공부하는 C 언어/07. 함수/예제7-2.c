// 7-2. 매개변수가 없는 함수
// 매개변수가 없는 함수: 매개변수 자리에 void를 사용합니다.

#include <stdio.h>

int get_num(void);  // 함수 선언

int main(void)
{
    int result;

    result = get_num(); // 함수 호출, 반환 값은 result에 저장
                        // 함수를 호출할 땐 괄호 안을 비워두어야 한다(void) 넣지 마세요.

    printf("반환값 : %d\n", result);    // 반환값 출력
    return 0;
}

int get_num(void)   // 매개변수가 없고 반환형만 있다
{
    int num;    // 키보드 입력값을 저장할 변수

    printf("양수 입력 : ");
    scanf("%d", &num);  // 키보드 입력

    while (num < 0)
    {
        printf("양수를 입력하세요!\n");
        printf("양수 입력 : ");
        scanf("%d", &num);
    }

    return num; // 입력한 값 반환
}

/* 실행 결과

양수 입력 : 10
반환값 : 10

*/