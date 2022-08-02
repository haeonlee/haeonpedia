// 12-11. 두 문자열 중 길이가 긴 단어 출력

/*

    strlen 함수: 문자열의 길이를 계산함
        문자열을 저장하는 char 배열은 다양한 길이의 문자열을 저장할 수 있도록 크게 선언
        따라서, 배열의 크기와 배열 속 문자열의 길이는 다를 수 있음
        strlen 함수는 배열에 저장된 문자열의 실제 길이를 반환함

        strlen(크기를 확인할 배열명);

*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80], str2[80];
    char *resp;     // 문자열이 긴 배열을 선택할 포인터

    printf("2개의 과일 이름 입력 : ");
    scanf("%s%s", str1, str2);
    if (strlen(str1) > strlen(str2))
        resp = str1;
    else 
        resp = str2;
    printf("이름이 긴 과일은 : %s\n", resp);

    return 0;
}

/* 실행 결과

2개의 과일 이름 입력 : apple banana
이름이 긴 과일은 : banana

*/