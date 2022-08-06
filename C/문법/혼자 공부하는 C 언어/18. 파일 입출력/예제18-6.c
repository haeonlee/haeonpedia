// 18-6. 파일의 형태와 개방 모드가 다른 경우

/*

    텍스트 파일과 바이너리 파일

        파일은 데이터의 기록 방식에 따라
        텍스트(text) 파일과 바이너리(binary) 파일로 나눕니다.

        (1) 텍스트 파일: 데이터를 아스키 코드 값에 따라 저장
            아스키 코드 값에 따라 데이터를 읽고 저장하는 메모장 같은 프로그램에서 확인 가능
            e.g. txt 파일

        (2) 바이너리 파일: 그 이외의 방식으로 저장
            바이너리 파일은 해당 기록 방식을 적용한 별도의 프로그램을 사용해야 함
            e.g. 그림판 프로그램

        따라서 파일을 개방할 때 개방 모드에 파일의 형태도 함께 표시해야 합니다.


    개방 모드에 파일 형태를 함께 표기하기

        (1) 텍스트 파일: 텍스트 파일은 t를 추가하여 개방합니다

        개방 모드       파일의 용도
        rt          텍스트 파일을 읽기 위해 개방
        wt          텍스트 파일을 쓰기 위해 개방
        at          텍스트 파일의 끝에 추가하기 위해 개방


        (2) 바이너리 파일: 바이너리 파일은 b를 추가하여 개방합니다

        개방 모드       파일의 용도
        rb          텍스트 파일을 읽기 위해 개방
        wb          텍스트 파일을 쓰기 위해 개방
        ab          텍스트 파일의 끝에 추가하기 위해 개방

*/