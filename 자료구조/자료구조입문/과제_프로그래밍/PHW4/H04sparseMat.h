#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

// include files
#include <stdio.h>
#include <stdlib.h>

// macros
#define MALLOC(ptr, type, size) \
 if (!((ptr)=(type)malloc(size))) {\
   fprintf(stderr, "Insufficient memory"); \
   exit(EXIT_FAILURE); \
 }

#define MAX2(x, y) ((x) > (y) ? (x) : (y))

// data definitions
typedef enum {head, entry} tagfield;
typedef struct _entryNode {
    int row, col, val;
} entryNode;

typedef struct _matrixNode {
  struct _matrixNode *down, *right;
  tagfield tag;
  union {
    struct _matrixNode* next;
    entryNode entry;
  } u;
} matrixNode;
typedef matrixNode* matrixPtr;

// functions used
void testSMatrix_mid(matrixPtr M, matrixPtr* hnode);
matrixPtr newNode(void);
matrixPtr mread(void);
void mwriteFull(matrixPtr node);
void merase(matrixPtr* node);
matrixPtr madd(matrixPtr A, matrixPtr B);