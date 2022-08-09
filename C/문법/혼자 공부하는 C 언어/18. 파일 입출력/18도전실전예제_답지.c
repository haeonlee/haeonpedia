#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void my_assert(FILE *fp);
int check_registration(char(*reg_word)[21], char *word, int cnt);
 
int main(void)
{
     FILE *afp, *bfp, *cfp;
     char reg_word[10][21];
     char word[21];
     int i, cnt;
 
     afp = fopen("a.txt", "r");
     my_assert(afp);    // 파일 개방 안 된 경우 check를 함수로 간단하게 함
     bfp = fopen("b.txt", "r");
     my_assert(bfp);
     cfp = fopen("c.txt", "w");
     my_assert(cfp);
 
     for(i = 0; i < 10; i++)
     {
           fscanf(afp, "%s", reg_word[i]);
           if(feof(afp))    // feof는 파일의 끝인지 보는 함수, 끝이면 0이 아닌 값이 나옴
           {
                break;
           }
     }
     cnt = i;
 
     while(fscanf(bfp, "%s", word) != EOF)
     {
           if(!check_registration(reg_word, word, cnt)) // !(변수) -> 변수를 반대로 뒤집음
           {
                fprintf(cfp, "%s\n", word);
           }
     }
 
     fclose(afp);
     fclose(bfp);
     fclose(cfp);
 
     return 0;
}
 
int check_registration(char(*reg_word)[21], char *word, int cnt)
{
     int i;
 
     for(i = 0; i < cnt; i++)
     {
           if(strcmp(reg_word[i], word) == 0)
           {
                return 1;
           }
     }
 
     return 0;
}
 
void my_assert(FILE *fp)
{
     if(fp == NULL)
     {
           printf("@ 파일을 개방하지 못했습니다!\n");
           exit(1);
     }
}