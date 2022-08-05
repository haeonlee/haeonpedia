// 17-12. typedef를 사용한 형 재정의

/*

    typedef를 사용한 형 재정의: 형 재정의를 통해 자료형을 짧고 쉬운 이름으로 사용 가능

        구조체, 공용체, 열거형의 이름은 항상 struct 등 예약어와 함께 써야 합니다.
        특히 함수의 매개변수나 반환값의 형태에 쓰면 함수 원형이 복잡해집니다.
        이때, typedef를 사용하면 자료형의 이름에서 struct와 같은 예약어를 생략할 수 있습니다.

        물론, 재정의하기 전 이름도 함께 사용할 수 있습니다.
        보통 일반 변수명과 구분하기 위해 재정의된 자료형의 이름을 대문자로 쓰기도 합니다.


    typedef 사용법

        typedef 구조체이름 새자료형이름;
        typedef struct student Student;


    형 선언과 동시에 재정의
        재정의하기 전 자료형을 굳이 사용할 필요가 없다면 사용합니다.

        typedef Struct      // 재정의될 것이므로 구조체 이름 생략
        {
            int num;
            double grade;
        } Student;          // 재정의된 자료형의 이름

    
    여기서 잠깐. typedef문으로 기본 자료형 재정의하기
        typedef문은 복잡한 응용 자료형뿐만 아니라 필요에 따라 기본 자료형도 재정의해서 사용할 수 있습니다.
        예를 들어 unsigned int형 변수가 크기와 관련된 데이터를 저장하면,
        자료형 이름이 의미를 갖도록 다음과 같이 재정의할 수 있습니다.

        typedef unsigned int nbyte;

*/

#include <stdio.h>

struct student
{
    int num;
    double grade;
};

typedef struct student Student;     // Student형으로 재정의
void print_data(Student *ps);       // 매개변수는 Student형의 포인터

int main(void)
{
    Student s1 = { 315, 4.2 };      // Student형의 변수 선언과 초기화

    print_data(&s1);                // Student형 변수의 주소 전달

    return 0;
}

void print_data(Student *ps)
{
    printf("학번 : %d\n", ps -> num);
    printf("학점 : %.1lf\n", ps -> grade);
}

/* 실행 결과

학번 : 315
학점 : 4.2

*/