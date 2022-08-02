// 05-2. if문의 활용과 switch ~ case문
/* 3. 다음 표에 따라 옷의 사이즈가 결정될 떄, 나이가 25이고 가슴둘레가 95인 사람의 사이즈를 출력하는 프로그램을
      if문을 사용해 작성하세요. (p.151) */

// MEMO. 내가 코드는 잘 짰는데 중괄호를 너무 넣어서 보기가 좀 힘듦.
// if (chest < 85) size = 'S'; 같은 식으로 깔끔하게 붙여서 써도 OK.

#include <stdio.h>

int main(void)
{
    int age = 25, chest = 95;
    char size;

    if (age < 20)
    {
        if (chest<85)
        {
            size = 'S';
        }
        else if (chest<95)
        {
            size = 'M';
        }
        else
        {
            size = 'L';
        }
    }
    else
    {
        if (chest<90)
        {
            size = 'S';
        }
        else if (chest<100)
        {
            size = 'M';
        }
        else
        {
            size = 'L';
        }
    }

    printf("사이즈는 %c입니다.\n", size);   // 결정된 사이즈 출력
    return 0;
}

/* 실행 결과

사이즈는 M입니다.

*/