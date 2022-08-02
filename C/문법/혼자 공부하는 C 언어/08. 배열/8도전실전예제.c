// 08. 배열
// 도전 실전 예제. 대소문자 변환 프로그램
/* 키보드로부터 문장을 입력받은 후에 대문자를 찾아 소문자로 바꾸는 프로그램을 작성하세요.
   바뀐 문장과 바뀐 문자의 수도 함께 출력합니다. */

// MEMO: 답 안 보고 바로 풀어서 너무 기분이 좋았다. 혹시 나 코딩 천재? 

#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;          // 반복문 사용할 때 사용할 인수
    int count = 0;  // 바뀐 문자의 수 계산
    int str_length; // 문자열 길이 계산

    char input_str[80];
    int num_str[80];
    char output_str[80];

    printf("문장 입력 : ");
    gets(input_str);

    str_length = strlen(input_str);

    for (i=0; i<str_length; i++)
    {
        if ((((int)input_str[i]) >= 65) && (((int)input_str[i]) <= 90))
        {
            num_str[i] = ((int)input_str[i]) + 32;
            output_str[i] = (char)num_str[i];
            count++;
        }
        else
        {
            num_str[i] = (int)input_str[i];
            output_str[i] = (char)num_str[i];
        }
            
    }

    printf("바뀐 문장 : ");
    puts(output_str);
    printf("바뀐 문자 수 : %d", count);

    return 0;
}

/* 실행 결과

문장 입력 : DON'T Worry, Be Happy~
바뀐 문장 : don't worry, be happy~
바뀐 문자 수 : 7

*/

/* 프로그래밍 노트

보자마자 '아스키 코드'를 활용하면 좋을 것 같다는 생각이 들었다.

오류1. 문자열의 길이가 제대로 출력되지 않았다.
str_length = ( sizeof(input_str) / sizeof(input_str[0]));
로 짰는데, 입력한 문자열의 길이가 안 나오고 계속 미리 지정한 80만 나왔다.
알고 봤더니, 널 문자 나올 때까지 반복문 사용해서 count를 해야 알 수 있더라.
그래서 그냥 strlen 함수 쓰기로 함.


*/