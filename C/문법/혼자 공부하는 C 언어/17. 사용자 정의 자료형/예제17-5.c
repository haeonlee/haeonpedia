// 17-5. 구조체를 반환하여 두 변수의 값 교환

/*

    구조체 변수를 함수 매개변수에 사용하기

        구조체 변수는 대입 연산이 가능하므로,
        함수의 인수로 주거나 함수에서 여러 개의 값을 구조체로 묶어 동시에 반환하는 것이 가능합니다.

        두 변수의 값을 바꾸는 함수는 포인터가 필요합니다.
        그러나 구조체 변수를 사용해 값을 주고받으면 포인터 없이도 두 변수의 값을 바꾸는 함수를 만들 수 있습니다.

*/

#include <stdio.h>

struct vision
{
    double left;
    double right;
};

struct vision exchange(struct vision robot);

int main(void)
{
    struct vision robot;
    
    printf("시력 입력 : ");
    scanf("%lf%lf", &(robot.left), &(robot.right));
    robot = exchange(robot);
    printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);

    return 0;
}

struct vision exchange(struct vision robot)
{
    double temp;

    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;

    return robot;
}

/* 실행 결과

시력 입력 : 15.5 20.0
바뀐 시력 : 20.0 15.5

*/