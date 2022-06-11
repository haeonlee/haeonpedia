// 도전1. 체중관리 프로그램
/*  체중(kg)과 키(cm)를 입력하여 BMI(신체질량지수)를 구한 후에,
    BMI의 값이 20.0 이상 25.0 미만이면 "표준입니다"를 출력하고
    그렇지 않으면 "체중관리가 필요합니다"를 출력합니다.
    
    BMI는 표준체중, 저체중, 과제충을 판별하는 수치로
    몸무게를 키의 제곱으로 나누어 구합니다.
    이때 키는 미터(m)단위로 계산합니다. */

// [2022.06.10]: 한 번에 풀었어용ㅎㅎㅎㅎㅎ

#include <stdio.h>

int main(void)
{
    int kg;
    double cm;
    double bmi;

    printf("몸무게(kg)와 키(cm) 입력 : ");
    scanf("%d %lf", &kg, &cm);

    bmi = (double)kg / ((cm*cm) / 10000);

    printf("%s", ((( bmi >= 20) && (bmi < 25)) ? "표준입니다" : "체중 관리가 필요합니다" ));

    return 0;
}

/* 답지

int main(void)
{
    double weight, height, bmi;

    printf("몸무게(kg)와 키(cm) 입력 : ");
    scanf_s("%lf%lf", &weight, &height);

    height = height / 100.0; (또는 height /= 100.0)
    bmi = weight / (height * height);

    ((bmi) >= 20.0) && (bmi < 25.0))
        ? printf("표준입니다.\n")
        : printf("체중 관리가 필요합니다.\n");

    return 0;

}

*/