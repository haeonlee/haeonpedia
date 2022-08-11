// 19-6. #if, #ifdef #else #endif를 사용한 조건부 컴파일

/*

    조건부 컴파일 지시자

        조건부 컴파일은 프로그램의 호환성을 좋게 합니다.
        C언어의 기본 문법은 같지만 컴파일러와 운영체제에 따라
        자료형의 크기나 지원되는 라이브러리 함수가 다를 수 있습니다.

        따라서 조건부 컴파일 기능을 사용하며
        컴파일할 코드를 구별하면 서로 다른 컴파일러에서 컴파일이 가능한 코드를 만듭니다.

        조건부 컴파일은 소스 코드를 조건에 따라 선택적으로 컴파일합니다.
        이때 #if, #else #elif #ifdef #ifndef, #endif 등의
        전처리 지시자를 다양한 방법을 조합하여 사용합니다.



    전처리 연산자 #defined : 조건식에 특정 매크로명이 정의되어 있는지 검사할 때

        (1) BIT16 매크로명이 정의되어 있는지 확인하여 컴파일한다면 다음과 같이 작성합니다.

        #if defined BIT16 (= #ifdef BIT16)
            컴파일할 문장
        #endif

        이때, #if와 defined를 묶어 #ifdef로 쓸 수 있습니다.

        
        (2) BIT16 매크로명이 정의되지 않은 경우를 확인할 땐

        #if !defined BIT16 (= #ifndef BIT16)
            컴파일할 문장
        #endif

        
        (3) #ifdef #ifnedf는 매크로명의 정의 여부만 확인할 수 있으므로
        다른 연산자와 함께 조건식을 만들 때는 defined나 !defined 연산자를 사용해야 합니다

        #if (defined(BIT16) && (VER >= 6)) 
            컴파일할 문장
        #endif

    #error 지시자: 조건을 만족하지 않은 경우 컴파일 자체를 중단할 때
    
        #if VER >= 6
            printf("버전 %d입니다.\n", VER);
        #else
        #error 컴파일러 버전은 6.0 이상이어야 합니다.   // 메시지를 보여주고 컴파일 종료
        #endif


*/

#include <stdio.h>
#define VER 7       // 치환될 부분이 있는 매크로명 정의
#define BIT16       // 치환될 부분이 없는 매크로명 정의

int main(void)
{
    int max;

#if VER >= 6                        // 매크로명 VER이 6 이상이면
    printf("버전 %d입니다.\n", VER);
#endif                              // #if의 끝

#ifdef BIT16                        // 매크로명 BIT16이 정의되어 있으면
    max = 32767;
#else                               // 매크로명 BIT16이 정의되어 있지 않으면
    max = 2147483647;
#endif                              // #ifdef의 끝

    printf("int형 변수의 최댓값 : %d\n", max);

    return 0;
}

/* 실행 결과

버전 7입니다.
int형 변수의 최댓값 : 32767

*/