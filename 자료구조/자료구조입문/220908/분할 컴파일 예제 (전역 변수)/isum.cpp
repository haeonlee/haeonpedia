#include "include.h"    // cpp 파일과 같은 폴더에 있어야 함
#include "function.h"
#include "extern.h"

int isum(void) {
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
