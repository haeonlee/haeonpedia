// 18-7. a+ 모드로 파일의 내용을 확인하며 출력

/*

    1. + 개방 모드

        파일 개방 모드는 기본적으로 읽고(r), 쓰고(w), 붙이는(a) 세 가지 모드가 있으나,
        +를 사용하면 읽고 쓰는 작업을 함께 할 수 있습니다.

        개방 모드   파일이 있을 때
        r+      텍스트 파일에 읽고 쓰기 위해 개방
        w+      텍스트 파일의 내용을 지우고 읽거나 쓰기 위해 개방
        a+      텍스트 파일을 읽거나 파일 끝에 추가하기 위해 개방
        rb+     바이너리 파일을 읽고 쓰기 위해 개방
        wb+     바이너리 파일의 내용을 지우고 읽거나 쓰기 위해 개방
        ab+     바이너리 파일을 읽거나 파일의 끝에 추가하기 위해 개방

    
    2. fseek 함수

        파일의 입력과 출력을 서로 전환할 때마다 fseek 함수를 호출해야 합니다.
        fprintf 함수는 스트림 파일의 버퍼에 데이터를 출력해놓는데,
        이때 버퍼에 데이터가 있는 상태에서 바로 하드디스크로부터 데이터를 입력하게 되면
        입출력 순서가 꼬입니다.

        따라서 버퍼의 데이터를 하드디스크로 옮기고 버퍼를 읽기 위한 공간으로 설정한 후에
        하드디스크의 데이터를 처음부터 다시 읽도록 해야 합니다.

        fseek 함수 원형
            int fseek(FILE * stream, long offset, int whence);
            
            (1) FILE * stream: stream 파일의 버퍼를
            (2) long offset: offset만큼 위치 지시자를 옮깁니다
            (3) int whence: whence를 기준으로 하여,

                whence에 사용할 수 있는 값과 의미
                
                값  매크로명        기준 위치           오프셋값
                0   SEEK_SET    파일의 처음         양수만 가능
                1   SEEK_CUR    파일의 현재 위치     양수와 음수 모두 가능
                2   SEEK_END    파일의 끝          음수만 가능

            예를 들어 fseek(fp, -5, SEEK_END); 는
            파일 끝에서 앞으로 다섯 문자 정도로 위치 지시자를 옮깁니다.
            매크로명은 값 대신에 사용할 수 있는 이름인데, 전처리 과정에서 약속된 정수로 바뀝니다.

    
    3. rewind 함수

        rewind 함수는 위치 지시자를 맨 처음으로 설정합니다.

        rewind(fp);
        는 

        fseek(fp, 0, SEEK_SET);
        와 같은 의미입니다.

    4. feof 함수

        feof 함수는 스트림 파일의 데이터를 모두 읽었는지 확인할 때 유용합니다.
        파일의 끝이면 0이 아닌 값을 반환하고, 끝이 아니면 0을 반환합니다.
        feof 함수는 입력 함수가 데이터 입력에 실패한 이후에 그 결과를 알 수 있으므로
        입력 함수 다음에 사용합니다.
    
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    char str[20];

    fp = fopen("a.txt", "a+");      // 읽기 가능한 추가 모드로 개방
    if (fp == NULL)
    {
        printf("파일을 만들지 못했습니다.");
        return 1;
    }

    while (1)
    {
        printf("과일 이름 : ");
        scanf("%s", str);
        if (strcmp(str, "end") == 0)
        {
            break;
        }
        else if (strcmp(str, "list") == 0)  // list를 입력하면 파일의 내용 확인
        {
            fseek(fp, 0, SEEK_SET);         // 버퍼의 위치 지시자를 맨 처음으로 이동
            while (1)
            {
                fgets(str, sizeof(str), fp);    // 과일의 이름을 읽는다
                if (feof(fp))               // 파일의 내용을 모두 읽으면 종료
                {
                    break;
                }
                printf("%s", str);          // 읽은 과일 이름을 화면 출력
            }
        }
        else
        {
            fprintf(fp, "%s\n", str);       // 입력한 과일 이름을 파일에  출력
        }
    }
    fclose(fp);

    return 0;
}

/* 실행 결과

(처음 실행할 때 실행결과)
과일 이름 : apple
과일 이름 : banana
과일 이름 : list
apple
banana
과일 이름 : end

(두 번째 실행할 때 실행결과)
과일 이름 : strawberry
과일 이름 : list
apple
banana
strawberry
과일 이름 : end

*/