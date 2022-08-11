// 19-7. #pragma 를 사용한 바이트 얼라인먼트 변경

/*

    #pragma 지시자: 컴파일러의 컴파일 방법을 세부적으로 제어할 때

        1. 사용법
            지시명(directive-name)을 통해 컴파일러의 어떤 기능을 제어할 것인지 알려줍니다.
            pack은 구조체의 패딩 바이트의 크기를 결정하며,
            warning은 경고 메시지를 관리합니다.

            물론, pragma에서는 pack, warning 외에도 많은 지시명을 사용할 수 있습니다.
            그러나 컴파일러에 따라 사용법이 다르거나 지원하지 않을 수 있으므로
            사용하는 컴파일러의 매뉴얼을 참고하여 사용하는 것이 좋습니다.

        2. pack 사용법: 구조체의 패딩 바이트의 크기를 결정
        
            (1) push: 바이트 얼라이먼트를 바꿀 때 현재 규칙을 기억
            (2) pop: 바꾸기 전의 바이트 얼라인먼트 규칙을 적용
            (3) push, pop을 사용하지 않고 크기만 사용
                #pragma pack(1)

        3. warning 사용법: 경고 메시지를 관리

            warning은 컴파일러가 표시하는 경고 메시지를 제거하는 데에 사용 가능합니다.

            경고 메시지
            warning C4101: 'a' :참조되지 않은 지역 변수입니다

            #pragma waring(disable:4101)
            // 4101번 경고 메시지는 모두 표시하지 않음

*/

#include <stdio.h>
#pragma pack(push, 1)   // 바이트 얼라인먼트를 1로 바꿈
typedef struct
{
    char ch;
    int in;
} Sample1;

#pragma pack(pop)       // 바꾸기 전의 바이트 얼라인먼트 적용
typedef struct
{
    char ch;
    int in;
} Sample2;

int main(void)
{
    printf("Sample1 구조체의 크기 : %d바이트\n", sizeof(Sample1));
    printf("Sample2 구조체의 크기 : %d바이트\n", sizeof(Sample2));
    
    return 0;
}

/* 실행 결과

Sample1 구조체의 크기 : 5바이트
Sample2 구조체의 크기 : 8바이트

*/