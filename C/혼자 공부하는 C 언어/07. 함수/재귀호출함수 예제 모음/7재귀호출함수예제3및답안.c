// 예제3. n개의 수를 입력 받아 (n<=20), 그 중 최댓값을 구하라
// 출처: https://m.blog.naver.com/fewus28/220966348725

/* 입력 예시: N = 5 / 입력 정수: 4 1 8 3 7 */
/* 출력 예시: 최댓값은 8입니다. */


#include <stdio.h>

int MaxVal(int n, int *input);

void main()
{
    int n;  // 입력 갯수 n
    int input[20];
    int i = 0;
    int result = 0;

    printf("몇 개의 수를 입력할 건가요? : ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
        scanf("%d", &input[i]);

    result = MaxVal(n-1, input);

    printf("최댓값은 %d입니다.", result);
}

int MaxVal(int n, int *input)
{
    int m;
    if (n == 0)
        return input[0];
    
    m = MaxVal(n - 1, input);
    if (m < input[n])
        return input[n];
    else
        return m;
}



/* 프로그래밍 노트

내 생각엔 두 개를 비교하고, 또 두 개를 비교하고, 또 두 개를 비교하는 걸 계속 해야 할 것 같다.

그리고 매개변수에 숫자를 20개를 넣을 순 없으니까 얘네를 어떻게 한 번에 넣을 것인가 고민해야 할 것이다.
(예제2를 역으로 생각해서 아예 한 숫자로 만들어서 넣으면 되지 않을까?
라고 생각했지만 int 범위로는 20개의 숫자를 다 받아들일 수 없다.)

배열을 쓸 것 같은데? 하고 봤더니 역시나 배열을 쓴 문제였다.
그래서 얘는 풀지는 않고, 답안을 배끼기만 하려고 한다.

*/