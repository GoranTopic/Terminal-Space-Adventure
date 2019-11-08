#ifndef MERGESORT_H_
#define MERGESORT_H_
#include <stdio.h>
#include <stdlib.h>

extern void merge(int* a, int* w, int len);
extern int merge_sort_recursive(int* array, int* w , int len);
extern int mergesort(int* array, int size);

#endif
