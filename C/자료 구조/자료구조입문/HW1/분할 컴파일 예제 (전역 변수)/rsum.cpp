#include "include.h"
#include "function.h"
#include "extern.h"

int rsum(int n) {
    if(n>0)
        return (rsum(L, n-1)+ L[n - 1]);
    return 0;
}