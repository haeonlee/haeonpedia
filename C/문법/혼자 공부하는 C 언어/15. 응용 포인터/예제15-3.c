// 15-3. 포인터 배열의 값을 출력하는 함수

/*

    이중 포인터 활용 2. 포인터 배열을 매개변수로 받는 함수

    이중 포인터는 포인터 배열을 매개변수로 받는 함수에도 사용합니다.
    배열명은 첫 번째 배열 요소의 주소이므로 int형 배열의 이름은 int형 변수의 주소입니다.
    마찬가지로 int형 포인터 배열의 이름은 int형 포인터의 주소가 됩니다.
    따라서 포인터 배열의 배열명은 이중 포인터에 저장합니다.

*/

#include <stdio.h>

void print_str(char **pps, int cnt);

int main(void)
{
    char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrel"};   // 초기화
    int count;  // 배열 요소의 수를 저장할 변수

    count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);   // 배열 요소의 수 계산
    print_str(ptr_ary, count);  // 배열명과 배열 요소 수를 주고 호출
    
    /*
    이때 ptr_ary는 포인터의 주소이므로,
    배열명 ptr_ary를 인수로 받는 함수의 매개변수는 이중 포인터를 선언해야 합니다.
    포인터가 배열명을 저장하면 배열명처럼 쓸 수 있으므로 함수 안에서는 매개변수를 배열명처럼 사용하여 문자열을 출력합니다.
    */

    return 0;
}

void print_str(char **pps, int cnt)     // 매개변수로 이중 포인터 사용
{
    int i;

    for (i = 0; i < cnt; i++)   // 배열 요소의 수만큼 반복
    {
        printf("%s\n", pps[i]);     // 이중 포인터를 배열명처럼 사용
    }
}