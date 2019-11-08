#ifndef FLXARRAY_H_
#define FLXARRAY_H_

typedef struct flxarrayrec* flxarray;

extern void flxarray_append(flxarray fa, int item);
extern void flxarray_free(flxarray fa);
extern flxarray flxarray_new();
extern void flxarray_print(flxarray fa);
extern void flxarray_sort(flxarray fa);

#endif
