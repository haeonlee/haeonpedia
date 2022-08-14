// 19-10. 헤더 파일의 중복 포함 문제 해결 방법

/*

    헤더 파일의 필요성과 문제
    
        분할 컴파일을 할 땐 사용자 정의 헤더 파일이 필요합니다.
        헤더 파일은 텍스트 파일로 소스 코드의 일부를 따로 만들어 필요한 파일에서 인클루드해서 씁니다.
        헤더 파일은 각 파일에 공통으로 필요한 코드를 모아 만듭니다.

        함수의 선언, extern 선언, 구조체 선언 등을 헤더 파일로 만들면,
        필요할 때 인클루드하여 쉽게 공유할 수 있습니다.

        장점
        1. 헤더 파일 내용만 수정하면, 그를 인클루드하는 모든 파일에서 수정한 내용을 빠르게 반영합니다
        2. 다른 프로그램에서 재활용하는 것이 용이합니다

        단점
        1. 다만, 헤더 파일을 재활용하는 경우 구조체 등이 중복 선언될 수 있습니다

        따라서 헤더 파일 중복 문제를 해결하는 방법을 찾아보겠습니다.


    헤더 파일 중복 문제의 해결법

        조건부 컴파일 전처리 명령으로 헤더 파일의 중복 문제를 해결합니다.
        즉, 헤더 파일의 처음에 특정 매크로명을 정의하여 같은 헤더 파일이 두 번 이상 포함될 때는
        조건 검사를 통해 헤더 파일이 중복 포함되지 않도록 만듭니다.

        #ifndef _POINT_H_       
        #define _POINT_H_

        와 같은 부분을 넣으면,
        main.c를 처음에 가동할 때 #ifndef가 맞기 때문에 구조체 선언이 실행됩니다.
        그러나 LINE 구조체 선언에 속한 부분에서는 #ifndef가 거짓이 되기 때문에,
        구조체 선언이 실행되지 않습니다.

        이때, 매크로명은 헤더 파일명과 비슷하게 만들어
        헤더 파일이 다르면 인클루드하더라도 매크로명이 중복되지 않도록 합니다.

*/

// 파일명: point.h
// Point 구조체 선언

#ifndef _POINT_H_        /* _POINT_H 매크로명이 정의되어 있지 않으면 */
#define _POINT_H_       // _POINT_H 매크로명 정의
// 조건부 컴파일 전처리로 헤더 파일 중복 포힘 문제를 해결한 코딩

typedef struct
{
    int x;
    int y;
} Point;

#endif                  // #ifdef _POINT_H_의 끝


// 파일명: line.h
// Line 구조체 선언

#include "point.h"      // Point 구조체를 포함

typedef struct
{
    Point first;        // 첫 번째 점
    Point second;       // 두 번째 점
} Line;


// 파일명: main.c
// Point와 Line 구조체 모두 사용

#include <stdio.h>
#include "point.h"
#include "line.h"

/*

이때, line.h가 point.h를 인클루드하므로 결국 main.c에는 point.h가 중복 포함되는 문제가 발생합니다.
이 경우, Point 구조체가 두 번 선언되므로 중복 선언 에러가 발생합니다.
함수의 선언이나 extern 선언의 경우는 중복 선언이 가능하지만, 구조체는 중복 선언이 허용되지 않습니다.

*/

int main(void)
{
    Line a = { {1, 2}, {5, 6} };            // Line 구조체 변수의 초기화
    Point b;                                // 가운데 점의 좌표를 저장할 점

    b.x = ( a.first.x + a.second.x ) / 2;   // 가운데 점의 x좌표 계산
    b.y = ( a.first.y + a.second.y ) / 2;   // 가운데 점의 y좌표 계산
    printf("선의 가운데 점의 좌표 : (%d, %d)\n", b.x, b.y);

    return 0;
}

/* 실행 결과

선의 가운데 점의 좌표 : (3, 4)

*/
