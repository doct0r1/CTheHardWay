//
// Created by Mu$t4f△ J4m4L on 7/11/17.
//

#ifndef darray_algos_h
#define darray_algos_h

//#include <lcthw/darray.h>
#include "../ex34/darray.h"

typedef int (*DArray_compare) (const void *a, const void *b);

int DArray_qsort(DArray *array, DArray_compare cmp);

int DArray_heapsort(DArray *array, DArray_compare cmp);

int DArray_mergesort(DArray *array, DArray_compare cmp);

#endif // DARRAY_ALGOS_H
