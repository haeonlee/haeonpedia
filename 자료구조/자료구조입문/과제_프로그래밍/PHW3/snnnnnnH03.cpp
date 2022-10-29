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
    
    // 이 함수를 완성하세요.

    queuePtr tmp;

    MALLOC(tmp, queuePtr, sizeof(queue));

    tmp->row = r;
    tmp->col = c;
    tmp->p = NULL;

    if (front)
        rear->p = tmp;
    else
        front = tmp;
    
    rear = tmp;

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
    *r = tmp->row;      // delete된 r과 c를 pointer 이용해서 r, c 변수에 저장했다는 소리
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

    // 이 함수를 완성하세요.

    char** maze = NULL;

    // 1. 미로 크기를 나타내는 width C와 height R을 scanf()를 사용하여 입력받습니다.

    int C, R;           // width(C)와 height(R)를 입력할 변수 선언

    scanf("%d", &C);    // width(C) 입력
    scanf("%d", &R);    // height(R) 입력

    // 2. 실제 maze의 크기를 뜻하는 Cm, Rm의 값을 계산하여, pointer를 통해 초기화합니다.

    *Cm = (2 * C) + 1;
    *Rm = (2 * R) + 1;

    // 3. 시작점(전역변수 sR, sC)과 도착점(전역변수 dR, dC)의 값을 초기화합니다.

    sC = 1;
    sR = 1;

    dC = (*Cm) - 2;
    dR = (*Rm) - 2;

    // 4. maze 배열을 row 개수 = Rm, column 개수는 = Cm + 2로 allocate합니다.
    //    allocSize와 allocSizeMax를 이 작업 중에 갱신합니다.

    char** maze;

    MALLOC(maze, char**, (*Rm) * sizeof(char*));
    allocSize += (*Rm) * sizeof(char*);

    for (int r = 0; r < (*Rm); r++) {
        MALLOC(maze[r], char*, ((*Cm) + 2 ) * sizeof(char)); 
        allocSize += ( (*Cm) + 2 ) * sizeof(char);
    }

    allocSizeMax = MAX2(allocSizeMax, allocSize);

    // 5. 크기가 최소 2 이상인('\n'과 '\0' 저장용) 버퍼를 static으로 선언하고, fgets를 이 버퍼를 사용해 호출합니다.
    //    이 버퍼는 input size에 무관하므로 allocSize에 포함하지 않습니다. 

    static char temp_buffer[2];

    fgets(temp_buffer, 2, stdin);

    // 6. fgets(buffer, max_size, FILE)로 미로 데이터를 읽는 작업을 합니다.

    for (int r = 0; r < (*Rm); r++) {
        fgets(maze[r], ((*Cm) + 2), stdin);
    }
    
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

    // 이 함수를 작성하세요

    int distance = 0;

    // 1. wave propagation 단계

    // (1) 탐색에 앞서 필요한 준비사항을 하는 과정입니다.
    
    bool found = false;
    
    front = NULL;           // Queue는 empty한 상태
    addq(sR, sC);           // Queue에 starting point를 넣습니다.
    mark[sR][sC] = 0;       // starting point의 mark는 0입니다.
    int r, c, rr, cc;       // 좌상우하의 순서로 미로를 탐색할 때 사용할 변수

    // 좌상우하 순서로 탐색하기 위해 구조체 offsets를 선언하여, 좌상우하 순서로 정렬합니다.

    typedef struct _offsets{
        int v;
        int h;
    } offsets;

    offsets move[4] = {
        {0, -1}, {-1, 0}, {0, 1}, {1, 0}
    };

    // (2) wave propagation 단계를 queue(FIFO)로 구현합니다.

    while (front != NULL)   // Q가 비워져 있지 않다면, 아래 사항을 반복합니다.
    {
        deleteq(&r, &c);    // Queue에서 row와 column을 delete
                            // 이렇게 하면, pointer를 통해 r과 c의 값이 바뀝니다.
                            // 즉, Queue에서 숫자를 하나씩 뺄 때마다 그 숫자를 사용할 수 있다는 말입니다.

        int p = mark[r][c];

        for (int d = 0; d < 4; d++)     // move 배열을 활용해 좌상우하 순서로 미로를 탐색합니다.
        {
            rr = r + move[d].v;
            cc = c + move[d].h;

            // 주변 셀 중 maze 값이 빈칸이고, Mark 값이 unvisted일 때
            if ((maze[rr][cc] == ' ') && (mark[rr][cc] == UNVISITED) )
            {
                mark[rr][cc] == p + 1;          // mark 값을 p+1로 업데이트합니다.
                if ((rr, cc) = (dR, dC)) {      // 만약, 과정 중 목적지에 도착하면
                    found = true;               // found 값을 true로 바꾸고,
                    break;                      // 반복문을 멈춥니다.
                }
                addq(rr, cc);               // 해당 셀을 queue에 넣습니다.
            }
        }
    }

    // 2. 예외 처리

    // (1) Q에 여전히 뭔가 남아 있다면, deleteq를 호출하여 front가 NULL이 되도록 모두 비웁니다.

    while(front!=NULL)
    {
        deleteq(&r, &c);
    }

    // (2) 경로가 없는 경우엔 UNVISITED를 반환합니다.
    //     하지만, 우리의 입력은 오류가 없다고 가정하므로, 항상 경로가 있습니다.

    if (found == false)
        return(UNVISITED); 

    // 3. back tracing 단계

    // (1) back tracing 앞서 필요한 준비사항을 하는 과정입니다.

    distance = mark[dR][dC];    // 도착점의 mark 값을 distance로 저장합니다.
    maze[dR][dC] = 'T';         // maze에서 도착점을 'T'로 바꿉니다.
    (r, c) = (dR, dC);          // 변수 r과 c는 도착점 T로 설정합니다.
    int pp = distance;          // 추후에 back tracing 과정에서 사용할 변수

    // (2) starting position에 도착할 때까지 back tracing 과정을 합니다.

    while (1)
    {
        if ((r, c) = (sR, sC))  // 만약, 과정 중 시작점에 도착하면
        {
            maze[r][c] = 'S';   // 시작점을 'S'로 설정하고
            break;              // loop를 종료합니다.
        }

        for (int d = 0; d < 4; d++)     // move 배열을 활용해 좌상우하 순서로 미로를 탐색합니다.
        {
            rr = r + move[d].v;
            cc = c + move[d].h;

            // 주변 셀 중에서 mark 값이 pp보다 1 작은 셀을 발견하면
            if (mark[rr][cc] == pp - 1)
            {
                maze[rr][cc] = '*';     // 발견한 셀의 maze 값을 '*'로 변경
                pp = pp - 1;            // pp의 값도 pp-1로 변경
                r = rr;                 
                c = cc;                 // r = rr, c = cc로 변경
                break;                  // break문을 활용해 나머지 cell에 대한 조사는 skip
            }
        }
    }

    return distance;
}
