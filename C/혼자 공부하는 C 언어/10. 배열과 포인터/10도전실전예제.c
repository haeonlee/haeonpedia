// 10. 배열과 포인터
/*  도전 실전 예제. 로또 번호 생성 프로그램
    1~45 중 6개의 서로 다른 수를 배열에 입력하고 출력합니다.
    입력한 수가 이미 저장된 수와 같으면 에러 메시지를 출력하고 다시 입력합니다.
    다음 함수의 선언과 정의를 참고하고 빈 부분을 채워 완성합니다. */

#include <stdio.h>

void input_nums(int *lotto_nums);   // 배열에 로또 번호를 입력하는 함수
void print_nums(int *lotto_nums);   // 배열에 저장된 값을 출력하는 함수

int main(void)
{
    int lotto_nums[6];

    input_nums(lotto_nums);
    print_nums(lotto_nums);
    return 0;
}

void input_nums(int *lotto_nums)
{
    int count, i, j;

    for (j=0; j < count; j++)
    {
        
        if (lotto_nums[j] == 

    }

    while (count != 6)
    {
        if lotto_nums[i]
    }
    if lotto_nums[i] 
        printf("번호 입력 : ");
        scanf("%d", lotto_nums[i])

    

        
}

void print_nums(int *lotto_nums)
{
    for (i=0; i<6; i++)
    {
        printf("로또 번호 : ");
        printf("%d  ", lotto_nums[i]);
    }
}