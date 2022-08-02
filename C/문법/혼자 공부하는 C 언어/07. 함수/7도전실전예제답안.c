#include <stdio.h>

int rec_func(int n);

int main(void)
{
    int res;
    res = rec_func(10);
    printf("%d", res);
}

int rec_func(int n)
{
    if (n == 0) return n; // return 0으로 하든, n으로 하든 상관이 없어요.
    n += rec_func(n-1);
    return n;
}

/* CODE REVIEW:

1. 함수의 매개 변수로 이용되는 n을 이용한다면,
초기화가 되지 않고 계속 값을 이어서 갖고 올 수 있구나.

2. 어디서 어떻게, 어떤 순서로 재귀되는 것일까?
'재귀함수 값을 이용한 연산'이 들어가는 순간, 그 순서가 잘 이해가 되지 않는다.
눈을 감고, rec_func 부분에 또 다른 함수가 들어가 있다고 생각하자.
마트료시카 인형처럼.

그럼 슬슬 이해가 된다.

3. if문을 이용해서 다시 return 하는 원리가 잘 이해가 안 된다.
왜 return 0를 해도, return n을 해도 똑같을까?
return 0을 하라고 했으니까, 매개변수 0을 별도 연산을 거치지 않고 바로 넣어서 값도 0이 나오는구나!

 */