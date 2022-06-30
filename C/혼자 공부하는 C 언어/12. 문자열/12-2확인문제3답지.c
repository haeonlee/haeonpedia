#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80];
    char res_str[80];
    char *star = "**********";
    int len;

    printf("단어 입력 : ");
    scanf("%s", str);

    len = strlen(str);

    if (len <= 5)
    {
        strcpy(res_str, str);
    }
    else
    {
        strncpy(res_str, str, 5);   // 일단 다섯 문자만 복사
        res_str[5] = '\0';          // 마지막에 널 문자 저장
        strncat(res_str, star, len-5);  // 문자열의 길이만큼 별로 채움
    }

    printf("입력한 단어 : %s, 생략한 단어 : %s\n", str, res_str);
    return 0;
}