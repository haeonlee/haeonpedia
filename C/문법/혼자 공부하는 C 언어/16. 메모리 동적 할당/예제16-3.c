// 16-3. calloc, realloc 함수를 사용한 양수 입력

/*

    기타 동적 할당 함수

        calloc 함수: 할당한 저장 공간을 0으로 초기화
            메모리를 동적으로 할당하여 0으로 초기화된 메모리 공간을 얻고자 할 때 사용

            calloc 함수의 원형
                void *calloc(unsigned int count, unsigned int size);
                (count * size) 바이트 수만큼 할당하고 0으로 초기화 후 시작 위치 반환

                반환 값의 형태: void *

            calloc 함수의 사용
                double *pd;
                pd = (double *)calloc(5, sizeof(double));
                해석: pd = (double *)calloc(배열 요소의 개수, double형 변수 하나의 바이트 크기);
                

        realloc 함수: 할당한 저장 공간의 크기를 조절
            메모리를 동적 할당할 때는 대부분 입력되는 데이터에 맞게 저장 공간을 확보
            그러나 사용하다보면 처음에 예측한 크기가 너무 크거나 작을 수 있으므로,
            이때는 realloc 함수로 저장 공간의 크기를 조절함
            저장 공간을 늘리는 경우, 이미 입력한 값은 그대로 유지되며 추가된 공간엔 쓰레기 값이 존재한다
            저장 공간을 줄이는 경우라면 입력된 데이터는 잘려 나간다
            
            realloc 함수의 원형
                void *realloc(void *, unsigned int);

                반환 값의 형태: void *

            relloc 함수의 사용
                pi = (int *)realloc(pi, 10 * sizeof(int));
                해석 : pi = (int *)realloc(이미 할당한 저장 공간의 포인터, 재할당 후 전체 저장 공간의 크기);

                이미 사용하던 저장 공간의 위치를 포인터가 기억하고 있더라도,
                재할당 과정에서 메모리 위치가 바뀔 수 있으므로
                realloc 함수가 반환하는 주소를 다시 포인터에 저장해 사용하는 것이 좋습니다.

                메모리 위치가 바뀌는 경우, 이미 있던 데이터는 계속 사용할 수 있도록 옮겨서 사용하며
                기존 저장 공간은 자동으로 반환됩니다.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi;            // 할당한 저장 공간을 연결할 포인터
    int size = 5;       // 한 번에 할당할 저장 공간의 크기, int형 변수 5개씩
    int count = 0;      // 현재 입력된 양수 개수

    int num;
    int i;

    pi = (int *)calloc(size, sizeof(int));  // 먼저 5개의 저장 공간을 할당

    while (1)
    {
        printf("양수만 입력하세요 => ");
        scanf("%d", &num);
        if (num <= 0) break;
        if (count == size)
        {
            size += 5;
            pi = (int *)realloc(pi, size * sizeof(int));
        }
        pi[count++] = num;
    }

    for ( i = 0; i < count; i++ )
    {
        printf("%5d", pi[i]);   // 입력한 데이터 출력
    }

    free(pi);

    return 0;
}

/* 실행 결과

양수만 입력하세요 => 1
양수만 입력하세요 => 2
양수만 입력하세요 => 3
양수만 입력하세요 => 4
양수만 입력하세요 => 5
양수만 입력하세요 => 6
양수만 입력하세요 => 7
양수만 입력하세요 => -1
    1    2    3    4    5    6    7

*/