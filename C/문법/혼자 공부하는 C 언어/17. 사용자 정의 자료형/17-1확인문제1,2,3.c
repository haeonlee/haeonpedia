// 17-1. 구조체

/*

    확인 문제 1. 도서명(title), 저자(author), 페이지수(page), 가격(price)을
    멤버로 가지는 book 구조체를 선언해보세요.

        struct book {
            char title[80];
            char author[20];
            int page;
            double price;
        };

    확인 문제 2. 크래커의 가격(price)와 열량(calories)을 저장할 cracker 구조체를 선언합니다.
    만든 구조체를 변수로 선언하고 가격과 열량을 키보드로 입력한 후에 화면으로 출력하는 프로그램을 작성하세요.

        #include <stdio.h>

        struct cracker {
            int price;
            int calories;
        };

        int main(void)
        {
            struct cracker ba;

            printf("바사삭의 가격과 열량을 입력하세요 : ");
            scanf("%d %d", &(ba.price), &(ba.calories));
            
            printf("바사삭의 가격 : %d원\n", ba.price);
            printf("바사삭의 열량 : %dkcal", ba.calories);

            return 0;
        }

    확인 문제 3. 다음과 같이 구조체가 선언되어 있을 때, 잘못 사용한 것을 찾아 이유를 적어보세요.

        struct profile
        {
            int num;
            char name[20];
            char *skill;
        };

        struct sports
        {
            char *event;
            struct profile player;
        };

        struct sprots a;

        내 답안
        (1) strcpy(a.event. "figure skating");
        a.event는 포인터 변수이므로, "figure skating"을 직접 입력 받을 순 없어요.
        얘랑 배열이랑 연결해서 배열에 문자를 입력해야 해요.
        (또는 동적 할당을 해서 미리 복사 받을 공간을 확보해야 합니다.)

        (2) a.player.name = "Yuni Seo";
        얘는 잘 썼어용.

        (3) a.num = "19";
        a.player.num으로 사용해야 해요.

        (4) scanf("%s", a.player.skill);
        a.player.sill은 포인터 변수이므로, 문자를 직접 입력 받을 순 없어요.
        얘랑 배열이랑 연결해서 배열에 문자를 입력해야 해요.


        실제 답지
        
        (1) strcpy(a.event. "figure skating");
        strcpy 함수는 첫 번째 인수로 받은 주소에 문자열을 복사하므로,
        event에 복사 받을 공간을 먼저 확보해야 해요.

            a.event = (char *)malloc(80);
            strcpy(a.event, "figure skating");

        (2) a.player.name = "Yuni Seo";

            name은 배열명으로 주소 상수이므로 대입 연산자 왼쪽에 올 수 없습니다.
            strcpy(a.player.name, "Yuni Seo")
            와 같이 함수를 사용하는 것이 적절함.

        (3) a.num = "19";

            num은 struct profile의 멤버이므로
            a.player.num과 같이 접근해야 합니다.
       

        (4) scanf("%s", a.player.skill);

            skill도 포인터이므로 입력한 문자열을 저장할 공간을 먼저 확보한 후에 입력해야 합니다.
        

    
*/

