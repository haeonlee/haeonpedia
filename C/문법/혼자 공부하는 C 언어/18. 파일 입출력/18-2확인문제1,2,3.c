// 18-2. 다양한 파일 입출력 함수

/*

    확인 문제 1. 다음 파일 입출력 함수 중에서 반환값의 형태가 다른 함수를 고르세요.

        반환값이 기억이 안 나서 그냥, 개념 정리를 보면서 쭉 정리했다.
        
        답지
        (3) 나머지 함수는 반환값의 형태가 모두 int형이며, fgets 함수는 char *형입니다.

        (1) fgetc
            반환값: 입력한 문자, 오류나 파일에 데이터가 없다면 EOF

        (2) fputc
            반환값: 출력한 문자, 오류가 발생한 경우 EOF

        (3) fgets
            반환값: 입력한 char 배열, 파일의 끝이면 NULL

        (4) fputs
            반환값: 출력에 성공하면 음수가 아닌 값, 실패하면 EOF

        (5) fscanf
            반환값: 입력에 성공한 데이터 수, 파일에 데이터가 없을 때 EOF
            
        (6) fprintf
            반환값: 출력한 문자의 바이트 수, 실패하면 음수


    확인 문제 2. 다음 코드와 실행결과가 같은 함수 호출을 고르세요.

        char str[5];
        char ch;
        int i = 0;
        ch = fgetc(stdin);
        while ((i < (sizeof(str) - 1)) && ((ch != '\n'))    // 데이터 갯수만큼 받음, 개행 문자 입력하면 바로 짤
        {
            str[i++] = ch;  
            ch = fgetc(stdin);
        }
        if (i < (sizeof(str) - 1)) str[i++] = ch;   // 
        str[i] = '\0';  // 마지막에 널 문자 추가

        내 답안
        (2) fgets(str, sizeof(str), stdin);

        답지
        (2) fgets(str, sizeof(str), stdin);
        키보드로 입력한 한 줄의 데이터를 개행문자까지 배열에 저장하므로 fgets 함수의 기능을 구현한 코드입니다.
        단, 파일 포인터는 stdin을 사용합니다.

    
    확인 문제 3. 다음 프로그램의 실행결과를 적어보세요. 파일을 개방할 때 실패하지 않는다고 가정합시다.
               a.txt 파일은 다음과 같습니다.

               a.txt
               a mango
               an apple

        
        #include <stdio.h>

        int main(void)
        {
            FILE *fp;                   // 파일 포인터
            char str[20] = "empty";     // 문자열 입력 배열
            int ch;                     // 문자 입력 변수

            fp = fopen("a.txt", "r");   // 파일 개방
            ch = fgetc(fp);             // 문자 입력
            while (fgetc(fp) != EOF);   // 버퍼 비움

            fgets(str, sizeof(str), fp);    // 한 줄 입력
            printf("%s", str);          // 출력
            fclose(fp);                 // 파일 닫음

            return 0;
        }


        내 답안
        an apple
        fgetc가 개행문자 전까지만 읽고, 종료하지 않을까 생각했고
        이후 fgets가 다음 줄을 읽을 것이라고 생각함...
        (지금 생각하면 왜 이렇게 생각했나 싶음)

        답지
        empty
        처음 fgetc 함수가 호출될 때 파일의 데이터가 작으므로 모든 데이터가 버퍼로 입력됩니다.
        이어서 fgetc 함수를 반복 호출하여 버퍼의 모든 내용을 지웁니다.
        따라서 이후 호출되는 fgets 함수는 입력할 데이터가 없습니다.
        결국 fgets 함수는 널 포인터를 반환하며,
        str 배열의 초깃값 empty가 그대로 출력됩니다.

*/