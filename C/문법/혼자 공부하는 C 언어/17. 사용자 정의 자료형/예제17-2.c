// 17-2. 배열과 포인터를 멤버로 갖는 구조체 사용

/*

    구조체 멤버로 다양한 자료형을 사용할 수 있습니다.
    e.g. int형, double형, 배열, 포인터, 심지어는 이미 선언된 다른 구조체

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile
{
    char name[20];
    int age;
    double height;
    char *intro;
};

int main(void)
{
    struct profile yuni;    // profile 구조체 변수 선언

    strcpy(yuni.name, "서하윤");
    yuni.age = 17;
    yuni.height = 164.5;

    yuni.intro = (char *)malloc(80);
    printf("자기소개 : ");
    gets(yuni.intro);

    printf("이름 : %s\n", yuni.name);
    printf("나이 : %d\n", yuni.age);
    printf("키 : %.1lf\n", yuni.height);
    printf("자기소개 : %s\n", yuni.intro);
    free(yuni.intro);

    return 0;
}

/* 실행 결과

자기소개 : 항상 행복하세요.
이름 : 서하윤
나이 : 17
키 : 164.5
자기소개 : 항상 행복하세요.

*/