// 08-2. 문자를 저장하는 배열
// 3. 다음 코드는 2개의 문자열을 입력받아 위치를 바꾼 후에 출력합니다. 빈칸을 채워 프로그램을 완성하세요.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80], str2[80];
    char temp[80];

    printf("두 문자열 입력 : ");
    scanf("%s %s", str1, str2);
    printf("바꾸기 전 : %s, %s\n", str1, str2);
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
    printf("바꾼 후 : %s, %s\n", str1, str2);

    return 0;
}

/* 실행 결과

두 문자열 입력 : apple banana
바꾸기 전 : apple, banana
바꾼 후 : banana, apple

*/