#include <stdio.h>
int main(void)
{
     int num;
     int i, j;
     int pn;
     int count = 0;

     printf("2이상의 정수를 입력하세요 : ");
     scanf("%d", &num);

     for(i = 2; i <= num; i++)
     {
           pn = 1;      // 이게 내가 안 한 거
           for(j = 2; j < i; j++)
           {
                if((i % j) == 0)
                {
                      pn = 0; // 이게 내가 안 한 거
                      break;
                }
           }
           if(pn == 1)  // 이렇게 빼 줘야 하고
           {
                printf("%5d", i);
                count++;
                if((count % 5) == 0)
                {
                      printf("\n");
                }
           }
     }
     return 0;
}