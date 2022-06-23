/*
    CODE REVIEW

    - for문 안에서 사용하는 i를 외부에서도 바꿀 수 있다(e.g. 중복인 경우는 i--)
      즉, for(i=0; i<6; i++)라고 해서 꼭 6번만 반복하고 끝나는 건 아니라는 소리
    - 일단 num에 입력을 받고, 그걸 배열 안에 넣어도 충분히 OK
    - if(!dup) 같은 형식으로 사용해도 OK

*/

#include <stdio.h>
 
void input_nums(int *lotto_nums);  // 배열에 로또 번호를 입력하는 함수
void print_nums(int *lotto_nums);  // 배열에 저장된 값을 출력하는 함수
 
int main(void)
{
     int lotto_nums[6];            // 로또 번호를 저장할 배열
 
     input_nums(lotto_nums);       // 입력함수 호출
     print_nums(lotto_nums);       // 출력함수 호출
 
     return 0;
}
 
void input_nums(int *lotto_nums)
{
     int num;
     int i, j;
     int dup;
 
     for(i = 0; i < 6; i++)
     {
           printf("번호 입력 : ");
           scanf("%d", &num);
           dup = 0;
           for(j = 0; j < i; j++)
           {
                if(num == lotto_nums[j])
                {
                      dup = 1;
                      break;    // break를 사용하여 for문에서 빠져 나옴
                }
           }
           if(!dup)
           {
                lotto_nums[i] = num;
           }
           else
           {
                printf("같은 번호가 있습니다!\n");
                i--;
           }
     }
}
 
void print_nums(int *lotto_nums)
{
     int i;
 
     printf("로또 번호 : ");
     for(i = 0; i < 6; i++)
     {
           printf("%d  ", lotto_nums[i]);
     }
}