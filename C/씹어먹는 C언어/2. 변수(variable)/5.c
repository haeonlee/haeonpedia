/*
DATE: 2022. 03. 18. FRI
PAGE: 37p
주제: 변수 작명하기
포인트: 변수 이름을 정하기 위한 규칙 익히기
*/

#include <stdio.h>
int main() {
    int a, A; // 대소문자 구분 - a와 A는 각기 다른 변수

    /* int 1hi; 
    (오류) 숫자가 앞에 위치할 수 없음 */

    int hi123, h123i, h123432;

    /* int 한글이 좋아;
    (오류) 변수는 오직 알파벳, 숫자, 그리고 _(underscore)로만 이루어져야 함 +띄어쓰기도 불가능 */

    int space_bar;

    /* int enum, long, double, int;
    (오류) 위에서 나열한 이름은 '예약어'로 이미 C에서 쓰이고 있음 */

    return 0;
}