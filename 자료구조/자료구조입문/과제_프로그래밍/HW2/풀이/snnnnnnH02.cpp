#include "H02_polyAdd.h"
extern int allocSize;	   // size of the allocated memory for each test
extern int allocSizeMax;  // max allocated mem size among those of all tests

void readPolyAB(int* pnA, polyPtr* pA, int* pnB, polyPtr* pB) {

	// terms 개수를 입력 받음: pnA, pnB 이용해서(*) nA, nB를 바꾸면 됨
		// 이때 만약 0이라면 zero polynomial이므로 각 항의 정보를 받는 건 하지 마
		// 아예 안 들어왔다면 wrong_input() 출력
		
		/*
		이렇게 쓰면 됨
		if (scanf("%d", &temp) == EOF)	// 1. Column size C를 읽는다.
		{
		WRONG_INPUT;				// 만약 입력되지 않는다면, WRONG_INPUT 호출
		}
		*/
	
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

	// 먼저 nA, nB를 확인해야 되는데,

	// 만약에 nA = 0 이고 nB = 0 이라면, 아래 단계는 수행하지 않고 넘어가면 됨
	// 만일 A+B가 zero polynomial이라면 nD = 0을 return

	// 둘 다 0이 아니라면
	// 무작정 둘만 더하는 것이 아니고 지수가 달라야지 pD를 얼만큼 할당할 것인지 확인이 가능함
	// 집합에서: A + B - (A 교집합 B) 한 것처럼
	// 얘도 nA + nB - n(A 교 B)가 nD임
	// 따라서, 이중 for문 굴리면서 두 숫자가 겹치면 count++ 해서 제거해 주면 됨

	// nD만큼 MALLOC으로 할당해 주면 됨
	// nD는 나중에 return 해 줘야 되니까 정확히 하시고...

	// allocated memory 사이즈: 구조체 자체를 sizeof(구조체이름) 이렇게 해야 할 것 같음
	/* allocSize -= nA * sizeof(poly);
		allocSize -= nB * sizeof(poly);
		allocSize -= nD * sizeof(poly); */
	// 아님, 위 코드 역으로 해서 계산해야 됨...
	// allocSize = nA * sizeof(poly) + nB * sizeof(poly) + nD * sizeof(poly);
	// 이런 식으로...

	// 

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

	// 이제부터 약간 ppt에 있는 부분들을 보면 됨

	/*

	#define COMPARE(x, y) \
  	(((x)<(y)) ? -1 : ((x) == (y)) ? 0 : 1)

	이거 이용하시고

	*/

	/*

	얜 약간 고민을 더 해봐야 됨
	어쩌면 sA, sB라는 개념을 도입해야 할 수도 있겠음...
	순서대로 착착 먹어야 하는데 이걸 for문으로 상승시킬 순 없으니...

	while ( nA > 0 && nB > 0) // 어차피 얘네는 다시 return 안 하니까 막 서도 됨
	{
		이땐 한 놈 씩 처먹으면서 
		switch(COMPARE(A[i].expon, B[i].expon) {
			case -1: // a의 지수 < b의 지수
				D[i] = { B[i].coef, B[i].expon }
                i++;
                break;

            case 0: // a의 지수 = b의 지수
                D에 a랑 b랑 계수 더해서 아무튼 해주고
                
            case 1: // a의 지수 > b의 지수
                얘는 D에 a 관련한 놈만 넣어주고
		}
	}

	while 루프를 돌며 A(x)나 B(x) 중 항 수가 작은 항이 먼저 소진될 것입니다.
           그럼 항 수가 아직 남아 있는 항이 있을 수 있겠죠, 그런 항을 위해 for문을 사용합니다.

        for (; sA <= fA; sA++)
            attach(terms[sA].coef, terms[sA].expon);
        for (; sB <= fB; sB++)
            attach(trems[sB].coef, trems[sB].expon);
        *fD = avail - 1;

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