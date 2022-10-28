#include "H02_polyAdd.h"
extern int allocSize;	   // size of the allocated memory for each test
extern int allocSizeMax;  // max allocated mem size among those of all tests

void readPolyAB(int* pnA, polyPtr* pA, int* pnB, polyPtr* pB) {

    *pnA = *pnB = 0; // 이 줄은 삭제해도 무방하다(빌드 오류 회피용)

    // readPolyAB 함수에서는 다항식 A, 다항식 B의 입력을 분리하여 받겠습니다.
    
    // 1. 다항식 A와 관련된 Data를 입력 받습니다.

    // (1) scanf 함수로 다항식 A의 항의 개수를 입력 받습니다: 포인터 pnA를 이용하여 nA에 값을 저장합니다.

    if (scanf("%d", pnA) == EOF)
	{
		WRONG_INPUT;    // 입력 자료가 부족한 경우, WRONG INPUT 매크로 실행
	}

    // (2) 다항식 A를 저장할 메모리를 동적 할당 합니다.

    if (*pnA < 0)       // 항의 개수가 음수인 경우
	{
		WRONG_INPUT;    // 음수라면, WRONG INPUT 매크로 실행
	}
    else if (*pnA > 0)  // 항의 개수가 양수인 경우
	{
		MALLOC(*pA, polyPtr, sizeof(poly)*(*pnA)); // MALLOC 매크로로 A 저장을 위한 메모리를 할당
		for (int i=0; i<(*pnA); i++)    // A의 항의 개수만큼 for문 반복: 입력 자료 부족 여부를 체크하기 위한 목적
		{
			if (scanf("%d %d", &((*pA)[i].coef), &((*pA)[i].expon)) == EOF)
			{
				WRONG_INPUT;    // 입력 자료가 부족한 경우, WRONG INPUT 매크로 실행
			}
		}
	}
    
    /*
    항의 개수가 0인 경우(zero polynomial)는 따로 조건문을 만들지 않아,
    MALLOC 매크로가 시행되지 않도록 했습니다.
    이는 아래에 다항식 B와 관련된 Data를 입력 받을 때에도 마찬가지입니다.
    */


    // 2. 다항식 B와 관련된 Data를 입력 받겠습니다.

    // (1) scanf 함수로 다항식 B의 항의 개수를 입력 받습니다: 포인터 pnB를 이용하여 nB에 값을 저장합니다

    if (scanf("%d", pnB) == EOF)
	{
		WRONG_INPUT;    // 입력 자료가 부족한 경우, WRONG INPUT 매크로 실행
	}

    // (2) 다항식 B를 저장할 메모리를 동적 할당 합니다.

    if (*pnB < 0)       // 항의 개수가 음수인 경우
	{
		WRONG_INPUT;    // 음수라면, WRONG INPUT 매크로 실행
	}
    else if (*pnB > 0)  // 항의 개수가 양수인 경우
	{
		MALLOC(*pB, polyPtr, sizeof(poly)*(*pnB)); // MALLOC 매크로로 A 저장을 위한 메모리를 할당
		for (int i=0; i<(*pnB); i++)    // A의 항의 개수만큼 for문 반복: 입력 자료 부족 여부를 체크하기 위한 목적
		{
			if (scanf("%d %d", &((*pB)[i].coef), &((*pB)[i].expon)) == EOF)
			{
				WRONG_INPUT;    // 입력 자료가 부족한 경우, WRONG INPUT 매크로 실행
			}
		}
    }

	// pnA, pnB : 다항식 A와 B의 nonzero term의 개수를 저장하는
	//            nA, nB를 가리키는 pointers
	// pA : 다항식 A를 저장하는 배열을 가리키는 pointer A를 가리키는 pointer
	//      즉, poly pointer의 pointer이다.
	// pB : 다항식 B를 저장하는 배열을 가리키는 pointer B를 가리키는 pointer
	// 참고: 이 함수에서 배열과 배열의 크기가 결정되므로 이에 대한 pointer를
	//      parameter로 입력받는다.
	//
	// 기능 : 입력에서 다항식 A와 B에 대한 자료를 읽어 저장한다.
	//        HW pdf의 입력 파일 형식을 참조하자
	// 주의 :  
	//  -- 각 다항식은 zero polynomial 일 수 있다.
	//     입력 자료가 부족할 경우 WRONG INPUT 메크로를 실행한다.
	//  -- A, B 저장을 위한 메모리는 MALLOC 매크로를 각각 한번씩만 사용하여
	//     할당받아야 한다.
	//
	// *pnA = *pnB = 0; 이 줄은 삭제해도 무방하다(빌드 오류 회피용)

	// ***이 함수를 완성하세요***

	return;
}

int allocPolyD(int nA, polyPtr A, int nB, polyPtr B, polyPtr* pD) {

    int nD = 0; *pD = NULL;

    int coef_temp;      // 다항식의 덧셈 simulation 과정에서 다항식 A와 B의 지수가 같은 경우,
                        // 임시적으로 계수의 합을 담아놓기 위한 변수를 선언
    int sA, sB = 0;     // 다항식 A, B에서 더해야 하는 항을 파악하기 위한 startA와 startB 변수 선언

    // 1. 다항식의 덧셈 과정을 simulation 하여, A+B를 저장하기 위하여 필요한 메모리 크기(nD)를 구합니다.
    // 필요한 메모리 크기는 지역 변수 nD에 저장하여 return을 통해 출력할 예정입니다.
    // 이때 중요한 건, 다항식 A나 B의 항의 개수가 0개(zero polynomial)인지 확인해야 한다는 것입니다.

    // (1) 다항식 A는 zero polynomial, 다항식 B는 zero polynomial이 아닌 경우
    // 다항식 D의 항의 개수 nD는 다항식 B의 항의 개수 nB일 것입니다.

    if ( nA == 0 && nB != 0 )
    {
        nD = nB;
    }

    // (2) 다항식 B는 zero polynomial, 다항식 A는 zero polynomial이 아닌 경우
    // 다항식 D의 항의 개수 nD는 다항식 A의 항의 개수 nA일 것입니다.

    else if ( nA != 0 && nB == 0 )
    {
        nD = nA;
    }

    // (3) 다항식 A, B 모두 zero polynomial이 아닌 경우

    else if ( nA != 0 && nB != 0 )
    {
        // 다항식 A, B 중 한 다항식의 항의 개수가 모두 소진될 때까지 덧셈 simulation을 반복합니다.

        while ( sA < nA && sB < nB )   
	    {
            switch(COMPARE(A[sA].expon, B[sB].expon)) {
                case -1:    // case: a의 지수 < b의 지수
                    nD++;	// 지수가 다르다면 지수끼리 계산할 것도 없이 nD는 하나 더 필요
                    sB++;   // startB 값을 +1 하여 다음 항으로 이동
                    break;

                case 0:     // case: a의 지수 = b의 지수
                    coef_temp = A[sA].coef + B[sB].coef;  // coef_temp에 a의 계수 + b의 계수의 합을 연산하여 입력
                    if (coef_temp)  // 다항식 A, B의 계수의 합이 0이 아닌 경우일 때만
                        nD++;       // nD 값을 +1 하여 추후 추가할 메모리 크기 배정
                        sA++;       // startA 값을 +1 하여 다음 항으로 이동
                        sB++;       // startB 값을 +1 하여 다음 항으로 이동
                        break;
                    
                case 1:     // case: a의 지수 > b의 지수
                    nD++;   // 지수가 다르다면 지수끼리 계산할 것도 없이 nD는 하나 더 필요
                    sA++;   // startA 값을 +1 하여 다음 항으로 이동
                    break;
            }
        }

        // 항의 개수가 아직 남은, 다항식을 처리합니다.
        // 아래 두 for문 중 조건에 맞는 한 for문만 실행될 것입니다.

        for (; sA <= nA; sA++)
            nD++;
            sA++;

        for (; sB <= nB; sB++)
            nD++;
            sB++;
    }

    // (4) 다항식 A, B가 모두 zero polynomial인 경우
    // 위 if문 중 어떤 것도 실행되지 않으므로, 처음에 초기화한 대로 nD = 0, *pD = NULL일 것입니다.

    // 2. nD의 값에 따라 MALLOC 매크로를 실행하여, 메모리 크기를 할당합니다.

    if (nD != 0)    // nD가 아닌 경우에만, 메모리 크기를 할당합니다.
    {
        MALLOC(*pD, polyPtr, sizeof(poly)*(nD));
    }
    
    // 3. 전역변수인 allocSize에 dynamic allocation한 메모리 크기를 저장합니다.

    allocSize = nA * sizeof(poly) + nB * sizeof(poly) + nD * sizeof(poly);

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
	// int nD = 0; *pD = NULL; // 이 줄은 삭제해도 무방하다(빌드 오류 회피용) 

	// ***이 함수를 완성하세요***

	return nD;
}

void addPoly(int nA, polyPtr A, int nB, polyPtr B, int nD, polyPtr D) {

    int coef_temp;      // 다항식의 덧셈 과정에서 다항식 A와 B의 지수가 같은 경우,
                        // 임시적으로 계수의 합을 담아놓기 위한 변수를 선언
    int sA, sB, sD = 0;     // 연산을 할 항을 파악하기 위한 startA, startB, startD 변수 선언

    // 1. 다항식 A, B, D가 zero polynomial 여부에 따라 case를 분류하고,
    // 덧셈 연산을 할 것인지 단순 복사를 할 것인지 선택합니다.

    // (1) 다항식 A는 zero polynomial, 다항식 B는 zero polynomial이 아닌 경우
    // 다항식 D는 덧셈 연산을 할 필요 없이, 다항식 B와 같을 것입니다.

    if ( nA == 0 && nB != 0 )
    {
        for (int i=0; i<nB; i++)
        {
            D[i] = B[i];
        }
    }

    // (2) 다항식 B는 zero polynomial, 다항식 A는 zero polynomial이 아닌 경우
    // 다항식 D는 덧셈 연산을 할 필요 없이, 다항식 A와 같을 것입니다.

    else if ( nA != 0 && nB == 0 )
    {
        for (int i=0; i<nA; i++)
        {
            D[i] = A[i];
        }
    }

    // (3) 다항식 A, B 모두 zero polynomial이 아닌 경우

    else if ( nA != 0 && nB != 0 )
    {
        // 다항식 A, B 중 한 다항식의 항의 개수가 모두 소진될 때까지 덧셈 연산을 반복합니다.

        while ( sA < nA && sB < nB )   
	    {
            switch(COMPARE(A[sA].expon, B[sB].expon)) {
                case -1:    // case: a의 지수 < b의 지;수
                    D[sD].coef = B[sB].coef;
				    D[sD].expon = B[sB].expon;
                    sB++;   // startB 값을 +1 하여 다음 항으로 이동
                    sD++;   // startD 값을 +1 하여 다음 항으로 이동
                    break;

                case 0:     // case: a의 지수 = b의 지수
                    coef_temp = A[sA].coef + B[sB].coef;  // coef_temp에 a의 계수 + b의 계수의 합을 연산하여 입력
                    if (coef_temp)  // 다항식 A, B의 계수의 합이 0이 아닌 경우일 때만
                        D[sD].coef = A[sA].coef + B[sB].coef;
                        D[sD].expon = A[sA].expon;
                        sA++;       // startA 값을 +1 하여 다음 항으로 이동
                        sB++;       // startB 값을 +1 하여 다음 항으로 이동
                        sD++;       // startD 값을 +1 하여 다음 항으로 이동
                        break;
                    
                case 1:     // case: a의 지수 > b의 지수
                    D[sD].coef = A[sA].coef;
				    D[sD].expon = A[sA].expon;
                    sA++;   // startA 값을 +1 하여 다음 항으로 이동
                    sD++;   // startD 값을 +1 하여 다음 항으로 이동
                    break;
            }
        }

        // 항의 개수가 아직 남은, 다항식을 처리합니다.
        // 아래 두 for문 중 조건에 맞는 한 for문만 실행될 것입니다.

        for (; sA <= nA; sA++)
            D[sD].coef = A[sA].coef;
            D[sD].expon = A[sA].expon;
            sA++;
            sD++;

        for (; sB <= nB; sB++)
            D[sD].coef = B[sB].coef;
            D[sD].expon = B[sB].expon;
            sB++;
            sD++;
    }

    // (4) 다항식 A, B가 모두 zero polynomial인 경우
    // 위 if문 중 어떤 것도 실행되지 않으므로, 처음에 인수 값을 받은 대로 nD = 0, *pD = NULL일 것입니다.

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