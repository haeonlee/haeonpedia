// 06-1. while문, for문, do ~ while문
// 확인문제3. 반복문을 사용하여 화면에 '$'를 10번 출력하는 프로그램을 작성하세요.

#include <stdio.h>
int main(void)
{
    int i;
    for (i=0; i<10; i++)
    {
        printf("$");
    }

    return 0;
}

/* 실행 결과

$$$$$$$$$$

*/