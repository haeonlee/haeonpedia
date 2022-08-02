// 9-9. 변수의 값을 인수로 주는 경우

#include <stdio.h>

void swap(int x, int y);

int main(void)
{
    int a = 10, b = 10;

    swap(a, b);
    printf("a : %d, b : %d\n", a, b);

    return 0;
}

void swap(int x, int y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}

/* 실행 결과

a : 10, b : 20

    swap() 함수 내에서 바뀐 건 a, b의 복사본
    이름이 같아도 함수가 다르면 메모리에 별도의 저장 공간을 확보하므로 전혀 다른 변수로 쓰임

    더불어 함수는 오직 하나의 값만 반환할 수 있으므로,
    하나의 함수 호출을 통해 두 변수의 값을 바꾸는 것은 불가능함

*/