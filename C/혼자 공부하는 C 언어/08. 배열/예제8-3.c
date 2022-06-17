// 8-3. sizeof 연산자를 사용한 배열

/*

배열
- problem: 배열 요소의 개수가 바뀌면 배열을 처리하는 반복문을 모두 수정해야 한다
- solution: 배열 요소의 개수를 직접 계산하여 반복문에 사용한다

배열 요소의 개수
- count = sizeof(배열명) / sizeof(배열요소);
- 반복문뿐만 아니라 배열 요소의 개수가 필요한 모든 곳에 count를 사용할 수 있다!


*/

#include <stdio.h>

int main(void)
{
    int score[5];
    int i;
    int total = 0;
    double avg;
    int count;

    count = sizeof(score) / sizeof(score[0]);

    for (i=0; i<count; i++)
    {
        scanf("%d", &score[i]);
    }

    for (i=0; i<count; i++)
    {
        total += score[i];
    }
    avg = total / (double)count;    // 배열의 개수가 필요한 곳에 count 사용
                                    // total, count 모두 int형이므로 형 변환 연산자 (double) 사용

    for (i=0; i<count; i++)
    {
        printf("%5d", score[i]);
    }
    printf("\n");

    printf("평균 : %.1lf\n", avg);

    return 0;
}

/* 실행 결과

80 95 77 84 100
   80   95   77   84  100
평균 : 87.2

*/