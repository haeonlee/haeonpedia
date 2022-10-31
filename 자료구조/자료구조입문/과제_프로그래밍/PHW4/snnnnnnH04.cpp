
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


