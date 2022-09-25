#include <stdio.h>

void selSort(int list[], int n) {
    int i, j, min, tmp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for ( j = i + 1; j < n; j++) {
            if (list[j] < list[min])
                min = j;
        }
    }
    SWAP(list[i], list[min], tmp);
}