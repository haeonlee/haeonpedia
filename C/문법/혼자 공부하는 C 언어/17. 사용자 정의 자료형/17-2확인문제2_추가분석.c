// p.510 참고
/*
    처음엔 이해가 안 됐는데 의문점을 정리하며, 코드를 뚫어져라 쳐다보니까 이해가 됐다.
*/

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
        // 이렇게 되면 head, tail이 같아지면서 한 개의 구조체를 형성하게 된다.

        else
        {
            tail->next = (Train *)malloc(sizeof(Train));
            tail = tail->next

            // head는 첫 구조체를 그대로 가리키고 있고, tail만 움직이면서 구조체를 계속 생성한다(5회 반복)
            // 그리고 tail = tail->next 가 되어서 다음 tail로 이동한다.
            
            /* 해석: tail 포인터가 항상 연결 리스트의 마지막 위치를 기억하도록
            새로운 구조체 변수를 연결한 후에는 tail의 값을 마지막 위치로 바꿉니다. */
        }
    }
}

