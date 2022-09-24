#include <stdio.h>
#include <stdlib.h>

#define MALLOC(ptr,type,size) \
if ( !((ptr) = (type)malloc(size)) ) { \
    fprintf(stderr, "Insufficient memory"); \
    exit (EXIT_FAILURE);    \
}

int isum(int * L, int n);
int rsum(int * L, int n);

int main(void) {
    // add n integers and print the sum
    int n, *L;
    int sum;

    scanf("%d", &n);                    // read n
    MALLOC(L, int*, n*sizeof(int))      // alloc memory
    for (int i = 0; i < n; i++) {
        scanf("%d", &L[i]);             // read n intengers
    }

    sum = isum(L, n);
    printf("isum = %d\n", sum);

    sum = rsum(L, n);
    printf("rsum = %d\n", sum);

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
