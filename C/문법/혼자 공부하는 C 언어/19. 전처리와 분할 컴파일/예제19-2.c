// 19-2. 다양한 매크로명의 사용

/*

    매크로명을 만드는 #define

        #define은 매크로명을 만드는 전처리 지시자입니다.
        
        (1) 매크로명은 다른 변수명과 쉽게 구분할 수 있도록 관례상 대문자로 쓰며,


        (2) #define 사용법

            #define 매크로명 치환될부분
            #define PI 3.14159
            
            치환될 부분은 매크로명과 하나 이상의 빈칸을 둡니다.
            (상수 대신에 쓰이는 매크로명은 '매크로 상수'라고 부릅니다.)

            #define INTRO "Perfect C Language \
            & Basic Data Structure"

            만약에 위처럼 치환할 부분이 길어 여러 줄에 써야 한다면 백슬래시를 통해 연결하세요.


        (3) 매크로명의 장점

            매크로명을 정의하면 복잡한 상수나 문장을 의미 있는 단어로 쓸 수 있습니다.


        (4) 매크로명의 단점

            문제가 발생하면 매크로명이 어떤 형태로 치환되는지 다시 확인해야 하므로, 디버깅과 유지 보수가 힘듭니다.
            
            즉, 컴파일러는 전처리가 끝난 후에야
            치환된 소스 파일을 컴파일하고 사용자는 매크로명으로 작성된 소스 코드를 보게 되므로
            컴파일러가 표시하는 에러 메시지를 소스 코드에서 즉시 확인하기 힘듭니다.

            따라서 매크로명은 필요한 경우만 제한적으로 쓰는 것이 좋습니다.

*/

#include <stdio.h>
#define PI 3.14159          // 상수를 매크로명으로 정의
#define LIMIT 100.0         // 상수를 매크로명으로 정의
#define MSG "passed!"       // 문자열을 매크로명으로 정의
#define ERR_PRN printf("허용 범위를 벗어났습니다!\n")       // 출력문을 매크로명으로 정의

int main(void)
{
    double radius, area;

    printf("반지름을 입력하세요(10 이하) : ");
    scanf("%lf", &radius);
    area = PI * radius * radius;    // 면적 계산
    if (area > LIMIT) ERR_PRN;
    else printf("원의 면적 : %.2lf (%s)\n", area, MSG);     // 면적과 메시지 출력

    return 0;
}

/* 실행 결과 1

반지름을 입력하세요(10 이하) : 5
원의 면적 : 78.54 (passed!)

*/

/* 실행 결과 2

반지름을 입력하세요(10 이하) : 7
허용 범위를 벗어났습니다!

*/