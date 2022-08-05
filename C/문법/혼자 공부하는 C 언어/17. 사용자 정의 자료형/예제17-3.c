// 17-3. 다른 구조체를 멤버로 갖는 구조체 사용

#include <stdio.h>

struct profile
{
    int age;
    double height;
};

struct student
{
    struct profile pf;  // 구조체를 멤버에 사용
    int id;
    double grade;
};

int main(void)
{
    struct student yuni;

    yuni.pf.age = 17;
    yuni.pf.height = 164.5;
    yuni.id = 315;
    yuni.grade = 4.3;

    printf("나이 : %d\n", yuni.pf.age);
    printf("키 : %.1lf\n", yuni.pf.height);
    printf("학번 : %d\n", yuni.id);
    printf("학점 : %.1lf\n", yuni.grade);

    return 0;
}

/* 실행 결과

나이 : 17
키 : 164.5
학번 : 315
학점 : 4.3

*/