/*
    프로그래밍 노트
    - 문제를 풀면서, 포인터로 대소 관계를 미리 확정한 다음에 방향만 요리조리 바꿔야겠다고 생각했다.
    - 아까는 포인터의 방향을 if문 중간에 설정했다면, 지금은 처음부터 초기화를 하기로 했다.
    - 내가 3개의 대소 관계를 비교해서 블록을 순서대로 넣는 효율적인 알고리즘을 제대로 파악 못 하고 있다는 생각이 들었다.
*/


#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80];
    char str2[80];
    char str3[80];
    char *max = &str1;  // 틀림: str1 자체로도 주소이므로 char *max = str1; 이라고 깔끔하게 써야 함
    char *mid = &str2;  // 틀림: 위와 마찬가지
    char *min = &str3;  // 틀림: 위와 마찬가지

    printf("세 단어 입력 : ");
    scanf("%s%s%s", str1, str2, str3);
    printf("%s, %s, %s", max, mid, min);    // 이건 맞음

    if ( strcmp(*max, *mid) == 0 )  // 틀림: *을 빼야 해, 왜냐면 max 자체로도 주소니까
    {
        *max = *mid;    // 이건 이렇게 하면 애초에 값 자체도 요상해지겠지? 이미 2를 넣었으면
        *mid = *max;    // 여기서 똑같이 아까 넣은 2가 들어갈 테니까, 교체가 아니고 중복 값이 생기는 셈이야
    }

    if ( strcmp(*max, *min) == 1 )
    {
        *max = *min;
        *mid = *max;
        *min = *mid;
    }

    if ( strcmp(*mid, *min) == 1 )
    {
        *mid = *min;
        *min = *mid;
    }

    printf("%s, %s, %s", *max, *mid, *min);
    
    return 0;
}