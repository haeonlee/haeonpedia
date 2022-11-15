﻿
#include "H04sparseMat.h"

extern int allocSize;      // size of allocated memory currently used

matrixPtr madd(matrixPtr A, matrixPtr B) {
    // return A + B in sparse matrix structure

    // must use below three variables
    // 아래 세 개의 변수는 mread에서 사용한 변수와 동일한 역할을 한다.
    // matrix 덧셈도 결국에는 sparse matrix 구조를 만드는 것이므로
    // 아래 변수들이 반드시 필요하다.
    matrixPtr node = NULL;
    matrixPtr* hdnode = NULL;
    int nHeads = MAX2(A->u.entry.col, A->u.entry.row);

    //------------------------------------------------------
    // 이 함수를 완성하세요. mread를 이해했다면 비교적 쉽게 작성할 수 있습니다.
    // allocSize를 정확히 누적해야합니다.

    // 1. 필요한 변수를 선언합니다.
    int nRows, nCols, nTerms, i;
    int row, col, val, curRow;
    matrixPtr tmp, last, node;

    // 2. matrixPtr A, B에서 main hearder node 데이터를 추출합니다.

    // 이때, matrix C의 Row와 Col의 값은 A(또는 B)의 Row와 Col의 값과 동일하므로, 그대로 값을 사용합니다.
    // 그러나 val의 값, 즉 matrix C의 전체 원소의 개수는 A와 B를 비교한 뒤에 알 수 있습니다.
    // 따라서 여기서는 val의 값을 (A의 원소의 개수) + (B의 원소의 개수)로 초기화한 뒤,
    // 추후에 A와 B를 비교하며 정확한 val의 값을 찾아가도록 하겠습니다.

    nRows = A->u.entry.col;
    nCols = A->u.entry.row;
    nTerms = (A->u.entry.val) + (B->u.entry.val);

    // 3. 입력 데이터를 이용해 전체 Matrix의 정보가 담긴 Main header node를 생성합니다.
    node = newNode();
    alloSize += sizeof(matrixPtr);

    node->tag = entry;
    node->u.entry.row = nRows;
    node->u.entry.col = nCols;
    node->u.entry.val = nTerms;

    // 예외 처리: 만약 zero matrix라면
    // Main header node는 right에서 자기 자신을 가리키게끔 설정하고, 그대로 반환합니다.
    if (!nHeads) {
        node -> right = node;
        return node;
    }

    // 4. head node 할당을 위한, 포인터 배열 hdnode를 동적 할당합니다. 
    // 이때 할당한 메모리는 추후 free할 것이므로, allocSize 값에서는 임시적으로 넣었다가 뺄 예정입니다.
    
    MALLOC(hdnode, matrixPtr*, nHeads*sizeof(matrixPtr));
    allocSize += nHeads * sizeof(matrixPtr);    // 이때 추가된 값은, 추후에 다시 뺄 예정

    // 5. head node들을 동적 할당합니다.
    // 이때, head node들끼리 연결하는 부분(right, u.next)에선 임시적으로 자기 자신을 가리키게 합니다.
    // 이는 추후에 다시 제대로 연결할 예정입니다.
    
    for (i=0; i< nHeads; i++)
    {
        tmp = newNode();
        hdnode[i] = tmp;
        hdnode[i]->tag = head;
        hdnode[i]->right = tmp;
        hdnode[i]->u.next = tmp;
    }

    // 6. C에 데이터를 입력하는 과정을 설명하자면, 아래와 같습니다.
    //    (1) A와 B에서 row 기준으로 entry node의 값을 받아온 뒤,
    //        A와 B의 row와 col 값을 비교하며 A+B 연산을 합니다.
    //        이때 중요한 것은, C의 row, col, val 값을 정확하게 정하는 것입니다.
    //    (2) entry node들을 동적 할당하고
    //    (3) row/col 기준으로 각각 연결합니다.


    // (1) A와 B에서 row 기준으로 entry node의 값을 받아온 뒤,
    //     A와 B의 row와 col 값을 비교하며 A+B 연산을 합니다.
    //     이때 중요한 것은, C의 row, col, val 값을 정확하게 정하는 것입니다.

    matrixPtr Atmp, Btmp;
    matrixPtr Ahead = A->right;
    matrixPtr Bhead = B->right;

    for (int r = 0; r < (A->u.entry.row); r++)
    {
        // while()
        {
            // 이때 비교를 하면 됨
            // 먼저 row의 값은 같은 상황
            // -> 만약 A나 B 중에서 다시 해당 row에서 쓸 걸 다 쓴 상황이면... 더는 연산할 필요가 없긴 함
            // 아래 추출 방법을 A, B 동시에 해야 함... how to? row는 같으니까, col 값으로 비교를 조져...
            // col이 누가 큰지 따라서 어떻게 할건지 하고...
            // 그리고 col이 같으면, A+B 연산
            // 걍 비교하면서 동적할당도 하고;;; 연결도 하고 그래야됨
        }

        /* 다항식에서 A+B 하는ㄴ 방법

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
                    D[i].expon = A[sA].expon
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


       
        
        /* row를 기준으로 A의 값을 추출하는 방법임
        for (Atmp = Ahead->right; Atmp != Ahead; Atmp = Atmp->right)
        {
            Atmp->u.entry.row;
            Atmp->u.entry.col;
            Atmp->u.entry.val;
        }
        */

    }

    // (2) entry node들을 동적 할당하고
    // (3) row/col 기준으로 각각 연결합니다.

    curRow = 0;             // row 기준으로 연결하기 위해 선언한 변수 curRow
    last = hdnode[0];       // row 기준으로 연결하기 위해 선언한 변수 last

    for (i = 0; i < nTerms; i++) {
        scanf("%d %d %d", &row, &col, &val);

        // 만약 새로 입력된 데이터가 curRow(즉, 이전까지 입력 받았던 데이터들의 Row)보다 크다면,
        // 당연히 아래 row로 넘어가야 할 것입니다.
        if (row > curRow) {
            last->right = hdnode[curRow];   // row의 마지막 노드를 head node랑 연결

            // 새로운 row의 연결고리를 만들기 위한 setting을 합니다.
            curRow = row;                   // 새로운 row로 curRow의 값을 바꿈
            last = hdnode[row];             // last 값은 hdnode[row]로 바꿈
        }

        tmp = newNode();                    // newNode를 만들었으므로
        allocSize += sizeof(matrixPtr);     // allocSize 누적 갱신

        tmp->tag = entry;                   
        tmp->u.entry.row = row;             // scanf로 입력한 값을 entry에 넣음
        tmp->u.entry.col = col;
        tmp->u.entry.val = val;

        // (1) row 기준으로 연결
        last->right = tmp;                  // last, 즉 이전에 만든 노드의 right 값을 tmp로 설정
        last = tmp;                         // last 값을 방금 만든 노드 tmp로 갱신
        
        // (2) col 기준으로 연결 1
        hdnode[col]->u.next->down = tmp;    // col 기준으로 연결
        hdnode[col]->u.next = tmp;          // 이때, hdnode[col]->u.next는 tmp,
                                            // 즉, 해당 행에서 마지막으로 입력된 node를 가리킵니다.
                                            // 이는 임시적(temporal)인 setting입니다.
    }

    last->right = hdnode[curRow];           // 맨 마지막 node까지 circular하게 header node랑 연결

    // 7. col 기준으로 연결 2
    // 위에서 말한 임시적(temporal)인 setting을 제대로 수정하는 작업입니다.

    for (i=0; i<nCols; i++)
    {
        hdnode[i]->u.next->down=hdnode[i];  // hdnode[i]->u.next
                                            // 즉, 각 col의 마지막 노드를 circular하게 header node랑 연결
    }

    // 8. hdnode[]끼리 연결
    
    // (1) hdnode끼리 연결
    for (i=0; i < nHeads - 1; i++)
    {
        hdnode[i]->u.next = hdnode[i+1];
    }

    // (2) 맨 마지막 노드는 main header node랑 연결

    hdnode[nHeads-1]->u.text = node;

    // (3) main header nodes는 hdnode[0]랑 연결
    node->right = hdnode[0];



    //------------------------------------------------------
    //testSMatrix_mid(node, hdnode); // 필요시 코멘트를 지워 자신이 만든 구조를
                                     // 확인해보자
    //
    // 아래 두 statement는 반드시 사용해야 오류가 없습니다.
    //
    // hdnode는 header node의 pointer들을 저장하는 배열인데,
    // 이 함수를 종료하면, 이 배열을 free할 수 없다(이유를 생각해보자)
    // 그런데, 실제로 header node 들은 circular linked list 형태로
    // node->right를 header로 하여 연결되어 있으므로 이 배열
    // hdnode는 더이상 쓸모가 없다. 따라서, 여기서 free한다.
    allocSize -= nHeads * sizeof(matrixPtr);
    free(hdnode);

    return node;
}

void mwriteFull(matrixPtr node) {
    // Print out the matrix in complete squared form

    // 이 함수는 sparse matrix를 sparse 형태가 아닌 정규 matrix 형태로 출력하는
    // 함수입니다(예로 보인 출력을 확인하세요.
    // 주의 사항:
    // 1. 기본적으로 예제 출력과 동일한 출력이 되도록 하여야 합니다(아니면 많은 감점)
    // 2. 각 테스트 간에는 1 줄의 빈줄을 만든다(첫번째 테스트 출력 전에는 빈줄 없어애
    //    하고 마지막 테스트는 마지막 빈줄을 출력한다.
    // 3. 각 수자는 %5d를 사용하며, 수와 수 사이에는 정확히 하나의 빈칸을 준다.
    //    0을 출력할 때도 마찬가지로 %5d를 사용한다.
    // 4. 1st column의 수의 경우 이의 출력 전에 빈칸이 있으면 안된다.
    // 5. 각 테스트의 출력 캡션은 주어진 예와 그 형식이 정확히 동일해야 한다.
    // 6. 빈칸 대신 tap ('\t')를 사용하면 안된다.
    // 7. 이 함수는 앞에 main 함수의 출력문과 연동해서 실행해야 제대로 된 출력이 나옵니다.
    //
    // 이 함수는 의외로 상당히 어려울 수 있습니다. 특히, format을 정확히 위에 요구하는 사항,
    // 그리고 예로 보인 출력과 완전히 같아야 합니다.
    // 동일한 출력 여부를 windiff로 확인하세요.
    // (https://www.grigsoft.com/download-windiff.htm 에서 다운 가능).
    // 이렇게 조건을 까다롭게 주는 것은, 추후 정확한 프로그램 작성을 위한 사전 연습을
    // 시키기 위함입니다.
    //
    //------------------------------------------------------
    // 이 함수를 완성하세요. 



    //------------------------------------------------------


    return;
}

matrixPtr mread(void) {
    // read a spase matrix and store

    // must use below three variables
    // these have the same meaning as in the lecture note
    // initializations are just for no reporting warnings
    matrixPtr node = NULL;      
    matrixPtr* hdnode = NULL;
    int nHeads = 0;
 
    //------------------------------------------------------
    // 이 함수를 완성하세요. 강의자료의 내용과 같으니 직접 입력하며
    // 그 동작을 이해합시다.
    // 그리고, allocSize를 정확히 누적해야합니다.


    // 1. 필요한 변수를 선언합니다.
    int nRows, nCols, nTerms, i;
    int row, col, val, curRow;
    matrixPtr tmp, last, node;

    // 2. scanf 함수를 통해 데이터를 입력 받습니다.
    // 입력 데이터: nRows, nCols, nTerms
    scanf("%d %d %d", &nRows, &nCols, &nTerms);

    nHeads = MAX2(nCols, nRows);    // head node의 개수 = MAX2(nCols, nRows)

    // 3. 입력 데이터를 이용해 전체 Matrix의 정보가 담긴 Main header node를 생성합니다.
    node = newNode();
    alloSize += sizeof(matrixPtr);

    node->tag = entry;
    node->u.entry.row = nRows;
    node->u.entry.col = nCols;
    node->u.entry.val = nTerms;

    // 예외 처리: 만약 zero matrix라면
    // Main header node는 right에서 자기 자신을 가리키게끔 설정하고, 그대로 반환합니다.
    if (!nHeads) {
        node -> right = node;
        return node;
    }

    // 4. head node 할당을 위한, 포인터 배열 hdnode를 동적 할당합니다. 
    // 이때 할당한 메모리는 추후 free할 것이므로, allocSize 값에서는 임시적으로 넣었다가 뺄 예정입니다.
    
    MALLOC(hdnode, matrixPtr*, nHeads*sizeof(matrixPtr));
    allocSize += nHeads * sizeof(matrixPtr);    // 이때 추가된 값은, 추후에 다시 뺄 예정

    // 5. head node들을 동적 할당합니다.
    // 이때, head node들끼리 연결하는 부분(right, u.next)에선 임시적으로 자기 자신을 가리키게 합니다.
    // 이는 추후에 다시 제대로 연결할 예정입니다.
    
    for (i=0; i< nHeads; i++)
    {
        tmp = newNode();
        hdnode[i] = tmp;
        hdnode[i]->tag = head;
        hdnode[i]->right = tmp;
        hdnode[i]->u.next = tmp;
    }

    // 6. (1) entry node들을 동적 할당하고
    //    (2) scanf() 함수로 각 entry node들의 데이터를 받아옵니다.
    //    (3) row/col 기준으로 각각 연결합니다.

    curRow = 0;             // row 기준으로 연결하기 위해 선언한 변수 curRow
    last = hdnode[0];       // row 기준으로 연결하기 위해 선언한 변수 last

    for (i = 0; i < nTerms; i++) {
        scanf("%d %d %d", &row, &col, &val);

        // 만약 새로 입력된 데이터가 curRow(즉, 이전까지 입력 받았던 데이터들의 Row)보다 크다면,
        // 당연히 아래 row로 넘어가야 할 것입니다.
        if (row > curRow) {
            last->right = hdnode[curRow];   // row의 마지막 노드를 head node랑 연결

            // 새로운 row의 연결고리를 만들기 위한 setting을 합니다.
            curRow = row;                   // 새로운 row로 curRow의 값을 바꿈
            last = hdnode[row];             // last 값은 hdnode[row]로 바꿈
        }

        tmp = newNode();                    // newNode를 만들었으므로
        allocSize += sizeof(matrixPtr);     // allocSize 누적 갱신

        tmp->tag = entry;                   
        tmp->u.entry.row = row;             // scanf로 입력한 값을 entry에 넣음
        tmp->u.entry.col = col;
        tmp->u.entry.val = val;

        // (1) row 기준으로 연결
        last->right = tmp;                  // last, 즉 이전에 만든 노드의 right 값을 tmp로 설정
        last = tmp;                         // last 값을 방금 만든 노드 tmp로 갱신
        
        // (2) col 기준으로 연결 1
        hdnode[col]->u.next->down = tmp;    // col 기준으로 연결
        hdnode[col]->u.next = tmp;          // 이때, hdnode[col]->u.next는 tmp,
                                            // 즉, 해당 행에서 마지막으로 입력된 node를 가리킵니다.
                                            // 이는 임시적(temporal)인 setting입니다.
    }

    last->right = hdnode[curRow];           // 맨 마지막 node까지 circular하게 header node랑 연결

    // 7. col 기준으로 연결 2
    // 위에서 말한 임시적(temporal)인 setting을 제대로 수정하는 작업입니다.

    for (i=0; i<nCols; i++)
    {
        hdnode[i]->u.next->down=hdnode[i];  // hdnode[i]->u.next
                                            // 즉, 각 col의 마지막 노드를 circular하게 header node랑 연결
    }

    // 8. hdnode[]끼리 연결
    
    // (1) hdnode끼리 연결
    for (i=0; i < nHeads - 1; i++)
    {
        hdnode[i]->u.next = hdnode[i+1];
    }

    // (2) 맨 마지막 노드는 main header node랑 연결

    hdnode[nHeads-1]->u.text = node;

    // (3) main header nodes는 hdnode[0]랑 연결
    node->right = hdnode[0];

    //------------------------------------------------------
    //testSMatrix_mid(node, hdnode); // 필요시 코멘트를 지워 자신이 만든 구조를
                                     // 확인해보자
    // 아래 두 statement는 반드시 사용해야 오류가 없습니다.
    allocSize -= nHeads * sizeof(matrixPtr);
    free(hdnode);

    return node;
}

void merase(matrixPtr* node){
    // deallocate the storage for a sparse matrix

    // matrix 하나에 사용된 메모리를 deallocation하는 함수입니다.
    // 강의자료의 내용과 같습니다만, allocSize 값이 0이 되어야 합니다.
    // 이 allocSize로 괴롭히는(?)이유는 연습할 때 메모리 관리를 철저히 하는
    // 습관을 들이게 하고 싶어서입니다.
    // 
    //------------------------------------------------------
    // 이 함수를 완성하세요. 
    // allocSize 값을 정확히 줄여 0이 되어야 합니다.



    //------------------------------------------------------
    return;
}


