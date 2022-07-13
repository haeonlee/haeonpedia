// 14-3. 여러 개의 동물 이름을 입출력하는 프로그램

#include <stdio.h>

int main(void)
{
    char animal[5][20];     // 5개의 동물의 이름을 저장하는 2차원 char 배열 선언
    int i;
    int count;

    count = sizeof(animal) / sizeof(animal[0]);     // 행의 수 계산
    // 동물의 이름의 수에 변화가 생겨도 수정할 필요가 없음
                                                

    for (i = 0; i < count; i++)
    {
        scanf("%s", animal[i]);     // 행의 수만큼 반복
    }

    for (i = 0; i < count; i++)
    {
        printf("%s ", animal[i]);
    }

    return 0;
}

/* 실행 결과

dog
tiger
rabbit
horse
cat 
dog tiger rabbit horse cat 

*/