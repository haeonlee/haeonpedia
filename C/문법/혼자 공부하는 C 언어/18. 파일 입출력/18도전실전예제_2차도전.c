// 18. 파일 입출력

/*

    도전 실전 예제1. 단어 검출 프로그램

        텍스트 파일에서 등록된 단어 이외의 단어를 찾아 새로운 파일에 출력합니다.
        모든 단어의 길이는 최대 20자, 등록 단어 수는 10개로 제한하며 검출 대상 단어 수는 제한이 없습니다.
        다음 실행결과는 b.txt에서 a.txt에 등록되지 않은 단어를 찾아 c.txt에 출력합니다.

*/

/*

    아이디어 기록

        1. 조건 분석

        (1) 모든 단어의 길이는 최대 20자이다.
            char word[21];
            과 같은 형식으로 단어를 나열해야 한다.

        (2) 등록 단어는 최대 20자, 등록 단어의 수는 최대 10개로 제한한다.
            등록 단어를 char registered_word[21][10] = { }
            의 이차원 배열로 선언하는 것은 어떨까?
            단, 등록 단어의 수가 10개 미만일 수 있으므로 모든 배열을 0으로 초기화해야 한다.

        (3) 검출 대상 단어 수는 제한이 없습니다.
            즉, 검출 대상 단어는 배열에 저장하지 말고
            그때그때 입력한 다음에 등록 단어랑 비교하고(그렇다면, for문에서 i<10이 되겠지?)
            바로 c.txt로 출력하라는 소리다.

        2. 과정 분석
        
        (1) 선언
        FILE *afp;
        FILE *bfp;
        FILE *cfp;
        char re_word[10][21] = { 0, };
        char new_word[21];
        
        (2) 명령문
        re_word[10][21]에 하나씩 a.txt 속 animal들을 저장합니다.
        이때, 구분은 '\n'로 하면 됩니다.

*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, check_num;
    FILE *afp, *bfp, *cfp;
    char re_word[10][21] = { 0, };      // registed word
    char new_word[21];
    char *res;

    afp = fopen("a.txt", "rt");     // afp 파일 포인터에 a.txt를 읽기 모드로 개방

    if (afp == NULL)
    {
        printf("파일이 열리지 않습니다.\n");    // 안내 메시지 출력
        return 1;                         // 프로그램 종료, 비정상 종료인 경우는 return 1
    }

    for (i=0; i<10; i++)            // a.txt에서 동물 이름을 모아 re_word 배열에 등록
    {
        if ( re_word[i] == 0 ) break;
        fgets(re_word[i], sizeof(re_word[0]), afp);
    }

    bfp = fopen("b.txt", "rt");     // bfp 파일 포인터에 b.txt를 읽기 모드로 개방
    cfp = fopen("c.txt", "wt");     // cfp 파일 포인터에 c.txt를 쓰기 모드로 개방

    while (1)
    {
        check_num = 0;
        res = fgets(new_word, sizeof(new_word), bfp);
        if ( res == NULL ) break;
        for (i=0; i<10; i++)
        {
            if ( new_word == re_word[i] )   // 요기가 제대로 안 돌아감... 이유는 모르겟음
            {
                printf("%s%s\n", re_word[i], new_word);
                check_num++;
            }
        }
        if (check_num == 0 )
        {
            fputs(new_word, cfp);
        }
    }
    
    fclose(afp);
    fclose(bfp);
    fclose(cfp);
}

/* 실행 결과


*/