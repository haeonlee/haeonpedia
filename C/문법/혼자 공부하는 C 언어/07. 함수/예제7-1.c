// 7-1. 2개의 함수로 만든 프로그램

/* 

함수: 기능을 수행하는 코드 단위
     e.g. main 함수, 표준 라이브러리 함수(printf, scanf 등을 말한다)

     c.f. 함수 속 변수명은 선언한 블록 내부로 제한한다, 따라서 둘 이상의 함수에서 같은 이름의 변수를 선언해도 괜찮다. 

C언어에서 표준으로 제공하는 함수 외에도 자주 사용하는 코드를 함수로 만들기 위해서

    1. 함수 정의: 함수를 실제로 코드를 만드는 것, 기능을 구현

        함수는 다른 함수와 분리되어 독립적으로 정의한다.

        함수 원형(fuction prototype) 구성을 위한 질문 3가지
        (1) 함수명: 함수의 기능에 맞는 이름은 무엇인가?
        (2) 매개변수: 함수가 기능을 수행하는 데 필요한 데이터는 무엇인가?
        (3) 반환형: 함수가 수행된 후 결과는 무엇인가?

        반환형 함수명(매개변수1, 매개변수2)     // 매개변수의 자료형이 같아도 콤마로 구분
        {
            함수가 수행하는 명령
        }

        c.f. 함수의 반환 값은 수식의 일부로 사용할 수 있습니다. (e.g. result = sum(a,b) * 2)


    2. 함수 호출: 함수 호출을 해야 함수를 사용할 수 있음

        함수를 호출할 때 이름을 사용하며, 함수에 필요한 데이터를 괄호 안에 넣어 줍니다.
        이를 인수(argument)라 합니다.
        인수는 상수나 변수를 쓸 수 있으며, 수식을 사용하면 수식의 결괏값이 인수로 쓰입니다.

        인수의 값은 호출된 함수의 매개변수(parameter)에 복사되어 사용됩니다.

        
    3. 함수 선언: 프로그램 상단에서 어떤 함수를 사용할 것이라고 컴파일러에게 정보를 줌

        함수 선언은 함수 원형에 세미콜론을 붙이면 됩니다.
        이때, 매개변수 이름은 생략할 수 있습니다.

        함수 선언이 필요한 이유
        이유1. 함수 선언에서 반환값의 형태를 확인: 컴파일러는 반환값만큼의 저장 공간을 준비합니다
        이유2. 함수의 호출 형식에 문제가 없는지 검사합니다: 예를 들어 정수 2개가 필요한데, 인수로 실수를 주면 경고 메시지를 띄움

        여기서 잠깐. 함수 선언이 없다면 함수 정의는 항상 함수 호출 이전에 있어야 합니다.
        그러나 여러 함수 간의 호출 관계가 엉켜 있으면 순서에 맞게 정의하는 일이 쉽지 않습니다.
        따라서 필요한 함수를 main 함수 밑에 차례로 만들고, main 함수 앞엔 모든 함수를 선언하는 편이 좋습니다.
        또한 분할 컴파일하는 프로그램에서 호출하는 함수와 호출되는 함수가 서로 다른 파일에 있으면 반드시 선언이 필요합니다.

*/


#include <stdio.h>

int sum(int x, int y);  // sum 함수 선언: p.186에서 설명

int main(void)
{
    int a = 10, b = 20; 
    int result;         // 두 정수를 더한 결과(result)를 출력할 변수

    result = sum(a,b);  // sum 함수 호출
    printf("result : %d\n", result);

    return 0;
} // main 함수의 끝

int sum(int x, int y)   // sum 함수 정의
{
    int temp;   // 두 정수의 합을 잠시 저장할 변수

    temp = x + y;   // x + y의 값을 temp에 보관

    return temp;    // temp의 값을 반환

    /* 또는 return (x+y); 로 간단하게 적을 수도 있음 */
}

/* 실행 결과

result : 30

*/