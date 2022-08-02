// 10-2. 배열을 처리하는 함수

/* 1. 다음과 같이 선언된 함수가 있을 때 함수의 호출이 적합하지 않은 것을 고르세요.

    void func(int *p);
    // 매개변수로 주소값을 전달해 주어야 함

    (1) int ary[5];
        func(ary);
        // [] 없이 배열명만 딸랑 쓴 건 주솟값이므로 맞음
    
    (2) int ary[] = { 1, 2, 3 }
        func(ary);

    (3) double ary[5];
        func(ary); 
        // ary 배열은 double형인데, 매개변수는 int형이라 안 돼요
    
    (4) int ary[5];
        func(ary + 2);

*/

/*
    2. 다음은 각 달의 일수를 저장한 배열입니다.
       month[0]은 1월이며, 첨자가 순차적으로 증가할 때 월도 함께 증가합니다.
       month 배열의 값을 한 줄에 5개씩 출력하는 함수를 만들어 보세요.

    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    void print_month(int *mp)
    {
        int i;
        for (i = 0; i < 12; i++)
        {
            printf("%5d", mp[i]);
            if (((i+1)%5) == 0) printf("\n");
        }
    }

*/