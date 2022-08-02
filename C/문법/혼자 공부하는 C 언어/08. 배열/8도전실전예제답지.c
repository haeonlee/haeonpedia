/* CODE REVIEW

코드는 나보다 훨씬 깔끔했지만,
논리 자체는 내 생각이랑 비슷했다.

어떻게 하면 더 코드를 깔끔하게 짤 수 있는지 생각하며 문제를 풀어야겠다!

point. char형은 어차피 숫자이자 문자이기에, 자료 자체를 변환할 것이 아니고
       출력 형태만 조심해서 쓴다는 걸 명심하자.

*/


#include <stdio.h>

int main(void)
{
     char str[80];
     int cnt = 0;
     int i;

     printf("문장 입력 : ");
     gets(str);

     for(i=0; str[i] != '\0'; i++)  // point1. 반복문에 != 를 써도 되는지 이제 알았다
     {
           if((str[i] >= 'A') && (str[i] <= 'Z'))   // point2. char끼리 대소 관계가 비교 가능
                                                    // 이때, 숫자로 서로 비교함
           {
                str[i] += ('a'-'A');    // 'a' - 'A'가 32다.
                cnt++;
           }
     }

     printf("바뀐 문장 : ");
     puts(str);
     printf("바뀐 문자 수 : %d\n", cnt);

     return 0;
}