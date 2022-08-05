// 17-2. 구조체 활용, 공용체, 열거형

/*

    확인 문제 1. 다음과 같이 구조체 변수와 구조체 포인터를 선언했을 때, mp를 사용하여 m1에 저장된 값을 출력하세요.
    멤버를 참조할 땐 -> 연산자를 사용합니다.

        struct marriage
        {
            char name[20];
            int age;
            char sex;
            double height;
        };

        struct marriage m1 = { "Andy", 22, 'm', 187.5 };
        struct marriage *mp = &m1;

        printf("이름 : %s\n", mp->name);
        printf("나이 : %d\n", mp->age);
        printf("성별 : %c\n", mp->sex);
        printf("키 : %0.1lf", mp->height);

        return 0;


    2. 다음과 같이 연결 리스트를 만들 수 있도록 코드의 빈칸을 채웁시다.

        #include <stdio.h>
        #include <stdlib.h>

        typedef struct train Train;

        struct train
        {
            int seat;
            Train *next;
        };

        int main(void)
        {
            Train *head = NULL, *tail = NULL;
            int i;
            for (i = 0; i < 5; i++)
            {
                if (head = NULL)
                {
                    head = tail = (Train *)malloc(sizeof(Train));
                }
                else
                {
                    tail->next = (Train *)malloc(sizeof(Train));
                    (2)
                    
                    // 내 답안: head->next = (Train *)malloc(sizeof(Train));
                    // 실제 답안: tail = tail->next;
                    tail 포인터가 항상 연결 리스트의 마지막 위치를 기억하도록
                    새로운 구조체 변수를 연결한 후에는 tail의 값을 마지막 위치로 바꿉니다.
                }
            }
        }

        이 문제는 이해가 안 됨... 연결 리스트 더 공부하고 다시 봐야할 것 같음.


    3. 다음 프로그램의 실행 결과를 예상해보겠습니다.

        #include <stdio.h>

        typedef enum { CYAN, MAGENTA, YELLOW = 5, BLACK } COLOR;
        typedef enum { UP, DOWN, LEFT, RIGHT } ARROW;

        int main(void)
        {
            COLOR my_color = YELLOW, c;
            ARROW direction = UP;

            for (c = CYAN; c <= BLACK; c++) // 0 1 2 3 4 5(MY COLOR) 6
            {
                
                direction++                 // 1 2 3 4 5 6 7
                direction = direction % 4;  // 1 2 3 0 1 2 3
                if ( c == my_color ) break; // 
            }

            switch (direction) // 2, DOWN
            {
                case UP: printf("현재 방향 : 위"); break;
                case DOWN: printf("현재 방향 : 아래"); break;
                case LEFT: printf("현재 방향 : 왼쪽"); break;
                case RIGHT: printf("현재 방향 : 오른쪽"); break;
            }

            return 0;
        }

        내 답안:
            현재 방향 : 왼쪽
*/

