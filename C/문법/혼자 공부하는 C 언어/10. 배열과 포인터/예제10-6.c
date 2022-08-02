// 10-6. 크기가 다른 배열을 출력하는 함수

#include <stdio.h>

void print_ary(int *pa, int size);  // 함수 선언, 매개변수 2개

int main(void)
{
    int ary1[5] = { 10, 20, 30, 40, 50 };
    int ary2[7] = { 10, 20, 30, 40, 50, 60, 70 };

    print_ary(ary1, 5);
    printf("\n");
    print_ary(ary2, sizeof(ary2) / sizeof(ary2[0]));
    // sizeof(배열명) / sizeof(배열요소) = 배열 전체의 크기 / 배열 요소 하나의 크기

    return 0;
}

void print_ary(int *pa, int size)
{
    int i;

    for (i=0; i < size; i++)
    {
        printf("%d ", pa[i]);
    }
}

/* 실행 결과

10 20 30 40 50 
10 20 30 40 50 60 70 

*/