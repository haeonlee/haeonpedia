// 6-2. for문을 사용한 반복문

/*

for문

for(초기식; 조건식; 증감식)
{
    실행문;
}

실행 순서
a. 초기식 -> 조건식
1. 조건식 -> 실행문
2. 실행문 -> 증감식
3. 증감식 -> 조건식

*/

/*

for문 사용 시 주의점
1.  초기식, 조건식, 증감식은 반복 횟수를 알기 쉽게 작성합니다
    e.g. for (i = 0; i <3; i++) // i의 값이 0, 1, 2일 때 3번 반복
         대부분 위 형식을 많이 사용한다. 조건식에 사용한 값이 반복 횟수가 된다.
2.  반복 횟수를 세는 변수를 반복문 안에서 바꾸지 마세요.

*/

#include <stdio.h>

int main(void)
{
    int a = 1;
    int i;  // 반복 횟수를 세기 위한 변수

    for (i = 0; i < 3; i++) // (1) i는 0으로 초기화된 후에 (2) 3보다 작은 동안
    {                       // (3) 하나씩 증가하면서(i++): 총 3번 반복한다고 보면 됨
        a = a * 2;
    }

    printf("a : %d\n", a); // for문을 빠져나오면 a값 출력

    return 0;
}

/* 실행 결과

a : 8

*/