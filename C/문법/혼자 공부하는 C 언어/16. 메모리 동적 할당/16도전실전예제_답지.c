#include <stdio.h>
#include <stdlib.h>

int main(void)
{
     int num;
     int *ap;
     int i, j, cnt = 0;

     printf("> 양수 입력 : ");
     scanf("%d", &num);
     ap = (int *)malloc((num - 1) * sizeof(int));
     // 답지는 2차원 배열이 아니고, 1차원 배열로 하심

     if(ap == NULL)     // NULL로 예외 처리도 하시고(이걸 까먹었네!)
     {
           printf("메모리 부족...\n");
           exit(1);
     }

     for(i = 0; i < (num - 1); i++)
     {
           ap[i] = i + 2;
     }
     i = 0;

     while(1)
     {
           while((ap[i] == 0) && (i < (num - 2)))
           {
                i++;
           }

           if (i == (num - 2)) break;

           for(j = i + 1; j < (num - 1); j++)
           {
                if((ap[j] % ap[i]) == 0)
                {
                      ap[j] = 0;
                }
           }
           i++;
     }

     for(i = 0; i < (num - 1); i++)
     {
           if(ap[i] != 0)
           {
                printf("%5d", ap[i]);
           }
           else
           {
                printf("%5c", 'X'); // 배열 자체의 값 말고, 출력할 때만 따로 이렇게 하심
           }

           if((i + 1) % 5 == 0)
           {
                printf("\n");
           }
     }

     free(ap);

     return 0;
}