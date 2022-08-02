// 14-2. 포인터 배열

/*

    확인 문제 1. 다음 5개의 문자열 상수를 저장하기 위한 포인터 배열을 선언하고 초기화하세요.

        "apple", "pear", "peach", "banana", "melon"

        char *pary[5] = { "apple", "pear", "peach", "banana", "melon" };

    
    확인 문제 2. 다음 프로그램의 실행결과를 적어 보세요.

        hope

    확인 문제 3. 다음과 같은 코드가 있을 때 보기 중에서 배열 요소 사용이 잘못된 것을 고르세요.

        char *pa = "apple";
        char ary[] = "banana";
        char *pary[4];

        (1) pary[1] = pa;
        (2) pary[2] = ary;
        (3) pary[3] = "mango";
        (4) pary[4] = "orange";
            // pary의 첨자는 0~3까지 사용 가능하므로, 4를 쓰면 안 됩니다

        
