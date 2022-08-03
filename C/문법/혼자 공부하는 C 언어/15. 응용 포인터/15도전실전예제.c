// 15. 응용 포인터

/*

    도전 실전 예제. 프로필 교환 프로그램

        두 명의 나이와 키를 입력한 후에 바꾸어 출력합니다.
        단, 나이와 키를 바꾸는 함수는 int형과 double형을 모두 교환할 수 있도록 하나의 함수로 구현하세요.
        다음의 swap 함수 호출 예를 참고하여 작성합니다.

        swap("int", &a, &b);
        swap("double", &a, &b);

    실행 결과
        첫 번째 사람의 나이와 키 입력 : 22 187.5
        두 번째 사람의 나이와 키 입력 : 44 165.4
        첫 번째 사람의 나이와 키 : 44, 165.4
        두 번째 사람의 나이와 키 : 22, 187.5

*/


/*

    아이디어 기록

    - 지금까지 배운 것: 이중 포인터, 배열 포인터, 함수 포인터, void 포인터

    - 애초에 함수 인수 자체가 자료형을 의미하는 문자열, 주소, 주소로 되어 있음
        swap("int", &a, &b);

    - 이건 곧 '포인터' 개념을 사용하여 프로그래밍을 하라는 소리
        

*/


#include <stdio.h>

void swap(char *, void *, void *);

int main(void)
{
    int age1, age2;
    double height1, height2;

    printf("첫 번째 사람의 나이와 키 입력 : ");
    scanf("%d %lf", &age1, &height1);

    printf("두 번째 사람의 나이와 키 입력 : ");
    scanf("%d %lf", &age2, &height2);

    swap("int", &age1, &age2);
    swap("double", &height1, &height2);

    printf("첫 번째 사람의 나이와 키 : %d, %.1lf \n", age1, height1);
    printf("두 번째 사람의 나이와 키 : %d, %.1lf", age2, height2);

    return 0;
}

void swap(char *str, void *pa, void *pb)
{
    int p_int;
    double p_double;

    if (str == "int")
    {
        p_int = *(int *)pa;
        *(int *)pa = *(int *)pb;
        *(int *)pb = p_int;
    }

    else if (str == "double")
    {
        p_double = *(double *)pa;
        *(double *)pa = *(double *)pb;
        *(double *)pb = p_double;
    }

    else
    {
        printf("이상한 값을 넣으셨네용...");
    }
}

/* 실행 결과

첫 번째 사람의 나이와 키 입력 : 22 187.5 
두 번째 사람의 나이와 키 입력 : 44 165.4
첫 번째 사람의 나이와 키 : 44, 165.4 
두 번째 사람의 나이와 키 : 22, 187.5

후기: 와! 한 번에 돼서 너무 신난다!

*/