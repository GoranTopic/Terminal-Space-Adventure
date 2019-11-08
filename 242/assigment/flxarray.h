#ifndef FLXARRAY_H_
#define FLXARRAY_H_

typedef struct flxarrayrec* flxarray;

extern void flxarray_append(flxarray fa, char* key);
extern void flxarray_free(flxarray fa);
extern flxarray flxarray_new();
extern void flxarray_print(flxarray fa);
extern void flxarray_sort(flxarray fa);
extern int flxarray_search(flxarray fa, char* key);

#endif
