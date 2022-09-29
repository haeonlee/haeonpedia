#include "H02_polyAdd.h"
extern int allocSize;	   // size of the allocated memory for each test
extern int allocSizeMax;  // max allocated mem size among those of all tests

void readPolyAB(int* pnA, polyPtr* pA, int* pnB, polyPtr* pB) {

    *pnA = *pnB = 0; // 이 줄은 삭제해도 무방하다(빌드 오류 회피용)

    // readPolyAB 함수에서는 다항식 A, 다항식 B의 입력을 분리하여 받도록 하겠습니다.
    
    // 1. 다항식 A와 관련된 Data를 입력 받겠습니다.
    
    // (1) 다항식 A의 항의 개수를 입력: 포인터를 이용하여 nA에 값을 저장합니다.

    if (scanf("%d", pnA) == EOF)
	{
		WRONG_INPUT;    // 입력 자료가 부족한 경우, WRONG INPUT 매크로 실행
	}

    // (2) 다항식 A를 저장할 메모리를 동적 할당

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

    // (1) 다항식 B의 항의 개수를 입력: 포인터를 이용하여 nB에 값을 저장합니다.

    // (2) 다항식 B를 저장할 메모리를 동적 할당




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
	*pnA = *pnB = 0; // 이 줄은 삭제해도 무방하다(빌드 오류 회피용)

	// ***이 함수를 완성하세요***

	return;
}

int allocPolyD(int nA, polyPtr A, int nB, polyPtr B, polyPtr* pD) {
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