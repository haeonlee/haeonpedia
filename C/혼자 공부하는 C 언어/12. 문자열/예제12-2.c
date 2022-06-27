// 12-2. 포인터로 문자열을 사용하는 법

/* 
    char 포인터로 문자열 사용
        문자열은 주소, 따라서 문자열도 char 포인터에 대입하여 사용
        문자열을 char 포인터에 대입하면
            1. 문자열도 이름을 붙여 사용할 수 있으며
            2. 다른 문자열로 바꿀 수 있음

    여기서 잠깐. 같은 문자열 상수를 여러 번 사용할 때
        같은 문자열을 여러 번 사용한 경우,
        하나의 문자열만 메모리에 저장하고 그 주소를 공유하도록 번역

        char *pa = "apple";
        char *pb = "apple";
        printf("%p, %p", pa, pb);
        "apple"의 주소값 하나를 pa에서도 쓰고, pb에서도 씀

*/

#include <stdio.h>

int main(void)
{
    char *dessert = "apple";

    printf("오늘 후식은 %s입니다.\n", dessert); // 문자열 출력
    dessert = "banana"; // 새로운 문자열 대입, 이때 다른 문자열 "banana"의 위치로 주소 값이 바뀜
    printf("내일 후식은 %s입니다.\n", dessert); // 바뀐 문자열 출력

    return 0;
}

/* 실행 결과

오늘 후식은 apple입니다.
내일 후식은 banana입니다.

*/