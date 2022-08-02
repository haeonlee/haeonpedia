// 11. 문자
/*
    도전 실전 예제. 길이가 가장 긴 단어 찾기

    키보드로 입력한 단어 중에서 길이가 가장 긴 단어의 길이를 출력하세요.
    한 줄에 하나의 단어만 입력하며 ctrl+z를 누를 때까지 입력한 단어 중에서 길이가 가장 긴 단어의 길이를 출력합니다.
    배열은 사용하지 않고 작성하세요.
*/

/*
    프로그래밍 노트

    (1) 문자 입력을 반복적으로 받기(왜냐면 깔끔하게 없애야 버퍼에 안 남음)
    (2) count++;
    (3) 저장된 max 숫자랑 count랑 비교해서 더 큰 놈을 max에 저장

*/

#include <stdio.h>

int main(void)
{
    int max = 0;    // 가장 큰 수를 저장할 변수, 쓰레기값 방지를 위해 처음은 0으로 저장
    int i;      // 반복문을 수행할 i
    int count = 0;  // count는 0에서 시작
    char keyword;

    keyword = getchar();

    while( keyword != EOF )
    {
        keyword = getchar();
        count++;

        if (keyword == '\n')
        {
            keyword = getchar();    // 개행문자까지 깔끔하게 정리
            if (count >= max) max = count;
            count = 0;
        }
    }

    printf("가장 긴 단어의 길이 : %d", max);
}

