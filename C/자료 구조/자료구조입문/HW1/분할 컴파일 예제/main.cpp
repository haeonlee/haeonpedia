#include "include.h"
#include "function.h"

int main(void) {
    // add n integers and print the sum
    // int T;  // T: number of test cases
    int n, *L;
    int sum;
    

    // scanf("%d", &T);    // read # of test cases

    // for (t = 1; t <= T; t++)                // 교수님은 for (int t = 1; t <= T; t++)로 짜심
                                            // 대신 앞에 int t 없고
        // scanf("%d", &n);                    // read n

    int t = 0;

    while(scanf("%d", &n)!=EOF) {
        MALLOC(L, int*, n * sizeof(int))    // alloc memory
        for (int i = 0; i < n; i++) {
            scanf("%d", &L[i]);             // read n intengers
        }

        printf("Test %d\n", ++t);

        sum = isum(L, n);
        printf("isum = %d\n", sum);

        sum = rsum(L, n);
        printf("rsum = %d\n", sum);
        free(L);                            // deallocate the memory
    }
    return(EXIT_SUCCESS);
}

int isum(int * L, int n) {
    int sum;
    if (n == 0) {
        fprintf(stderr, "No data!\n");
        exit(EXIT_FAILURE);
    }
    sum = L[0];
    for (int i = 1; i<n; i++) {
        sum += L[i];
    }
    return sum;
}

int rsum(int * L, int n) {
    if(n>0)
        return (rsum(L, n-1)+ L[n - 1]);
    return 0;
}
