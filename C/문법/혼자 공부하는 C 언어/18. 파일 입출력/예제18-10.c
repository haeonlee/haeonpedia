// 18-10. 버퍼를 공유하므로 발생하는 문제

/*

    스트림 파일의 버퍼 공유 문제

        스트림 파일을 사용하는 입출력 함수들이 버퍼를 공유하면 예상과 다른 결과가 나올 수 있습니다.

        가령, 아래 예제가 바로 그런 경우입니다.

        왜 저런 문제가 발생했을까요?
        fscanf 함수와 fgets 함수가 개행 문자를 처리하는 방식이 다르기 때문입니다.
        
        (1) fscanf 함수가 나이를 입력한 후에 버퍼에 남겨놓은 개행 문자를,
        (2) 다음에 호출되는 fgets 함수가 이어서 입력합니다.
            이때, fgets 함수는 개행 문자가 나오면 입력을 종료하므로
            이름을 추가 입력하지 못한 채 프로그램이 끝납니다.

        해결 방법1. 화이트 스페이스(개행 문자, 공백, 탭)을 데이터로 입력하지 않는 함수를 쓰세요

            fscanf(fp, "%s", name);
            그러나 위처럼 코딩을 하면 fscanf 함수가 공백으로 입력 데이터를 구분하기 때문에,
            'Hong GD'에서 'Hong'만 입력하는 문제가 생긴다.
            따라서, fgetc 함수를 개행문자가 등장하는 타이밍에 끼워넣는 것도 좋은 방법이다.
            그러나 매번 이렇게 하긴, 쉽지 않다.


        해결 방법2. my_fflush 함수를 만들어 해결합니다

            void my_fflush

            while (fgetc(fp) != '\n') {}    // fgetc 함수의 반환 값이 개행 문자가 아닌 동안 반복

            void my 

        해결 방법3. 

*/

/*

    a.txt

    17
    Hong GD

*/

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int age;
    char name[20];

    fp = fopen("a.txt", "r");

    fscanf(fp, "%d", &age);
    fgets(name, sizeof(name), fp);

    printf("나이 : %d, 이름 : %s", age, name);
    fclose(fp);

    return 0;
}

/* 실행 결과

나이 : 17, 이름 : 

*/