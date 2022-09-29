#include "H02_polyAdd.h"
extern int allocSize;	   // size of the allocated memory for each test
extern int allocSizeMax;  // max allocated mem size among those of all tests

void readPolyAB(int* pnA, polyPtr* pA, int* pnB, polyPtr* pB) {

	



	// 배열 A와 B의 입력을 나눠서 하도록 하겠습니다.

	// 1. 배열 A 데이터 처리: nA 입력, MALLOC, 다항식 읽기 등

	if (scanf("%d", pnA) == EOF)	// (1) nA에 A의 terms 값 입력
	{
		WRONG_INPUT;
	}

	// 2. MALLOC을 해서 pointer A에 동적 할당으로 메모리 부여
	// *pA는 pA가 가리키고 있는, pointer A의 값: 얘가 진짜 배열들을 가리키는 애들임

	if (*pnA <= 0)
	{
		WRONG_INPUT;
	}
	else
	{
		MALLOC(*pA, polyPtr, sizeof(poly)*(*pnA));
		for (int i=0; i<(*pnA); i++)
		{
			if (scanf("%d %d", &((*pA)[i].coef), &((*pA)[i].expon)) == EOF)
			{
				WRONG_INPUT;
			}
		}
	}

	if (scanf("%d", pnB) == EOF)	// (1) nA에 A의 terms 값 입력
	{
		WRONG_INPUT;
	}

	// 2. MALLOC을 해서 pointer A에 동적 할당으로 메모리 부여
	// *pA는 pA가 가리키고 있는, pointer A의 값: 얘가 진짜 배열들을 가리키는 애들임

	if (*pnB <= 0)
	{
		WRONG_INPUT;
	}
	else
	{
		MALLOC(*pB, polyPtr, sizeof(poly)*(*pnB));
		for (int i=0; i<(*pnA); i++)
		{
			if (scanf("%d %d", &((*pB)[i].coef), &((*pB)[i].expon)) == EOF)
			{
				WRONG_INPUT;
			}
		}
	}

	// A 입력, B 입력 나눠서 구동

	// A 입력

	// scanf() 함수를 이용해 nA와 nB를 입력 받을 것
	// 이때, 매개 변수가 pnA, pnB이므로(nA와 nB의 포인터) *을 이용해서 nA와 nB를 직접 바꾼다
		// if nA (또는 nB)가 0이라면 zero polynomial이므로, 각 항의 정보를 받을 필요가 없음
		// 아예 값 자체가 입력되지 않았다면 wrong_input 출력
	
	// nA 값을 이용해서 MALLOC으로 메모리를 할당한다
	
	// 각 항 정보를 입력 받음: A, B를 바꿈
	// 메모리 할당: *pA = MALLOC() 사용해서 pA가 가리키고 있는, pointer A의 값을 바꾸어야 합니다
		// A, B 저장을 위한 메모리는 MALLOC 매크로를 각각 한번씩만 사용하여 할당받아야 한다.
		// 아예 안 들어왔거나 적게 들어왔다면, wrong_input() 출력
	// 그리고 이제 저장 조져야지;;ㅎㅎ
	// *pa[0].coef = 어쩌고 이런 식으로 저장하는 게 맞을 것 같음
		
	// 언제 자료가 부족하니까 wrong_input()을 출력할 것인가 고민할 것

	/* 
	이런 느낌으로 아예 필요한 만큼 루프를 돌리고, 데이터 부족하면 WRONG_INPUT 나오게 하면 됨

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < (*C); j++)
		{
			if (scanf("%d", &temp) != EOF)
			{
				L[i][j] = temp;			 // 3. 파일에서 배열 값을 읽는다.
			}
			else
			{
				WRONG_INPUT;			// 4. 데이터가 부족하면 WRONG_INPUT을 호출하여 실행을 중지한다
			}
			
		}
	}
	*/



	// pnA, pnB : 다항식 A와 B의 nonzero term의 개수를 저장하는
	//            nA, nB를 가리키는 pointers
	// pA : 다항식 A를 저장하는 배열을 가리키는 pointer A를 가리키는 pointer
	//      즉, poly pointer의 pointer이다.
	// pB : 다항식 B를 저장하는 배열을 가리키는 pointer B를 가리키는 pointer
	// 참고: 이 함수에서 배열과 배열의 크기가 결정되므로 이에 대한 pointer를
	//      parameter로 입력받는다.

	// 기능 : 입력에서 다항식 A와 B에 대한 자료를 읽어 저장한다.
	//        HW pdf의 입력 파일 형식을 참조하자
	// 주의 :  
	//  -- 각 다항식은 zero polynomial 일 수 있다.
	//     입력 자료가 부족할 경우 WRONG INPUT 메크로를 실행한다.
	//  -- A, B 저장을 위한 메모리는 MALLOC 매크로를 각각 한번씩만 사용하여
	//     할당받아야 한다.
	//
	*pnA = *pnB = 0; // 이 줄은 삭제해도 무방하다(빌드 오류 회피용)

	// ***이 함수를 완성하세요***

	return;
}

int allocPolyD(int nA, polyPtr A, int nB, polyPtr B, polyPtr* pD) {

	// 1. 다항식의 덧셈 과정을 simulation: 즉, 결과 저장 없이 덧셈 과정을 수행

	int temp;	// simulation 하기 위한 temp 값
	int nD = 0;

	/*
	while ( sA < nA && sB < nB )
	{
		switch(COMPARE(A[sA].expon, B[sB].expon)) {
            case -1: // a의 지수 < b의 지수
				nD++;	// 지수가 다르다면 지수끼리 계산할 것도 없이 nD는 하나 더 필요
				sB++;
                break;

            case 0: // a의 지수 = b의 지수
				temp = A[sA].coef + B[sB].coef
                if (temp) // 얘네가 더 했을 때 0이 아니어야 nD가 하나 더 필요
					nD++;
					sA++;
					sB++;
                    break;
                
            case 1: // a의 지수 > b의 지수
				sA++;
                nD++;
                break;
        }

	while 루프를 돌며 A(x)나 B(x) 중 항 수가 작은 항이 먼저 소진될 것입니다.
           그럼 항 수가 아직 남아 있는 항이 있을 수 있겠죠, 그런 항을 위해 for문을 사용합니다.

        for (; sA <= nA; sA++)
            nD++;
        for (; sB <= nB; sB++)
            nD++;
	*/

	// 2. nD만큼 MALLOC으로 할당

	// 3. 전역변수인 allocSize에 allocated memory size를 할당
	// allocSize = nA * sizeof(poly) + nB * sizeof(poly) + nD * sizeof(poly);

	// 왜냐면 아래 코드를 이미 교수님이 작성하셨음
	/* allocSize -= nA * sizeof(poly);
		allocSize -= nB * sizeof(poly);
		allocSize -= nD * sizeof(poly); */

	// 위 방법이 안 된다면 allocated memory 사이즈: 구조체 자체를 sizeof(구조체이름) 이렇게 해야 할 것 같음

	// nA, nB : 다항식 A와 B의 term 수 (0일 수도 있다)
	//
	// 기능 : A+B를 저장하기 위하여 필요한 메모리 크기를 구하여 그 크기 만큼의
	//       메모리를 할당받는다.
	//       꼭 필요한 만큼만 할당받아야 한다. 그래서, 만일 A+B가 zero
	//       polynimial이라면 메모리를 할당받지 않는다.
	// 
	// 출력
	//   pD : A+B를 저장하기 위하여 할당한 메모리를 가리키는 pointer의
	//        pointer.
	//   nD : A+B의 term 수 (이는 return한다)
	//        만일 A+B가 zero polynomial이라면 nD = 0을 return한다(이 경우,
	//        *pD = NULL로 설정(불필요하니까).
	//
	// 주의
	// -- A+B 저장을 위하여 필요한 메모리는 MALLOC 매크로를 단 한 번만 사용하여 
	//    allocation하여야 한다(이를 어기면 점수가 없다)
	//    즉, 필요한 메모리 크기를 정확히 구하여 MALLOC 매크로를 실행한다.
	// -- 전역변수인 allocsize에 dynamic allocation한 메모리 크기를 저장해야 한다.
	//
	int nD = 0; *pD = NULL; // 이 줄은 삭제해도 무방하다(빌드 오류 회피용) 

	// ***이 함수를 완성하세요***

	return nD;
}

void addPoly(int nA, polyPtr A, int nB, polyPtr B, int nD, polyPtr D) {

	// 0. int i, coef_temp = 0;
	// 1. sA와 sB 변수를 선언, 얘네는 모두 0

	// 2. 이후로는 PPT에 있는 부분을 적절히 변환

	/*
	COMPARE 함수 이용할 예정
	#define COMPARE(x, y) \
  	(((x)<(y)) ? -1 : ((x) == (y)) ? 0 : 1)
	*/

	/*
	while ( sA < nA && sB < nB )
	{
		switch(COMPARE(A[sA].expon, B[sB].expon)) {
            case -1: // a의 지수 < b의 지수
				D[i].coef = B[sB].coef
				D[i].expon = B[sB].expon
				i++;
                sB++;
                break;

            case 0: // a의 지수 = b의 지수
				coef_temp = A[sA].coef + B[sB].coef
                if (coef_temp) // 얘네가 더 했을 때 0이 아니어야 attach를 함
					D[i].coef = A[sA].coef + B[sB].coef
                    D[i].expon = B[sA].expon
					i++;
                    sA++;
                    sB++;
                    break;
                
            case 1: // a의 지수 > b의 지수
                D[i].coef = A[sA].coef
				D[i].expon = A[sA].expon
				i++;
                sA++;
                break;
        }

	while 루프를 돌며 A(x)나 B(x) 중 항 수가 작은 항이 먼저 소진될 것입니다.
           그럼 항 수가 아직 남아 있는 항이 있을 수 있겠죠, 그런 항을 위해 for문을 사용합니다.

        for (; sA <= nA; sA++)
            D[i].coef = A[sA].coef
			D[i].expon = A[sA].expon
			i++;
        for (; sB <= nB; sB++)
            D[i].coef = B[sB].coef
			D[i].expon = B[sB].expon
			i++;
	*/

	// 입력
	// nA, nB : 다항식 A와 B의 term 개수
	// A, B   : 다항식 배열 (이들은 zero polynomial일 수도 있다)
	// 
	// 출력
	// nD, D  : A+B의 term 수 및 결과 (zero polynomial일 수도 있다)
	// 주의: nD와 배열 D를 위한 storage는 미리 결정되어 입력된다.
	//

	// ***이 함수를 완성하세요*** 

	return;
}