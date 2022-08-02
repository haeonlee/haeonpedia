// 05-2. if문의 활용과 switch ~ case문
// 2. 다음 프로그램의 실행결과를 참고하여 빈칸을 채워보세요.

#include <stdio.h>

int main(void)
{
    int n;
    printf("정수 입력 : ");
    scanf("%d", &n);
    switch ( n % 3 )
    {
        case 0:
            printf("거짓");
            break;
        default:
            printf("참");
            break;
    }

    return 0;
}

/* 실행 결과

정수 입력 : 1
참

정수 입력 : 2
참

정수 입력 : 3
거짓

*/