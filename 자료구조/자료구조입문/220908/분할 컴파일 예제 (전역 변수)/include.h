#include <stdio.h>
#include <stdlib.h>

#define MALLOC(ptr,type,size) \
if ( !((ptr) = (type)malloc(size)) ) { \
    fprintf(stderr, "Insufficient memory"); \
    exit (EXIT_FAILURE);    \
}