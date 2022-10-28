#include "H03_maze.h"

extern queuePtr front, rear;
extern int sR, sC;
extern int dR, dC;
extern int allocSize;
extern int allocSizeMax;

// queue 관련
// 1. queue init : front = NULL
// 2. empty check: front == NULL 인지 확인
// use the following two functions

void addq(int r, int c) {
    // 0. 큐 header front와 rear는 global 변수이다.
    // 1. FIFO에서 (r, c) 위치에 enqueue
    // 2. allocSize와 allocSizeMax를 수정
    // 
    // 이 함수를 완성하세요.

    return;
}

void deleteq(int* r, int* c) {
    // 0. queue header front와 rear는 전역 변수입니다.
    // 1. 큐를 호출하기 전에 이미 empty하진 않은지 확인하세요.
    // 2. FIFO에서 (r,c) 위치에 dequeue, 그리고 값 return
    // 3. allocSize와 allocSizeMax를 수정

    queuePtr tmp = front;   // get an element pointer

    if (!tmp) {
        printf("Check if the queue is empty before call.\n");
        exit(EXIT_FAILURE);
    }
    *r = tmp->row;
    *c = tmp->col;

    front = tmp->p;
    free(tmp);              // release the storage
    allocSize -= sizeof(queue);

    return;
}

char** readMaze(int *Rm, int *Cm) {
    // 0. 입력 데이타는 오류가 없다고 가정한다(즉, 입력에 오류가 있으면 임의의 동작 무방)
    // 1. 미로 데이타를 읽는 작업은 fgets(buffer, max_size, FILE)을 사용한다.
    //    buffer: string array of max_size,
    //    max_size: 읽어야 할 최대 글자수인데 함수 fgets( )는 char를 '\n'까지 읽고
    //              바로 다음에 EOS('\0')를 추가한다.
    //              따라서, 우리의 경우 max_size는 최소 *Cm + 2가 되어야 한다.
    //    buffer: 크기가 max_size인 string buffer인데, 우리의 경우 maze의 한 row가 된다.
    //    FILE:   file pointer인데 우리는 redirection을 사용하므로 stdin을 사용한다.
    //    추가 정보가 필요하다면 https://www.ibm.com/docs/ko/i/7.3?topic=functions-fgets-read-string
    //      혹은 인터넷을 검색해보자.
    // 2. 미로 크기를 나타내는 width C와 height R을 scanf( )를 사용하여 입력받는다. 
    //    주의: 입력 파일에서 미로 크기를 나타내는 두 수 중 1st 수가 width C이고 2nd가 height R이다.
    // 3. scanf( ) 사용하면 해당 줄 끝의 '\n'은 입력 버퍼에 그대로 남아 있는데 이는 다음에 실행하는
    //      fgets()를 사용한 maze 정보를 읽는데 방해가 되므로 이를 제거하여야 한다.
    //      이를 위하여 크기가 최소 2 이상인('\n', '\0' 저장용) 버퍼를 static으로 선언하고
    //      fgets를 이 버퍼를 사용하여 호출한다
    //      (이 버퍼는 allocSize에 포함하지 않는다(input size에 무관하므로). 
    // 3. 미로를 나타내는 text 배열은 Rm 개의 row와 Cm개의 column으로 구성되어 있다.
    //      그런데 입력 파일을 보면 알겠지만, barrier들 때문에 Rm = 2R + 1이고 Cm=2C + 1이다.
    //      이에 따라 Rm과 Cm을 계산한다.
    // 4. maze의 크기는 row 개수 = Rm, column 개수는 = Cm + 2로 정한다.
    //      Column 개수가 2만큼 큰 이유는 fgets를 호출했을 때 ('\n', '\0')이 마지막에 포함되기
    //      때문이다. 그런데 이 두 글자는 추후 maze 정보를 출력하는데 편하다(함수 printMaze 참조).
    // 5. 이제 크기가 Rm X (Cm+2)인 메모리를 할당받아 maze 정보를 입력합는다.
    //    allocSize와 allocSizeMax를 이 작업 중에 갱신하여야 한다.
    // 6. 본 과제에서 주어지는 maze는 항상 starting position = maze 좌상 빈칸이고
    //      destination = maze 우하 빈칸이다.
    //      따라서, destination position은 항상 dR = Rm - 2, dC = Cm - 2로 세팅한다.

    char** maze = NULL; // 초기화는 편의상 넣은 것임(코드를 넣으면 불필요)

    // 이 함수를 작성하세요

    return maze;
}

int findShortest(char **maze, int **mark, int Rm, int Cm) {
    //
    // 1. maze(sR,sC)부터 maze(dR,dC)까지 최단 경로를 찾는다.
    // 2. 두 단계 즉, wave propagation 단계와 backtracing 단계를 통해 경로를 찾는다.
    // 3. wave propagation 단계 (pseudo code)
    //      queue Q = empty; found = false;
    //      addq(sR, sC) and mark(sR, sC) = 0; // start position을 Q에 추가
    //      while (Q != empty) {
    //        (r, c) = deleteq();
    //        d = mark(r, c)라고 하자;
    //        (r, c)의 좌상우하 cell들에 대해 다음 작업 수행(범위를 벗어난 경우 해당 좌표는 skip) {
    //          cell 하나의 좌표를(rr, cc)라고 하자; // 좌상우하 순으로 체크하여야 한다(채점을 위하여)
    //          if (mark(rr, cc) == UNVISITED) {
    //              mark(rr, cc) = d + 1;
    //              if ((rr, cc) = (dR, dC)) { 
    //                  found = true; break; }   // found the destination
    //              addq(rr, cc);
    //          }
    //        }
    //      }
    // 4. 만일 Q에 여전히 뭔가 남아 있을 경우 deleteq를 호출하여 front가 NULL이 되도록 모두 비운다.
    // 5. if(found==false) return(UNVISITED); // 경로가 없다(그러나 우리의 입력은 항상 경로가 있다
    // 6. back tracing 단계 (pseudo code)
    //      r = dR, c = dC;     // destination position 부터 체크
    //      maze(r, c) = 'T';   // maze에 경로 표시
    //      d = distance = mark(dR, dC);
    //      while (r != sR || c != sC) { // starting position에 도착할 때까지 반복
    //        if((r,c)=(sR,sC)) {
    //          maze(r,c) = 'S'; break;
    //        }
    //        좌상우하의 순서로(r, c) 주변 유효한 cell을 다음과 같이 차례로 조사한다 
    //          (반드시 좌상우하여야 함(채점을 위한 이유))
    //        (rr, cc)를 현재 조사하는 (r,c)의 주변 cell이라고 하자;
    //          if (mark(rr, cc) == d - 1) { 
    //            maze(rr, cc) = '*'; d = d - 1;
    //            나머지 cell에 대한 조사는 skip하고 r = rr, c = cc로 바꾸고 tracing 계속; // 즉, if, else if 사용
    //          }
    //        만일 주변 cell을 모두 조사했는데고 mark 값이 d-1인 cell을 못찾는다면 경로를 프로그램에
    //          오류가 있는 것이다(앞에 maze propagation단계에서 destination cell에 도달했으므로)
    //      }
    // 7. 이제 배열 maze에 경로가 '*'로 표시되었다. return distance;
    //

    int distance = 0;

    // 이 함수를 작성하세요
 
    return distance;
}
