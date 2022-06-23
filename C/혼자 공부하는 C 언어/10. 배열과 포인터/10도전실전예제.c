// 10. 배열과 포인터
/*  도전 실전 예제. 로또 번호 생성 프로그램
    1~45 중 6개의 서로 다른 수를 배열에 입력하고 출력합니다.
    입력한 수가 이미 저장된 수와 같으면 에러 메시지를 출력하고 다시 입력합니다.
    다음 함수의 선언과 정의를 참고하고 빈 부분을 채워 완성합니다. */

/* 
    CODE REVIEW
    풀긴 풀었는데, 레전드로 찜찜하게 풀었음ㅋㅋ
    안 됐을 때 코드를 다 기록해 둘 걸 그랬다
*/

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
    int i, j;
    int count = 0;

    while (count != 6)
    {
        printf("번호 입력 : ");
        scanf("%d", &lotto_nums[count]);

        for (j=0; j<count; j++)
        {
            if (lotto_nums[j] == lotto_nums[count])
            {
                printf("같은 번호가 있습니다!\n");
                count -= 1;
            }
        }

        count++;
    }   
}

void print_nums(int *lotto_nums)
{
    int i;
    printf("로또 번호 : ");

    for (i=0; i<6; i++)
    {
        printf("%d  ", lotto_nums[i]);
    }
}

/*  프로그래밍 노트

    아이디어 count 변수를 하나 만들어서 6이 될 때까지 반복
    (if count == 6 return 0;)

    - n일 땐, n까지의 배열 요소 중 똑같은 수 있는지 찾기
    (for문 하나로 같이 쓰면 될 것 같음)
    - 있으면, 다시 입력
    - 없으면, 그냥 입력

*/

/* 실행 결과

번호 입력 : 3
번호 입력 : 7
번호 입력 : 7
같은 번호가 있습니다!
번호 입력 : 15
번호 입력 : 22
번호 입력 : 35
번호 입력 : 40
로또 번호 : 3  7  15  22  35  40  

*/