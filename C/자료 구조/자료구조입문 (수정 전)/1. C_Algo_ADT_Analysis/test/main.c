#include <stdio.h>

int main(void)
{
    int a, b, sum;

    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("%d + %d = %d\n", a, b, sum);

    return 0;
}


/*
int main(void)
{
    int a, b, sum;

    while (scanf("%d %d", &a, &b) != EOF)
    {
        sum = a + b;
        printf("%d + %d = %d\n", a, b, sum);
    }

    return 0;
}
*/