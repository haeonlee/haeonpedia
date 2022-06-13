//  도전1. 소수(prime number) 출력 프로그램
/*  2 이상의 정수를 입력하여 2부터 입력한 수까지의 모든 소수를 출력합니다.
    단, 한 줄에 5개씩 5칸 간격으로 출력합니다.
    하나의 정수가 소수인지 판단해서 출력하는 과정은 다음과 같습니다.

    1. 일단 소수라고 가정한다.
    2. 2부터 그 정수보다 하나 작은 수까지 하나라도 나누어 떨어지면 가정을 취소한다.
    3. 1의 가정이 2에서 바뀌지 않았으면 그 정수를 출력한다.

    위의 1~3까지의 과정은 하나의 정수에 대해서 소수를 판별하는 과정이고,
    어떤 수까지의 모든 수를 판별하기 위해서는 1~3까지의 과정을 다시 반복합니다.
*/

//  MEMO: 내 초기 답안이다. 아예 구동 자체가 안 됐는데 왜 안 됐는지 분석할 것이다.

#include <stdio.h>

int main(void)
{
    int num, i, j;
    int count = 0;

    printf("2 이상의 정수를 입력하세요 : ");
    scanf("%d\n", &num);

    for (i=2; i<=num; i++)
    {
        for (j=2; j<i; j++)
        {
            if (i % j == 0) // 2부터 num보다 하나 작은 수까지 나눗셈 연산
            {
                break;
            }

            /* 내 생각엔 여기서 이미 if에서 참이 나오면, else는 판별하지 않고 지나가니까 틀린 것 같다. */

            else
            {
                printf("%5d", i);
                count++;
                if ((count % 5) == 0) printf("\n"); // 한 줄에 5개씩 5칸으로 출력
            }
        }
    }
        
    return 0;
}