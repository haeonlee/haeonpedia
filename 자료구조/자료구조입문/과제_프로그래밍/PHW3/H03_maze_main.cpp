#include "H03_maze.h"

queuePtr front, rear;
int sR = 1, sC = 1;     // starting position (fixed)
int dR, dC;         
int allocSize;      
int allocSizeMax;   

int main(void) {
    int T;          // 테스트 케이스의 숫자
    int Rm, Cm;     // 미로 사이즈 (Cm: width, 2C+1) (Rm:height, 2R + 1)
    char** maze;    // maze: Rm X (Cm+2) - 왜냐하면, fgets() 함수가 '\n' '\0' 를 뒤에 붙여서
                    // 입력 및 결과 경로 저장
    int**  mark;    // mark: Rm X Cm
                    // starting position부터 특정 점까지 distance를 저장
    int distance;   // distance from the start to destination

    front = NULL;

    // 입력 값엔 오류가 없다고 가정
    scanf("%d", &T);    // test case를 몇 번 할 건지 입력

    for (int t = 1; t <= T; t++) {      // 테스트 갯수만큼 반복
        allocSize = allocSizeMax = 0;   // allocSize, allocSizeMax를 모두 0으로 초기화

        maze = readMaze(&Rm, &Cm);      // 과제
        
            // 1. Rm 및 Cm의 값을 지정: 목적지 (dR, dC)로 설정 가능
            // 2. pointer로 변수 Rm과 Cm 값을 바꾸기
            // 3. 미로 사이즈만큼 동적 메모리 allocate
            // 4. allocSize를 누적, 그리고 allocSizeMax를 update
            // 5. 미로 정보 읽기
            // 6. return char**형으로 maze pointer

        mark = allocMark(Rm, Cm);       // main 함수에 제시

            // 1. mark 배열 사이즈만큼 동적 메모리 allocate
            // 2. UNVISITED (-1)은 아직 방문하지 않았고, start position으로부터 무한 거리
            // 3. allocSize를 누적, 그리고 allocSizeMax를 update
            // 4. return int**형으로 mark pointer

        // printMaze(maze, Rm, Cm, t, 0, false);
        // 미로를 읽는 것이 괜찮은지 확인하기 위해 위 코드 활성화 가능

        distance = findShortest(maze, mark, Rm, Cm);    // 과제

            // 1. 미로 전파(maze propagation): (1,1)=(sR,sC)에서 출발해서 (dR, dC)까지 이동하며 mark
            // (dR, dC)에 도착하면 멈춤
            // 2. return (sR,sC)부터 (dR,dC)까지의 거리

        if(t==T)
            printMaze(maze, Rm, Cm, t, distance, true);
        else
            printMaze(maze, Rm, Cm, t, distance, false);

        freeMaze(&maze, &mark, Rm, Cm);
            // 1. free arrays maze and mark
            // 2. alloSize를 수정

        if (allocSize != 0) {
            printf("Error: allocSize != 0\n");
        }
    }
}

int** allocMark(int Rm, int Cm) {
    int** mark;

    // allocate 2-d int array of size Rm X Cm

    MALLOC(mark, int**, Rm * sizeof(int*));     // allocate row pointer array
    allocSize += Rm * sizeof(int*);

    for (int r = 0; r < Rm; r++) {
        MALLOC(mark[r], int*, Cm * sizeof(int));    // allocate each row
        allocSize += Cm * sizeof(int);

        for (int c = 0; c < Cm; c++) {
            mark[r][c] = UNVISITED;     // mark every position UNVISITED
        }
    }
    allocSizeMax = MAX2(allocSizeMax, allocSize);   // adjust maximum allocated memory
    return mark;
}

void freeMaze(char ***maze, int ***mark, int Rm, int Cm) {
    // maze and mark are 2-d array pointers(**maze, **mark) pointers.
    // that why prefixed three stars

    // free arrays maze and mark
    for (int r = 0; r < Rm; r++) {
        free((*maze)[r]);                   // free each row
        allocSize -= (Cm + 2) * sizeof(char);   

        free((*mark)[r]);                   // free eaxh row
        allocSize -= Cm * sizeof(int);          
    }

    free(*maze);                // free row pointers array
    allocSize -= Rm * sizeof(char*);
    *maze = NULL;

    free(*mark);
    allocSize -= Rm * sizeof(int*);   // free row pointers array
    *mark = NULL;
}

void printMaze(char **maze, int Rm, int Cm, int t, int distance, bool lastFlag) {
    // output the maze & path found if exists
    printf("T%d (w,h)=(%d, %d), distance = %d, mem used = %d bytes)\n", t, Cm, Rm, distance, allocSizeMax);
    for (int r = 0; r < Rm; r++) {
        fputs(maze[r], stdout);
    }
    if(!lastFlag)
        printf("\n");
}

void printMark(int** mark, int Rm, int Cm) { // one can call this function to check
    for (int r = 0; r < Rm; r++) {           // the propagation results
        for (int c = 0; c < Cm; c++) {
            printf("%4d", mark[r][c]);
        }
        printf("\n");
    }
}
