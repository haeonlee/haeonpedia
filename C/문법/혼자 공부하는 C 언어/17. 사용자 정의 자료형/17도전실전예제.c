// 17. 사용자 정의 자료형

/*

    도전 실전 예제. 성적 처리 프로그램

        학생 5명의 국어, 영어, 수학 점수를 입력하여 총점, 평균, 학점을 구하고,
        총점 순으로 정렬하여 출력합니다.

        학점은 평균이 90점 이상이면 A, 80점 이상이면 B, 70점 이상이면 C,
        그 외는 F로 평가합니다.


*/

#include <stdio.h>

typedef struct {
    int num;
    char name[20];
    int kor;
    int eng;
    int mat;
} Student;

int main(void)
{
    Student list[5];
    printf("학번 : ");
    printf("이름 : ");
    printf("국어, 영어, 수학 점수 : ");

    printf("# 정렬 전 데이터...\n");

    printf("# 정렬 후 데이터...\n");
}