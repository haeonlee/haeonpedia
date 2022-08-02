// 8-7. 널 문자가 없는 문자열

/* 

널 문자가 없는 문자열
    문자열을 출력한 다음, 널 문자가 없으니까 쓰레기 값을 넣음
    심지어는 메모리 영역을 넘어서 쓰레기 값을 넣기도 함

*/

#include <stdio.h>

int main(void)
{
    char str[5];

    str[0] = 'O';
    str[1] = 'K';
    printf("%s\n", str);

    return 0;
}

/* 실행 결과

OK �

*/