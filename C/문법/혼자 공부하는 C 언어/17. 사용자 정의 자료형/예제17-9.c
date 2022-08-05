// 17-9. 자기 참조 구조체로 list 만들기

/*

    자기 참조 구조체: 자신의 구조체를 가리키는 포인터를 멤버로 가지는 구조체

        개별적으로 할당된 구조체 변수들을 포인터로 연결하면, 관련 데이터를 하나로 묶어 관리할 수 있습니다.
        이때 자기 참조 구조체를 사용합니다.

    연결 리스트(linked list)

        구조체 변수를 포인터로 연결한 것을 연결 리스트라고 합니다.
        연결 리스트(또는 링크드 리스트)는 첫 번째 변수의 위치만 알면,
        나머지 변수는 포인터를 따라가 모두 사용할 수 있으므로,
        대부분 첫 번째 변수 위치를 head 포인터에 저장해 사용합니다.

*/

#include <stdio.h>

struct list             // 자기 참조 구조체
{
    int num;            // 데이터를 저장하는 멤버
    struct list *next;  // 구조체 자신을 가리키는 포인터 멤버
                        // 따라서 struct list 구조체 변수는 next 멤버로 다른 변수를 가리킬 수 있음
};

int main(void)
{
    struct list a = {10, 0}, b = {20, 0}, c = {30, 0};  // 구조체 변수 초기화
    struct list *head = &a, *current;                   // 헤드 포인터 초기화

    a.next = &b;    // a의 포인터 멤버가 b를 가리킴
    b.next = &c;    // b의 포인터 멤버가 c를 가리킴

    printf("head -> num : %d\n", head -> num);  // head가 가리키는 a의 num 멤버 사용
    printf("head -> next -> num : %d\n", head->next->num);  // head로 b의 num 멤버 사용

    printf("list all : ");
    current = head;     // 최초의 current 포인터가 a를 가리킴
    while (current != NULL)
    {
        printf("%d  ", current->num);   // current가 가리키는 구조체 변수의 num 출력
        current = current->next;        // current가 다음 구조체 변수를 가리키도록 함
    }
    printf("\n");

    return 0;
}  

/* 실행 결과

head -> num : 10
head -> next -> num : 20
list all : 10  20  30  

*/