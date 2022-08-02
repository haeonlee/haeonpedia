// 4-2
/* 확인문제3. 태희가 신청한 전체 학점과 평점을 계산하여
신청 학점이 10학점 이상이고 평점 평균이 4.0을 넘는 경우 1을 출력하고,
그렇지 않으면 0을 출력하는 프로그램ㅇ르 작성하세요.
태희가 이전 학기에 신청한 과목당 학점과 얻은 점수는 아래와 같습니다.

국어-3학점-3.8
영어-5학점-4.4
수학-4학점-3.9

각 변수명은 다음과 같습니다.

국어 영어 수학 전체학점 결과저장 국어평점 영어평점 수학평점 평점평균
kor eng mat credits res kscore escore mscore grade

*/

#include <stdio.h>

int main(void)
{
    int kor = 3, eng = 5, mat = 4; // 국어, 영어, 수학의 학점 초기화
    int credits; // 전체 학점을 저장할 변수
    int res; // 연산 결과를 저장할 변수
    double kscore = 3.8, escore = 4.4, mscore = 3.9; // 각 과목의 평점 초기화
    double grade; // 평점의 평균을 저장할 변수

    credits = kor + eng + mat;
    grade = (kscore + escore + mscore) / 3.0 ;
    res = (credits >= 10) && (grade > 4.0);
    printf("%d", res);
}

/* 실행 결과 

1

*/