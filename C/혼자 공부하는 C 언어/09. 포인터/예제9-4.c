// 9-4. 포인터에 const 사용

/*

const 예약어를 포인터에 사용: const int *pa = a;
    - pa가 가리키는 변수 a는 pa를 간접 참조하여 바꿀 수 없다는 뜻
    - 즉, *pa = 20; 과 같이 사용할 수 없다는 소리다

여기서 잠깐. 포인터에 const를 사용하는 이유
    - 포인터에 const를 사용하는 대표적인 예: 문자열 상수를 인수로 받는 함수
    - 문자열 상수는 값이 바뀌면 안 되는 저장 공간이므로,
      함수의 매개변수를 통해 값을 바꿀 수 없도록 매개변수로 선언된 포인터에 const를 사용
    - 참고: 12. 문자열과 포인터

*/

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;
    const int *pa = &a;

    printf("변수 a 값 : %d\n", *pa);
    pa = &b;
    printf("변수 b 값 : %d\n", *pa);
    pa = &a;
    a = 20;
    printf("변수 a 값: %d\n", *pa);

    return 0;
}

/* 실행 결과

변수 a 값 : 10
변수 b 값 : 20
변수 a 값: 20

*/