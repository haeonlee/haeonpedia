// 15-2. 이중 포인터를 사용한 포인터 교환

/*

    이중 포인터 활용 1. 포인터 값을 바꾸는 함수의 매개 변수

    이중 포인터는 포인터의 값을 바꾸는 함수의 매개변수에 사용합니다.
    예를 들어 다음과 같이 2개의 포인터가 문자열을 연결하고 있습니다.

    char *pa = "success";
    char *pb = "failure";

    이때 두 포인터가 다른 문자열을 연결하도록 포인터의 값을 바꾸는 함수를 만들어보겠습니다.

*/

#include <stdio.h>

void swap_ptr(char **ppa, char **ppb);  // 매개변수로 이중 포인터 사용

int main(void)
{
    char *pa = "success";
    char *pb = "failure";
    /* 문자열을 포인터에 저장하는 이유,
    char 저장소 하나당 하나의 문자만 저장 가능하므로
    시작점을 알아서 문자들의 나열을 문자열로 취급하기 위함 */

    printf("pa -> %s, pb -> %s\n", pa, pb);
    swap_ptr(&pa, &pb);     // pa, pb 주소를 인수로 주고 호출
    printf("pa -> %s, pb -> %s\n", pa, pb);

    return 0;
}

void swap_ptr(char **ppa, char **ppb)
{
    char *pt;
    pt = *ppa;      // ppa가 가리키는 pa의 값(즉, "success"의 주소 시작값)을 pt에 저장
    *ppa = *ppb;    // ppb가 가리키는 pb의 값(즉, "failure"의 주소 시작값)을 ppa가 가리키는 pa에 저장
    *ppb = pt;      // pt의 값(즉, "success"의 주소 시작값)을 ppb가 가리키는 pb에 저장

    // 과정이 이해 안 되면 424p 보세요.
}

/* 실행 결과

pa -> success, pb -> failure
pa -> failure, pb -> success

*/