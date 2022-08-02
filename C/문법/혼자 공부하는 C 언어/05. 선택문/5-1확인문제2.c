// 5-1. if문
/* 2. 다음 조건에 맞도록 if문의 빈칸을 채워 보세요.

- 가슴 둘레가 90보다 작거나 같으면 S 선택
- 가슴 둘레가 90보다 크고 100보다 작거나 같으면 M 선택
- 가슴둘레가 100보다 크면 L 선택

*/

#include <stdio.h>

int main(void)
{
    int chest = 95; // 가슴둘레 크기를 저장할 변수
    char size;  // 옷의 사이즈를 결정해서 저장할 변수
    if ( chest <= 90 )
    {
        size = 'S';
    }
    else if ( chest <= 100)
    {
        size = 'M';
    }
    else
    {
        size = 'L';
    }

    return 0;
}