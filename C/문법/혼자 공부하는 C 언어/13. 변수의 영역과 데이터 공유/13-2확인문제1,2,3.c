// 13-2. 함수의 데이터 공유 방법

/*

    확인문제1. 함수 원형과 데이터 공유 방법이 일치하도록 연결하세요.

    void swap(int *pa, int *pb); : 주소를 전달하는 방법
    double avg(int a, int b); : 값을 복사해서 전달하는 방법
    char *get_str(void); : 주소를 반환하는 방법


    확인문제2. 다음은 키보드로부터 정수를 입력받은 후에 값이 저장된 변수의 주소를 반환하는 함수입니다.
             구현에 문제가 있는 부분을 찾고 그 이유를 적어보세요.

        int *get_num(void)
        {
            int n; // 문제 발생: 일반 지역 변수는 함수가 반환되면, 저장 공간이 회수되므로 주솟값을 주나 마나
            scanf("%d", &n);
            return &n;
        }


    확인문제3. 다음 프로그램의 실행결과가 30이 되도록 빈칸에 알맞은 수식을 작성하세요.

        #include <stdio.h>

        void add_by_pointer(int *pa, int *pb, int *pr)
        {
            *pr = *pa + *pb
        }

        int main(void)
        {
            int a = 10, b = 20, res = 0;
            add_by_pointer(&a, &b, &res);
            printf(%d, res);
            return 0;
        }

*/

