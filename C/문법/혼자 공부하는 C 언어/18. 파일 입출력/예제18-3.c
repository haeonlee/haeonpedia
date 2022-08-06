// 18-3. 문자열을 한 문자씩 파일로 출력하기

/*

    문자 출력 함수 fputc: 한 문자를 파일로 출력할 때

        fputc 함수에 출력한 문자와 파일 포인터를 인수로 주며 파일로 문자를 출력합니다.
        반환값은 출력한 문자를 다시 반환하며, 에러가 발생하면 EOF를 반환합니다.

        (1) fputc 함수도 스트림 파일의 버퍼를 사용합니다.
            즉, 문자가 하나씩 하드디스크에 직접 저장되는 것이 아니고
            버퍼에 데이터를 모은 후에 한 번에 출력합니다.

            만약, 버퍼의 데이터를 즉시 장치로 출력해야 한다면 fflush 함수를 사용합니다.

*/

#include <stdio.h>

int main(void)
{
    FILE *fp;
    char str[] = "banana";
    int i;

    fp = fopen("b.txt", "w");
    if (fp == NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    i = 0;
    while (str[i] != '\0')
    {
        fputc(str[i], fp);
        i++;
    }
    fputc('\n', fp);
    fclose(fp);

    return 0;
}

/* 실행 결과

    프로젝트 폴더에서 b.txt 파일이 생기고,
    banana라는 텍스트가 보입니다.

*/
