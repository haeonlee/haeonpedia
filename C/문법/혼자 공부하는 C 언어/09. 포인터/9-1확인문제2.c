// 09-1. 포인터의 기본 개념
/* 2. 다음과 같이 변수가 초기화되고 메모리에 할당되었다고 가정하고,
      주소 연산자와 간접 참조 연산자를 사용한 수식의 결괏값을 적어보세요. (p.246) */

/* 답안

*&ch: 'A'
*&in: 10
*&db: 3.4

*&ch는 &ch의 연산 결과인 주소 100에 다시 간접 참조 연산을 수행하여,
주소 위치의 변수 ch의 값이 됩니다.
보통 & 연산으로 구한 주소는 포인터에 저장하여 쓰지만
주소 값을 바로 * 연산에 사용하는 것도 가능합니다.

*/

/*

&ch: 100
&in: 101
&db: 105
*&ch: 
*&in: 
*&db: 

*/

