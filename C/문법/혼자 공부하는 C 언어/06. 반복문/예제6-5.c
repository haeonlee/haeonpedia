// 6-5. break를 사용한 반복문 종료

/* 

break: 반복문 중간에서 임의로 반복을 끝내고 싶을 때 사용
- 주의할 점: break는 자신을 포함하는 반복문 하나만 벗어남

여기서 잠깐. switch ~ case문과 break
if문과 달리 switch ~ case문의 블록 안에서 break를 사용하면 switch ~ case 블록만 벗어납니다.

*/

#include <stdio.h>

int main(void)
{
    int i;  // 반복 횟수를 세기 위한 제어 변수
    int sum = 0;    // 1부터 10까지의 합을 누적할 변수

    for (i = 1; i <= 10; i++)   // i는 1부터 10까지 증가하면서 10번 반복
    {
        sum += i;   // i 값을 sum을 누적
        if (sum > 30) break;    // 누적한 값이 30보다 크면 반복문을 끝낸다
    }

    printf("누적한 값 : %d\n", sum);
    printf("마지막으로 더한 값 : %d\n", i);

    return 0;
}

/* 실행 결과

누적한 값 : 36
마지막으로 더한 값 : 8

*/