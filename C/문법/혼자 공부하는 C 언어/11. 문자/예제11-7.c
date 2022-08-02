// 11-7. 버퍼의 내용을 지워야 하는 경우

/*
    scanf와 getchar 함수는 같은 버퍼를 사용하며 입력 데이터를 공유
    따라서, 앞서 실행한 입력 함수가 버터에 남겨둔 데이터를 다음 함수가 갖고 갈 수 있음

    입력 버퍼의 내용을 지우는 법
        버퍼에 남아 있는 문자들을 모두 입력해서 사용하지 않고 버리면 됨

    여기서 잠깐. stdin과 stdout

    문자 입출력 함수 fgetc와 fputc: 별도 인수를 주는 것 외엔 getchar, putchar와 같음

        int ch;
        ch = fgetc(stdin);
        int형 변수에 입력, 입력 문자의 아스키 코드 값 반환

        fputc(ch, stdout);

        추가 인수: fgetc는 stdin을 주고 fputc는 stdout를 줍니다.
        stdin(standard input, 표준 입력장치인 키보드와 입력된 버퍼 이름)
        stdout(출력 버퍼 이름)

        +) 18장 파일 입출력에서 더 자세히 다룸
    
*/

#include <stdio.h>

int main(void)
{
    int num, grade;

    printf("학번 입력 : ");
    scanf("%d", &num);  // 학번 입력, 숫자는 %d에 저장, 개행 문자(\n)는 버퍼에 남음
    getchar();          // 버퍼에 남아 있는 개행 문자 제거
                        // 이게 없다면, 다음 getchar 함수에 개행 문자(\n)가 입력되면서 오류 발생
    printf("학점 입력 : ");
    grade = getchar();  // 학점 입력
    printf("학번 : %d, 학점 %c", num, grade);

    return 0;
}

/* 실행 결과

학번 입력 : 2020  
학점 입력 : A
학번 : 2020, 학점 A

if. getchar()로 개행 문자를 안 없애줬다면?
학번 입력 : 2020
학점 입력 : 학번 : 2020, 학점 

*/