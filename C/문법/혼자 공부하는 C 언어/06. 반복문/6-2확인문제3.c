// 06-2. 반복문 활용

/*

3. 중첩 반복문을 사용하여 다음과 같이 출력하는 프로그램을 작성합니다.

*   *
 * *
  *
 * *
*   *

*/

/*  MEMO: 됐긴 됐는데 안 될 줄 알았는데 돼서 찝찝하다, if ~ else if문을 내가 이해를 못 했나 싶다(...)
    '첫번째 if에서 참이면 이후 실행문은 그대로 뛰어넘어야 하는 거 아닌가?'라고 생각했는데
    역시나 OR 연산을 쓰는 거였다. */

#include <stdio.h>

int main(void)
{
    int i, j;

    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            if ((i == j) || (i + j == 4)) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}


/*

#include <stdio.h>

int main(void)
{
    int i, j;

    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            if (i == j) printf("*");    // 역시 내가 생각한 대로 이 부분이 틀렸음: OR(||) 사용하세요
            else if (i + j == 4) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}

*/