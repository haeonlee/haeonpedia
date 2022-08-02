/* 코드 리뷰

포인터를 매개 변수로 받는 녀석은 깔끔하게 포인터만 써서 주소 값만 보내세요

void line_up(double *maxp, double *midp, double *minp)
{
     if (*maxp < *midp) swap(maxp, midp);
     if (*maxp < *minp) swap(maxp, minp);
     if (*midp < *minp) swap(midp, minp);
}

*/


#include <stdio.h>

void swap(double *ap, double *bp);               // 두 실수를 바꾸는 함수
void line_up(double *maxp, double *midp, double *minp);  // 함수의 선언

int main(void)
{
     double max, mid, min;

     printf("실수값 세 개 입력 : ");
     scanf("%lf%lf%lf", &max, &mid, &min);

     line_up(&max, &mid, &min);           // 세 변수의 값을 정렬하는 함수 호출
     printf("정렬된 값 출력 : %.1lf, %.1lf, %.1lf\n", max, mid, min);

     return 0;
}

void swap(double *ap, double *bp)
{
     double temp;

     temp = *ap;
     *ap = *bp;
     *bp = temp;
}

void line_up(double *maxp, double *midp, double *minp)
{
     if (*maxp < *midp) swap(maxp, midp);
     if (*maxp < *minp) swap(maxp, minp);
     if (*midp < *minp) swap(midp, minp);
}