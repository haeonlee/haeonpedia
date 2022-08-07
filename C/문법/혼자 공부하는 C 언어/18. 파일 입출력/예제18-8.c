// 18-8. 여러 줄의 문장을 입력하여 한 줄로 출력

/*

    fgets 함수: 데이터를 한 줄씩 입력할 때 사용

        읽을 데이터의 크기가 큰 경우 저장 공간의 크기까지만 입력할 수 있으므로,
        할당하지 않은 메모리를 침범할 가능성을 차단합니다.

        (1) fgets 함수 입력 방법
        fgets(str, sizeof(str), ifp);
        fgets(입력할 배열, 배열의 크기, 파일 포인터);

        문자열을 저장할 배열과 그 크기를 주고, 입력할 파일의 포인터를 줍니다.

        (2) fgets 함수가 입력을 마치면 입력한 배열의 주소를 다시 반환합니다.
        이를 활용하면 함수를 호출한 후에 바로 입력된 데이터를 사용할 수 있어 편리합니다.
        
        (3) fgets 함수는 파일에서 더 이상 읽을 데이터가 없으면 NULL을 반환합니다.
        fgets 함수를 호출할 때 파일의 끝을 검사하기 위해서는 NULL과 비교해야 합니다.
        EOF(-1)를 사용하지 않도록 주의합시다.


    fputs 함수: 문자열을 파일에 출력할 때 사용

        (1) fputs 함수는 파일 출력에 성공하면 시스템에 따라 0 또는 출력한 문자를 반환합니다.
        (2) fputs 함수는 파일 출력에 실패하면 EOF를 반환합니다.

        (3) fputs 함수 입력 방법 

            fputs(출력할문자열, 파일포인터);
            fputs(str, ofp);

            파일 포인터와 연결된 파일로 문자열을 출력하며,
            개행 문자를 출력하지 않으면 자동으로 줄을 바꾸지 않습니다.


    여기서 잠깐. 왜 fgets와 fputs를 사용해야 할까요?
        gets와 puts 대신에 fgets와 fputs를 사용하는 것이 좋습니다.
        gets 함수는 입력할 저장 공간의 크기를 인수로 줄 수 없으므로
        문자열을 입력할 때 할당하지 않은 메모리 공간을 침범할 가능성이 있습니다.
        또한 puts 함수는 항상 줄을 바꾸므로 문자열을 이어서 출력할 수 없습니다.

    
    여기서 잠깐. fgets와 fputs로 키보드와 모니터로 데이터 입출력하기
        fgets(str, sizeof(str), stdin);
        fputs(str, stdout);

*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *ifp, *ofp;            // 파일 포인터 선언
    char str[80];               // 입력한 문자열을 저장할 배열
    char *res;                  // fgets 함수의 반환값을 저장할 변수

    ifp = fopen("a.txt", "r");  // 입력 파일을 읽기 전용으로 개방
    if (ifp == NULL)
    {
        printf("입력 파일을 열지 못했습니다.\n");
        return 1;
    }

    ofp = fopen("b.txt", "w");
    if (ofp == NULL)
    {
        printf("출력 파일을 열지 못했습니다.\n");
        return 1;
    }

    while (1)
    {
        res = fgets(str, sizeof(str), ifp);
        if (res == NULL)
        {
            break;
        }
        str[strlen(str) - 1] = '\0';    // 개행 문자 제거
                                        // 마지막에 널 문자를 붙여 마무리합니다
        
        /* 개행 문자를 제거하는 경우, 입력 파일의 형식에 주의하세요.
        예를 들어 개행 문자 없이 순수한 문자만 입력된 줄이라면 위 같은 코드를 넣으면
        마지막 문자가 사라질 수 있습니다. */
        fputs(str, ofp);
        fputs(" ", ofp);
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}

/* 실행 결과

a.txt
monkey likes
banana

b.txt
monkey likes banana

*/