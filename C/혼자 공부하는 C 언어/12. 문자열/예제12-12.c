// 12-12. strcmp, strncmp 함수를 사용한 문자열 비교

/*

    strcmp, strncmp 함수: 두 문자열의 사전 순서를 판단하여, 그 결과를 반환

        아스키 코드의 대소로 비교하므로, 대문자와 소문자가 섞여 있어서는 안 됩니다!

        strcmp(str1, str2);     // str1이 str2보다 사전에 먼저 나오면 -1 반환
                                // str1이 str2과 같은 문자열이면 0 반환
                                // str1이 str2보다 사전에 나중에 나오면 1 반환

        strncmp 함수: strcmp 함수와 거의 같지만, 비교할 문자 수를 세 번째 인수로 지정할 수 있음
        
            strncmp(str1, str2, 비교할 문자 수);
            즉, pear와 peach를 앞에서부터 3개의 문자만 비교하다면 결과로 0이 나오는 셈

        여기서 잠깐. strcmp 함수의 반환값이 항상 사전 순서를 의미하는 것은 아닙니다
            strcmp 함수가 아스키 코드 값을 비교하므로 대소문자가 섞인 경우는 반환값이 사전 순서와 다를 수 있음
            (대문자의 아스키 코드 값이 소문자보다 작기 때문)
            따라서, strcmp 함수의 반환값으로 사전 순서를 판단할 땐 반드시 대소문자를 일치시켜야 함

            숫자나 특수문자가 포함된 경우, 한글이 포함된 경우도 주의할 것
            특히 한글은 2바이트로 구현하여 어떤 아스키 코드 값보다 크다

*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80] = "pear";
    char str2[80] = "peach";

    printf("사전에 나중에 나오는 과일 이름 : ");

    if (strcmp(str1, str2) > 0)
        printf("%s\n", str1);
    else
        printf("%s\n", str2);
    
    return 0;

}