#include "include.h"
#include "function.h"

int rsum(int * L, int n) {
    if(n>0)
        return (rsum(L, n-1)+ L[n - 1]);
    return 0;
}