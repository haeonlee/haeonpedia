// 18-9. 다양한 자료형을 형식에 맞게 입출력

/*

    fscanf 함수: 파일에 저장된 문자열을 숫자로 변환하여 입력할 때

        fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);

        txt 파일에 있는 데이터를 서로 다른 자료형에 저장하려고 하면 일이 복잡합니다.
        txt 파일 안 자료는 모두 '문자열'로 저장돼 있습니다.
        전체 문자열을 각 데이터 형태에 따라 변환하는 작업을 해 주는 것이 바로 fscanf 함수입니다.

        fsacnf 함수는 파일 데이터를 모두 읽으면 EOF를 반환합니다.


    fprintf 함수: 정수나 실수를 쉽게 파일에 출력할 때

        fprintf 함수는 각 변수의 데이터를 모두 문자열로 변환하여 파일에 출력합니다.
        fprintf 함수는 출력한 문자의 바이트 수를 반환하며,
        출력 과정에서 오류가 발생하면 음수를 반환합니다.

*/

/*

    a.txt

    소원 95 99 96
    유주 80 85 94
    신비 92 76 93

*/

#include <stdio.h>

int main(void)
{
    FILE *ifp, *ofp;
    char name[20];
    int kor, eng, math;
    int total;
    double avg;
    int res;

    ifp = fopen("a.txt", "r");      // 입력 파일을 읽기 전용으로 개방
    if (ifp == NULL)                // 개방 여부 확인
    {
        printf("입력 파일을 열지 못했습니다.\n");
        return 1;
    }

    ofp = fopen("b.txt", "w");      // 출력 파일을 쓰기 전용으로 개방
    if (ofp == NULL)                // 개방 여부 확인
    {
        printf("출력 파일을 열지 못했습니다.\n");
        return 1;
    }

    while (1)
    {
        res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);     // 데이터 입력
        if (res == EOF)     // 파일의 데이터를 모두 읽으면 EOF 반환
        {
            break;
        }
        total = kor + eng + math;
        avg = total / 3.0;
        fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}

/* 실행 결과

소원  290   96.7
유주  259   86.3
신비  261   87.0

*/