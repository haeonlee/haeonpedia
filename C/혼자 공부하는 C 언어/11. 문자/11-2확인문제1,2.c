// 11-2. 버퍼를 사용하는 입력 함수

/*
    1. 키보드로 데이터를 입력할 때 버퍼에 남아 있는 데이터를 모두 지우는 방법으로 적당한 것은?

    (1) fflush(stdout);             // 출력 버퍼의 내용을 지울 때 사용
    (2) while (getchar() != '\n');  // 버퍼에서 하나의 문자만 가져와서 반환
    (3) fgetc(stdin);       
    (4) scanf("%c", &ch);           // 버퍼에서 하나의 문자만 가져와 ch에 저장

    실제 답
    (2) while (getchar() != '\n');

    내 답안
    (3) fgetc(stdin);
    버퍼에 입력된 모든 데이터를 입력해서 없애야 하므로, 인수로 stdin을 사용한 (3)이 정답이다
*/

/*
    2. 키보드로부터 하나의 문자를 입력받는 방법 중 적절하지 못한 것을 고르세요.

    char ch;
    int num;

    (1) num = getchar();    // getchar()는 반환형이 int이므로 맞음
    (2) ch = scanf("%c");   // 이렇게가 아니고 scanf("%c", &ch);라고 써야 함
    (3) ch = fgetc(stdin);  // fgetc 함수는 int형 변수에 입력해야 됨, 아스키 코드 값을 반환해서
                            // 근데 char에 넣어도 어차피 숫자라 괜찮을 것 같기도 하고?
    (4) scanf("%c"m &ch);   // 맞음
    (5) getchar(&ch);       // getchar는 매개 변수가 필요 없어요
    (6) scanf("%c", &num);  // %c 값을 받아서 int형에 저장한다? 괜찮음, 어차피 다 똑같이 숫자다

    정답
    (2) ch = scanf("%c");   // scanf 함수의 반환 값은 입력에 성공한 데이터의 개수
    (5) getchar(&ch);       // getchar 함수는 인수가 없음, getchar()와 같이 사용
    (6) scanf("%c", &num);  // 문자를 입력할 땐 char형 변수 사용

    내 답안
    정답: (2), (5)
*/

/*
    

    #include <stdio.h>
    int main(void)
    {
        int ch;
        int cnt = 0;
        ch = getchar();

        while (ch != EOF)
        {
            if (ch >= 'a' && ch <= 'z') cnt++;
            ch = getchar();
        }

        printf("소문자의 개수 : %d\n", cnt);

        return 0;
    }

*/