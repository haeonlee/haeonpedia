// 12-2. 문자열 연산 함수

/*
    확인 문제

    1. 다음 중 문자열 함수의 사용법이 잘못된 것을 모두 고르세요.

    char str[] = "lion";
    char *ps = "king";

    내 정답: (2), (5)
    실제 정답: (2), (5), (6)

    (6) strncpy(ps, str, strlen(str));
    ps가 연결하고 있는 문자열 상수는 바꿔서는 안 됩니다.

    -

    (1) strcpy(str, "cat");
    str 크기 안에 cat이 쏙 들어가므로, 얘는 잘했어요.

    (2) strcat(str, ps);
    str 크기 안에 ps를 넣으면 초과돼서 얘는 안 돼요.

    (3) strcmp(ps, str);
    괜찮아요.

    (4) strlen(ps);
    괜찮아요.

    (5) strcat("cute", str);
    strcat의 첫 번째 인수는 배열이어야 해요. 이렇게 문자열 상수 넣으면 안 됨. 문자열 상수는 수정할 수 없으니까.
    답지 설명: cute 뒤에 str을 붙여넣을 공간이 없어요.

    (6) strncpy(ps, str, strlen(str));
    괜찮아요.


    2. 다음 프로그램의 실행결과를 적어 보겠습니다.

        실행 결과
        wine
        wineapple
        pineapple
        pineapple, 9

*/