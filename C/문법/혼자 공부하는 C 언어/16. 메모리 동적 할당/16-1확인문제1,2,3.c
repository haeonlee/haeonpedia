// 16-1. 동적 할당 함수

/*

    확인 문제 1. 다음 용도에 맞게 저장 공간을 동적 할당하여 각 포인터에 연결합니다.

        (1) 몸무게를 저장할 변수
            double *weight = (double *)malloc(sizeof(double));
        
        (2) 열 과목의 점수를 저장할 배열
            int *scores = (int *)calloc(10, sizeof(int));
            답지: int *scores = (int *)malloc(10 * sizeof(int));

        (3) 널 문자를 포함하여 최대 80글자의 문자열을 저장할 char 배열
            char *string = (char *)calloc(80, sizeof(char));
            답지 : char *string = (char *)calloc(80 * sizeof(char));

    
    확인 문제 2. 다음은 동적 할당이 제대로 되었는지 검사하고 사용이 끝난 동적 할당 영역을 반환하도록
        빈칸을 채워보겠습니다.

        int *max = (int *)malloc(sizeof(int));
        if ( max == NULL )      // 솔직히 여기서 *max인지, max인지 헷갈림
                                // max == NULL 또는 max == 0이 정답
        {
            printf("메모리가 부족합니다.")
            return 1;           // 정상 종료는 0, 예외 상황 종료는 1
        }
        *max = 999;
        free(max);

    
    확인 문제 3. 다음 코드에서 pa, pb, pc 중 동적 할당 영역의 크기가 가장 큰 것을 고르세요/

        int ary[5] = { 1, 2, 3, 4, 5 };
        int *pa, *pb, *pc;
        int i;
        pa = (int *)malloc(sizeof(ary));    // 4바이트 * 5개 = 20바이트

        for ( i = 0; i < 5; i++ )
        {
            pa[i] = ary[i];
        }

        pb = (int *)calloc(pa[3], sizeof(int));     // 4개 *4바이트 = 16바이트
        pc = (int *)realloc(NULL, pa[4]);  // NULL을 어케 크기 조절함? 이건 모르겠음...
        

        pc = (int *)realloc(NULL, pa[4]);
        인 경우는

        답지: realloc 함수의 첫 번째 인수가 NULL인 경우, 두 번째 인수의 바이트 크기만큼 동적 할당
        따라서 pa[4]인 5바이트만큼 할당


*/