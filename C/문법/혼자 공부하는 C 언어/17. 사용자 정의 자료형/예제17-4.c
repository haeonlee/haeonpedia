// 17-4. 최고 학점의 학생 데이터 출력

/*

    구조체 변수의 초기화와 대입 연산

        구조체 변수도 일반 변수와 같이 선언과 동시에 초기화가 가능합니다.
        단, 여러 개의 멤버를 초기화하므로 배열 초기화와 비슷한 방법을 사용합니다.
        초깃값을 중괄호로 묶고 각 멤버 형태에 맞는 값으로 초기화합니다.
        구조체 변수의 초기화 방법과 다른 변수를 대입하는 예를 살펴보겠습니다.

    구조체 형선언, 구조체 변수 선언, 초기화 동시에 하기
        이때 구조체 선언을 함수 밖에서 하면 함께 선언되는 변수가 전역 변수가 됩니다.

        struct student
        {
            int id;
            char name[20];
            double grade;
        } s1 = { 315, "홍길동", 2.4 };
        
*/

#include <stdio.h>

struct student
{
    int id;
    char name[20];
    double grade;
};

int main(void)
{
    struct student s1 = { 315, "홍길동", 2.4 },
                   s2 = { 316, "이순신", 3.7 },
                   s3 = { 317, "세종대왕", 4.4 };
    
    struct student max;     // 최고 학점을 저장할 구조체 변수

    max = s1;               // s1을 최고 학점으로 가정
    if (s2.grade > max.grade) max = s2;
    if (s3.grade > max.grade) max = s3;

    printf("학번 : %d\n", max.id);
    printf("이름 : %d\n", max.name);
    printf("학점 : %.1lf\n", max.grade);

    return 0;
}

