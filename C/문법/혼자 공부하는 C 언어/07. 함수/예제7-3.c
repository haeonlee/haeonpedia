// 7-3. 반환값이 없는 함수
// 반환값이 없는 함수: 반환형 자리에 void를 사용합니다.
// 특징. 반환값이 없으므로 수식의 일부로 쓸 수 없습니다.

#include <stdio.h>

void print_char(char ch, int count); // 함수 선언

int main(void)
{
    print_char('@', 5); // 문자와 숫자를 주고 함수 호출
                        

    return 0;
}

void print_char(char ch, int count)
{
    int i;  // i는 0부터 count-1번까지 증가, count번을 반복

    for (i = 0; i < count; i++)
    {
        printf("%c", ch);
    }

    return; // 반환값이 없으므로 return문은 값없이 단독으로 사용
            // 심지어, return문 자체를 생략하는 것도 가능하다: 알아서 함수 수행하고 호출한 곳으로 감
            // 함수 중간에 return문 사용도 가능하다: 그럼 함수가 바로 끝남
    
}

/* 실행 결과

@@@@@

*/
