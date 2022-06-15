// 8-1. 5명의 나이를 저장할 배열을 선언하고 사용하는 방법 

/* 

배열(array)
용도: 같은 형태의 많은 데이터들을 반복문으로 처리하기 위해

*/

#include <stdio.h>

int main(void)
{
    int ary[5];

    ary[0] = 10;
    ary[1] = 20;
    ary[2] = ary[0] + ary[1];
    scanf("%d", &ary[3]);

    printf("%d\n", ary[2]); // 세 번째 배열 요소 출력: 10+20=30
    printf("%d\n", ary[3]); // 내가 입력한 값 출력
    printf("%d\n", ary[4]); // 쓰레기값 출력

    return 0;

}

/* 실행 결과

900 (입력)
30
900
158

*/