// 19-2. 분할 컴파일

/*

    1. 다음 2개의 파일로 분할 컴파일된 프로그램의 실행결과를 적어보세요.

        // main.c

        #include <stdio.h>

        extern void set_key(int);
        extern int get_key(void);
        int key;

        int main(void)
        {
            int res;
            set_key(10);
            key = get_key();        // 10 반환하여 key에 10 저장
            set_key(20);            // 
            res = key + get_key();  // 10 + 20
            printf("%d", res);
            return 0;
        }


        // sub.c

        static int key;
        void set_key(int val)
        {
            key = val;
        }
        int get_key(void)
        {
            return key;
        }

        
        내 답안
        30


    2. 다음 중 extern과 static을 사용한 전역 변수에 대한 설명 중 옳지 않은 것을 고르세요.

        (1) static을 쓰면 둘 이상 파일에서 같은 이름의 전역 변수를 각각 선언할 수 있다.
        (2) static을 사용한 전역 변수를 다른 파일에서 extern 선언으로 공유할 수 있다.
        (3) extern 선언은 중복이 가능하므로 헤더 파일에 넣어 사용하는 것이 좋다.
        (4) 다른 파일에 있는 static 전역 변수를 공유할 때는 static 선언이 필요하다.

        내 답안
        (2) static을 사용한 전역 변수를 다른 파일에서 extern 선언으로 공유할 수 있다.
            -> static 쓰면 공유 안 하고 쓰겠다는 소리임
        (4) 다른 파일에 있는 static 전역 변수를 공유할 때는 static 선언이 필요하다.
            -> static 전역 변수를 어케 씀? 뭔 수를 써도 못 쓴다

        답안
        (4) static 전역 변수의 사용 범위는 파일로 제한되므로 다른 파일에서 공유할 수 없습니다.

    

    3. 다음 중 사용자 정의 헤더 파일의 내용으로 적합하지 않은 것을 고르세요.

        (1) 매크로 함수 정의
        #define FUNC(x, y, z) (((x) * (y)) / (z))

        (2) 구조체 선언
        struct robot
        {
            char skill[20];
            int energy;
        };

        (3) 전역 변수 선언과 초기화
        int key_flag = 0;

        (4) 함수 선언
        int input_data_from_file(void);


        내 답안
        (1) 매크로 함수 정의
        #define FUNC(x, y, z) (((x) * (y)) / (z))
        -> 헤더 파일에 매크로 함수를 쓰나? 솔직히 이건 잘 모르겟음

        답지
        (3) 전역 변수 선언과 초기화
        초기화된 전역 변수의 선언은 헤더 파일이 여러 파일에 인클루드되었을 때
        전역 변수의 중복 문제가 발생합니다.

*/