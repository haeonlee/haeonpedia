
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


    // 편의상 A+B=C라고 하도록 하겠습니다.
    // 2. matrixPtr A, B에서 C의 main hearder node 데이터를 추출합니다.
    // 이때 저장한 nRows, nCols, nTerms의 값은 이후 matrix 형태로 C를 구현하며, 동적 할당을 할 때 사용합니다.

    // (1) C의 main hearder node의 Row와 Col의 값은 A의 Row와 Col의 값과 동일하므로, 값을 그대로 사용
    nRows = A->u.entry.row;
    nCols = A->u.entry.col;

    // (2) 그러나 val의 값, 즉 matrix C의 전체 원소의 개수는 A와 B를 비교한 뒤에 알 수 있음
    //     따라서 여기서는 val의 값을 (A의 원소의 개수) + (B의 원소의 개수)로 초기화한 뒤,
    //     추후에 A와 B를 비교하며 정확한 val의 값을 찾아가도록 하겠음
    nTerms = (A->u.entry.val) + (B->u.entry.val);


    // 3. matrixPtr A와 B에서 entry data들을 추출해, A+B 연산을 합니다.
    // 이때, A+B 연산 값은 entryNode 구조체 배열(Carr)에 저장한 뒤, 추후에 사용할 것입니다.

    // (1) entryNode 구조체 배열(Carr) 선언한 뒤,
    //     배열 전체를 (row, col, val)=(-1, -1, -1)로 초기화

    int CArrSize = (A->u.entry.val) + (B->u.entry.val);
    entryNode CArr[CArrSize];       // A의 terms 개수 + B의 terms 개수만큼 크기를 할당
                                    // CArr에 남는 공간이 생길 순 있지만, 프로그램상 편의를 위해 이렇게 배정
    
    // 주의: 쓰레기 값이 저장되는 것을 막기 위해서 CArr의 모든 값을 (-1, -1, -1)로 선언합니다.
    // matrix에서 row와 col은 음수가 나올 수 없으므로, 음수 값인 -1이 나오면 NULL인 셈 치기 위해서입니다.
    // val 값은 무엇이든지 상관 없으므로, 통일성을 위해 -1을 저장합니다.
    for (i = 0; i < CArrSize; i++)
    {
        CArr[i].row = -1;
        CArr[i].col = -1;
        CArr[i].val = -1;    
    }

    // (2) A+B를 연산해 CArr[i]에 데이터로 저장하는 과정은 아래와 같습니다.
    //     - A와 B에서 row 기준으로 entry node의 값을 받아온 뒤,
    //     - A와 B의 row와 col 값을 비교하며 A+B 연산을 합니다.
    //     - 그렇게 추출한 값(row, col, val)을 Carr[i]에 저장합니다.

    matrixPtr Atmp, Btmp;
    matrixPtr Ahead = A->right;
    matrixPtr Bhead = B->right;
    
    Atmp = Ahead->right;
    Btmp = Bhead->right;

    #define COMPARE(x, y) \
    (((x)<(y)) ? -1 : ((x) == (y)) ? 0 : 1)

    int i = 0;              // CArr에 데이터를 저장할 때 사용할 index

    for (int r = 0; r < (A->u.entry.row); r++)  // row 기준으로 데이터 입력
    {
        // while 루프
        // 종료 조건: A, B 중에서 하나라도 해당 row에서의 노드를 모두 소진하고 다시 head로 돌아온다면 종료  
        while ((Atmp != Ahead) && (Btmp !=Bhead) )
        {
            switch(COMPARE(Atmp->u.entry.col, Btmp->u.entry.col))
            {
                case -1:    // Atmp의 col 값 < Btmp의 col 값
                    CArr[i].row = Atmp->u.entry.row;
                    CArr[i].col = Atmp->u.entry.col;
                    CArr[i].val = Atmp->u.entry.val;
                    i++;
                    Atmp = Atmp->right;     // 계산을 마쳤다면, Atmp는 다음 노드로 이동
                    break;

                case 0:     // Atmp의 col 값 = Btmp의 col 값
                    // Atmp의 val 값 + Btmp의 val 값이 0이 아닐 때만 CArr에 저장
                    if ((Atmp->u.entry.val)+(Btmp->u.entry.val))
                    {
                        CArr[i].row = Atmp->u.entry.row;
                        CArr[i].col = Atmp->u.entry.col;
                        CArr[i].val = Btmp->u.entry.val;
                        i++;
                    }
                    Atmp = Atmp->right;     // 계산을 마쳤다면, Atmp는 다음 노드로 이동
                    Btmp = Btmp->right;     // 계산을 마쳤다면, Btmp는 다음 노드로 이동
                    nTerms -= 1;            // 중복 계산된 nTerms의 값을 제거합니다.
                    break;

                case 1:     // Atmp의 col 값 > Btmp의 col 값
                    CArr[i].row = Btmp->u.entry.row;
                    CArr[i].col = Btmp->u.entry.col;
                    CArr[i].val = Btmp->u.entry.val;
                    i++;
                    Btmp = Btmp->right;     // 계산을 마쳤다면, Btmp는 다음 노드로 이동
                    break;
            }
        }

        // A, B 중에서 아직 노드가 남아 있을 수 있기 때문에, for문을 사용해 남은 노드를 모두 소진

        for (; Atmp != Ahead; Atmp = Atmp->right)
        {
            CArr[i].row = Atmp->u.entry.row;
            CArr[i].col = Atmp->u.entry.col;
            CArr[i].val = Atmp->u.entry.val;
            i++;
        }

        for (; Btmp != Bhead; Btmp = Btmp->right)
        {
            CArr[i].row = Btmp->u.entry.row;
            CArr[i].col = Btmp->u.entry.col;
            CArr[i].val = Btmp->u.entry.val;
            i++;
        }

        // 해당 row에서 모든 연산이 끝났다면, 다음 row로 이동

        Ahead = Ahead->u.next;     
        Bhead = Bhead->u.next;
    }
    

    // 4. 전체 Matrix의 정보가 담긴 Main header node를 생성합니다.
    // 이때, nRows, nCols, nTerms의 값을 사용합니다.

    node = newNode();
    allocSize += sizeof(matrixPtr);

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


    // 5. head node 할당을 위한, 포인터 배열 hdnode를 동적 할당합니다. 
    // 이때 할당한 메모리는 추후 free할 것이므로, allocSize 값에서는 임시적으로 넣었다가 뺄 예정입니다.
    
    MALLOC(hdnode, matrixPtr*, nHeads*sizeof(matrixPtr));
    allocSize += nHeads * sizeof(matrixPtr);    // 이때 추가된 값은, 추후에 다시 뺄 예정


    // 6. head node들을 동적 할당합니다.
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

    // 7. (1) entry node들을 동적 할당하고
    //    (2) CArr 배열에서 각 entry node들의 데이터를 받아옵니다.
    //    (3) row/col 기준으로 각각 연결합니다.

    curRow = 0;             // row 기준으로 연결하기 위해 선언한 변수 curRow
    last = hdnode[0];       // row 기준으로 연결하기 위해 선언한 변수 last

    for (i = 0; i < nTerms; i++) {
        row = CArr[i].row;
        col = CArr[i].col;
        val = CArr[i].val;

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

    // 8. col 기준으로 연결 2
    // 위에서 말한 임시적(temporal)인 setting을 제대로 수정하는 작업입니다.

    for (i=0; i<nCols; i++)
    {
        hdnode[i]->u.next->down=hdnode[i];  // hdnode[i]->u.next
                                            // 즉, 각 col의 마지막 노드를 circular하게 header node랑 연결
    }

    // 9. hdnode[]끼리 연결
    
    // (1) hdnode끼리 연결
    for (i=0; i < nHeads - 1; i++)
    {
        hdnode[i]->u.next = hdnode[i+1];
    }

    // (2) 맨 마지막 노드는 main header node랑 연결

    hdnode[nHeads-1]->u.next = node;

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

    // 0. [ Row X Col ] 형태로 printf() 합니다.

    printf("[%d X %d]\n", node->u.entry.row, node->u.entry.col);

    // 1. writeFull을 위해 필요한 변수들을 선언합니다.

    matrixPtr tmp;
    matrixPtr head = node->right;

    int oldRow, oldCol;             // 이전에 입력된 노드의 데이터를 의미
    int newRow, newCol, newVal;     // 새롭게 입력된 노드의 데이터를 의미
    int pDataNum;                   // printDataNum으로 현재까지 출력한 data의 개수
    int repeatZero;                 // 반복 횟수 (즉, Node 사이의 간격)

    // 2. writeFull 과정을 실행합니다.
    // NOTE: writeFull 과정은 '데이터로 입력된 node 사이의 거리'와 '현재까지 출력한 data의 개수'만 알면 간단합니다.

    // - "데이터로 입력된 node 사이의 거리"가 필요한 이유
    //   가령, matrixPtr node를 통해 (0, 0, 1)과 (0, 4, 2) 데이터가 입력됐다고 가정합시다.
    //   writeFull 함수 데이터는 [1 0 0 0 2] 로 위 데이터를 출력해야 할 것입니다.
    //   node 사이의 간격은 3인데, 3번을 반복하여 0이 출력됐다는 것을 알 수 있습니다.
    //   즉, 0을 출력하기 위해 node 사이의 거리가 필요한 것입니다.
    //   저는 이러한 node 사이의 거리를 repeatZero에 넣어서 0을 반복 출력하는 for문을 작성할 것입니다.

    // - 현재까지 출력한 data의 개수
    //   그러나 위 형태로 출력 불가한 경우가 있습니다. (0, 2, 2)와 (1, 1, 3) 데이터처럼 row가 달라진 경우이지요.
    //   그럴 땐 출력하고 있는 위치가 row의 마지막 node일 땐, 줄바꿈 문자(\n)를 입력해야 합니다.
    //   이를 판단하기 위해서는 print를 할 때마다 pDataNum(초기값 0)을 1씩 증가하여,
    //   현재까지 출력한 data의 개수를 파악하면 됩니다.
    //   이후, (node->u.entry.col)을 pDataNum로 나누어서 나머지가 없을 때, 줄바꿈을 하면 됩니다.
    //   예를 들어 col의 개수가 3이라면, pDataNum이 3, 6, 9, ... 일 때마다 줄바꿈이 필요하기 때문입니다.

    // (1) 변수를 적절한 값으로 초기화합니다.

    oldRow = 0, oldCol = 0;       // 초기 입력 노드를 의미하는 oldRow와 oldCol은 (0, 0)으로 선언합니다.
    pDataNum = 0;                 // 현재 print하는 점 위치를 의미하는 pRow와 pCol도 

    // (2) row를 기준으로 값을 받아오면서, writeFull을 시작합니다.

    for (int i = 0; i < node->u.entry.row; i++ )
    {
        for ( tmp = head->right; tmp != head; tmp = tmp->right; )
        {
            newRow = tmp->u.entry.row;
            newCol = tmp->u.entry.col;
            newVal = tmp->u.entry.val;

            // 0을 출력할 반복 횟수를 계산
            repeatZero = (oldRow - newRow)* (node->u.entry.col) + (newCol - oldCol) - 1;

            // for 반복문으로 repeat: 0을 출력
            for (int j = 0; j < repeatZero; j++)
            {
                if (((node->u.entry.col)%pDataNum) == 0)
                {
                    printf("%5d\n", 0);
                    pDataNum += 1;
                }
                else
                {
                    printf("%5d ", 0);
                    pDataNum += 1;
                }
            }

            // NewVal를 printf로 출력합니다.
            if (((node->u.entry.col)%pDataNum) == 0)
            {
                printf("%5d\n", newVal);
                pDataNum += 1;
            }
            else
            {
                printf("%5d ", newVal);
                pDataNum += 1;
            }      

            // new data를 old data로 바꾸고, 새로운 데이터를 받아올 생각을 합니다.
            oldRow = newRow;
            oldCol = newCol;
        }

        // 다음 row로 넘어갑니다.
        head = head->u.next;
    }

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
    allocSize += sizeof(matrixPtr);

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

    hdnode[nHeads-1]->u.next = node;

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

    // 1. H0의 정보를 head에 입력합니다.
    matrixPtr head = (*node)->right;

    // 2. 필요한 변수를 선언합니다.
    matrixPtr x, y;

    // 3. row를 기준으로 free()합니다.
    // 이때, allocSize 값을 정확히 줄여야 합니다.

    for (int i = 0; i < (*node)->u.entry.row; i++)
    {
        y = head->right;
        while ( y != head )
        {
            x = y;              // 지울 node를 x에 저장
            y = y->right;       // y는 다음 node를 지시
            free(x);            // free(x)로 동적 메모리 할당 해제
            allocSize -= sizeof(matrixNode);
        }
        x = head;               // x는 해당 row의 head를 지시
        head = head->u.next;    // head는 다음 head로 이동
        free(x);                // 해당 row의 head까지 삭제
        allocSize -= sizeof(matrixNode);
    }

    // 4. 혹시 남은 head node가 있다면(row의 개수 < col의 개수), 지워줍니다.
    // 쉽게 말해, 아직 col 기준으론 Head node가 남아 있는 경우를 말합니다.

    y = head;
    while ( y != *node )
    {
        x = y;
        y = y->u.next;
        free(x);
        allocSize -= sizeof(matrixNode);
    }

    // 5. 마지막으로, main head node까지 삭제합니다.

    free(*node);
    allocSize -= sizeof(matrixNode);
    *node = NULL;

    //------------------------------------------------------
    return;
}


