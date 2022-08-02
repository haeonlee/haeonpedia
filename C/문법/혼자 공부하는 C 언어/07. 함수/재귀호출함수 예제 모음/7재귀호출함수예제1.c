// 예제1. 양의 정수 n을 입력 받아, 1부터 n까지의 합을 구하라.
// 출처: https://m.blog.naver.com/fewus28/220966348725

/* 입력 값이 10이면, 55가 출력되어야 합니다.
   다음 재귀 관계를 이용하세요. (재귀 함수 사용)
   - 1부터 N까지의 합 -> 1부터 (N-1)까지의 합에 N을 더한 값 */

/* code review

이미 한 번 풀어본 문제지만, 한 번 더 풀어보면서 공부하는 시간을 가졌습니다.

if랑 else로 구분하니까 깔끔하게 재귀 함수의 구조가 보였다.
또한 return 값을 재귀 함수를 넣어서 연산하는 식으로 쓴 코드라서, '이렇게 쓸 수도 있구나' 하고 공부했다.

재귀호출함수를 생각할 때 주의할 것
1. 마트료시카를 상상하라
2. if ~ else로 깔끔하게 정리하라


*/

#include <stdio.h>

int rec_sum(int number);

int main(void)
{
    int num, sum;

    printf("정수 입력 : ");
    scanf("%d", &num);

    sum = rec_sum(num);
    printf("결과는 %d입니다.", sum);

}

int rec_sum(int number)
{
    if (number == 0) return 0;

    else
        return number + rec_sum(number-1);
    

    /* 내 코드 
    if (number == 0) return 0;
    number += rec_sum(number-1);
    return number;
    */
}

