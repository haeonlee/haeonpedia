// 7-7. 3번 실행되는 재귀호출 함수 2

/*

재귀호출 vs 반복문
    
    재귀호출: 하나의 함수에서 코드를 반복하는 것처럼 보이지만 실제로는 새로운 함수를 실행
        - 장점: 경우에 따라 복잡한 반복문을 간단히 표현할 수 있다
        - 단점: 코드 읽기가 쉽지 않다, 반복 호출되면서 메모리를 사용한다
        따라서 제한적으로 쓰는 것이 좋다

*/

#include <stdio.h>

void fruit(int count);

int main(void)
{
    fruit(1);   // 처음 호출하므로 1을 인수로 준다

    return 0;
}

void fruit(int count)
{
    printf("apple\n"); 
    if (count == 3) return; // 인수가 3이 되면(즉, 호출 횟수가 3이면) 반환하고 끝낸다
    fruit(count + 1);   // 재호출할 때 인수(즉, 호출 횟수)를 1 증가
    printf("jam\n"); // 추가한 코드
}

/* 실행 결과

apple
apple
apple
jam
jam

    jam이 두 번 출력된 이유:
    재귀호출 함수는 최초 호출한 곳이 아니라 이전에 호출한 곳으로 돌아갑니다.
    재귀호출이 수행될 떄마다 함수의 복사본을 만들어보면 쉽게 이해할 수 있습니다. (p.202)

*/