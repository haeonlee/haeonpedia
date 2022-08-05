// 17. 사용자 정의 자료형

/*

    도전 실전 예제. 성적 처리 프로그램

        학생 5명의 국어, 영어, 수학 점수를 입력하여 총점, 평균, 학점을 구하고,
        총점 순으로 정렬하여 출력합니다.

        학점은 평균이 90점 이상이면 A, 80점 이상이면 B, 70점 이상이면 C,
        그 외는 F로 평가합니다.


*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int num;
    char name[20];
    int kor;
    int eng;
    int mat;
    int sum;
    double avg;
    char credit;
} Student;

void exchange(Student *lp);

int main(void)
{
    Student list[5];
    int i;
    char temp_name[20];

    for (i=0; i<5; i++)
    {
        printf("학번 : ");
        scanf("%d", &list[i].num);
        printf("이름 : ");
        scanf("%s", temp_name);
        strcpy(list[i].name, temp_name);
        printf("국어, 영어, 수학 점수 : ");
        scanf("%d %d %d", &list[i].kor, &list[i].eng, &list[i].mat);
        list[i].sum = list[i].kor + list[i].eng + list[i].mat;
        list[i].avg = (list[i].sum / 3);

        if (list[i].avg >= 90) list[i].credit = 'A';
        else if (list[i].avg >= 80) list[i].credit = 'B';
        else if (list[i].avg >= 70) list[i].credit = 'C';
        else list[i].credit = 'F';
    }
    
    printf("# 정렬 전 데이터...\n");
    for (i=0; i<5; i++)
    {
        printf("%5d%10s%5d%5d%5d%5d%5.1lf%5c\n",
        list[i].num, list[i].name, list[i].kor, list[i].eng, list[i].mat,
        list[i].sum, list[i].avg, list[i].credit);
    }

    // 정렬을 하는 함수를 만들자
    // 5, 3, 2, 1, 4
    // 정렬을 했다고 쳐, 그럼 모든 걸 다 바꿔야 하니까 아예 덩어리로 바꿔야 함
    // 작은 녀석을 겁나 비교하고, 덩어리를 바꿔야 돼

    exchange(list);

    printf("# 정렬 후 데이터...\n");
    for (i=0; i<5; i++)
    {
        printf("%5d%10s%5d%5d%5d%5d%5.1lf%5c\n",
        list[i].num, list[i].name, list[i].kor, list[i].eng, list[i].mat,
        list[i].sum, list[i].avg, list[i].credit);
    }

    return 0;
}

void exchange(Student *lp)
{
    Student temp;
    int i, j;

    for (i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            if ( lp[i].avg >= lp[j].avg ) 
            {
                temp = lp[i];
                lp[i] = lp[j];
                lp[j] = temp;
            }
        }
    }
}

/* 실행 결과

학번 : 315
이름 : 홍길동
국어, 영어, 수학 점수 : 80 75 90
학번 : 316
이름 : 이순신
국어, 영어, 수학 점수 : 88 92 100
학번 : 317
이름 : 서하윤
국어, 영어, 수학 점수 : 95 99 100
학번 : 318
이름 : 유관순
국어, 영어, 수학 점수 : 84 70 7
학번 : 319
이름 : 박신혜
국어, 영어, 수학 점수 : 60 65 40
# 정렬 전 데이터...
  315 홍길동   80   75   90  245 81.0    B
  316 이순신   88   92  100  280 93.0    A
  317 서하윤   95   99  100  294 98.0    A
  318 유관순   84   70    7  161 53.0    F
  319 박신혜   60   65   40  165 55.0    F
# 정렬 후 데이터...
  317 서하윤   95   99  100  294 98.0    A
  316 이순신   88   92  100  280 93.0    A
  315 홍길동   80   75   90  245 81.0    B
  319 박신혜   60   65   40  165 55.0    F
  318 유관순   84   70    7  161 53.0    F

*/


/*

    내가 헷갈리는 것

        Q1. 배열을 함수의 매개변수로 쓸 때 포인터로 왜 줘야 하는가?
        A1. 

        Q2. 포인터로 매개변수를 주었을 때, * 등 없이 깔끔하게 표현해도 되는 이유는?
        A2. 

*/

/*

    오류 기록: 이렇게 하니까 역방향으로 기록됨

        for (i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                if ( lp[j].avg >= lp[i].avg ) 
                {
                    temp = lp[i];
                    lp[i] = lp[j];
                    lp[j] = temp;
                }
            }
        }

*/