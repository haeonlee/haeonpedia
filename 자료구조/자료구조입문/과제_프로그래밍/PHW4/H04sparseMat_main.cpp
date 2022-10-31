
#include "H04sparseMat.h"

int allocSize;      // size of allocated memory currently used

int main(void) {
    matrixPtr A, B, C;
    int T;

    scanf("%d", &T);    // read # of test cases

    for (int t = 1; t <= T; t++) {
        allocSize = 0;
        A = mread();
        B = mread();
        C = madd(A, B);

        if(t == 1)
            printf("Test %d : (mem = %d bytes)\n", t, allocSize);
        else
            printf("\nTest %d : (mem = %d bytes)\n", t, allocSize);

        printf("A : ");   
        mwriteFull(A);

        printf("B : ");        
        mwriteFull(B);

        printf("A+B : ");        
        mwriteFull(C);

        merase(&A);
        merase(&B);
        merase(&C);
        if (allocSize != 0) {
            printf("ERROR in memory size counting(currently %d bytes remained\n", allocSize);
        }
    }

    return EXIT_SUCCESS;
}

void testSMatrix_mid(matrixPtr M, matrixPtr* hnode) {
    // Print matrix rowise and columnwise each.
    // This function may be used to check if
    // the sparse matrix data are correctly stored.
    // 
    // (1) rowwise printing
    matrixPtr elm;
    printf("\nrow wise printing\n");
    for (int r = 0; r < M->u.entry.row; r++) {
        for (elm = hnode[r]->right; elm != hnode[r]; elm = elm->right) {
            printf("%5d %5d %5d\n", elm->u.entry.row, elm->u.entry.col,
                                    elm->u.entry.val);
            fflush(stdout);
        }
    }
    // (2) column wise printing
    printf("\ncolumn wise printing\n");
    for (int c = 0; c < M->u.entry.col; c++) {
        for (elm = hnode[c]->down; elm != hnode[c]; elm = elm->down) {
            printf("%5d %5d %5d\n", elm->u.entry.row, elm->u.entry.col,
                elm->u.entry.val);
            fflush(stdout);
        }
    }
    printf("\n");
    fflush(stdout);
}

matrixPtr newNode(void) {
    // allocate a matrixNode and return its pointer
    matrixPtr mp;
    MALLOC(mp, matrixPtr, sizeof(matrixNode))
    return mp;
}

