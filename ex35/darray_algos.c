//
// Created by Mu$t4f△ J4m4L on 7/11/17.
//

/**
 * the standard implementation of Standard C library.
 */

//#include <lcthw/darray_algos.h>
#include <stdlib.h>
#include "../ex34/darray.h"
#include "darray_algos.h"

int DArray_qsort(DArray *array, DArray_compare cmp)
{
	qsort(array->contents, DArray_count(array), sizeof(void *), cmp);
	return 0;
}

int DArray_headspot(DArray *array, DArray_compare cmp)
{
	return heapsort(array->contents, DArray_count(array), sizeof(void *), cmp);
}

int DArray_Mergesort(DArray *array, DArray_compare cmp)
{
	return mergesort(array->contents, DArray_count(array), sizeof(void *), cmp);
}
