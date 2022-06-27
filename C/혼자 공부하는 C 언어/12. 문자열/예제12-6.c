// 12-6. 개행 문자로 인해 gets 함수가 입력을 못하는 경우

/*

    scanf 함수나 getchar 함수 같은 표준 입력 함수는 입력 버퍼를 공유
    따라서 같은 버퍼를 공유하는 gets나 fgets에서 개행 문자를 입력의 종료 조건을 사용하면 문제 발생 가능
    -> 앞서 입력한 함수가 버퍼에 개행 문자를 남겨 두면, 다음 함수가 개행 문자만 가져오고 입력을 끝냄

    버퍼에 남은 개행 문자를 지우는 방법: 문자 입력 함수 호출
        (1) getchar();      // 버퍼에서 하나의 문자를 읽어서 반환, 반환 문자는 버림
        (2) scanf("%*c");   // 버퍼에서 하나의 문자를 읽어서 반환, 변수는 필요 없음
        (3) fgetc(stdin);   // 버퍼에서 하나의 문자를 읽어서 반환, 반환 문자는 버림

*/

#include <stdio.h>

int main(void)
{
    int age;
    char name[20];

    printf("나이 입력 : ");
    scanf("%d", &age);
    // fgetc(stdin); 얘 입력하면 제대로 출력돼용
    printf("이름 입력 : ");
    gets(name);     // gets 함수로 이름 입력
    printf("나이 : %d, 이름 : %s\n", age, name);
}

/* 실행 결과

나이 입력 : 24
warning: this program uses gets(), which is unsafe.
이름 입력 : 나이 : 24, 이름 : 

24\n 에서 '24'는 scanf로 가고, gets엔 '\n'이 '\0'으로 바뀌어 입력된 셈

*/