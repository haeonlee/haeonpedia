#include <stdio.h>
#include <string.h>

void spaceTo0x20(char* A);

int main(void)
{
    char A[100] = "I LOVE\tU...";
    spaceTo0x20(A);
    printf("%s", A);

    return 0;
}

void spaceTo0x20(char* A)
{
    char tab = '\t';
    char space = ' ';

    int i, j;
    int blank_index;

    // CASE1. A에 저장된 문자열이 empty string인 경우: 그냥 return
    if (strlen(A) == 0)
    {
        return;
    }

    // CASE2. A에 저장된 문자열에 빈칸(space 또는 tab)이 없는 경우: 그냥 return
    else if ( strchr(A, tab) == NULL && strchr(A, space) == NULL )
    {
        return;
    }

    // CASE3. 위 두 경우에 모두 해당하지 않는 정상적인 문자열의 경우
    else
    {
        for (i=strlen(A)-1; i>=0; i--)
        {
            if ( A[i] == tab || A[i] == space )
            {
                blank_index = i;

                for (j=strlen(A); j>blank_index; j--)
                {
                    A[j+2] = A[j];
                }

                A[blank_index] = 'C';
                A[blank_index+1] = 'S';
                A[blank_index+2] = 'W';
            }
        }
    }

    return;
}