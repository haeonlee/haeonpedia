// 3-7. char 배열에 문자열 복사

/* char 배열에 새로운 문자열 저장 방법: strcpy 함수
strcpy 함수를 사용하려면, 소스 코드에 string.h 헤더 파일을 포함 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char fruit[20] = "strawberry"; // strawberry로 초기화

    printf("%s\n", fruit); // strawberry 출력
    strcpy(fruit, "banana"); // fruit에 banana 복사
    printf("%s\n", fruit); // banana 출력

    return 0;
}

/* 실행 결과
strawberry
banana
*/