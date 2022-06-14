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
    if (n == 0) return n;
    n += rec_func(n-1);
    return n;
}

/* CODE REVIEW:

함수를 정의하면서 생성된 n을 이용하한다면,
중간에 초기화가 되지 않고 계속 값을 이어서 갖고 올 수 있구나.

 */