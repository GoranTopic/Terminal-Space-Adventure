#ifndef HTABLE_H_
#define HTABLE_H_
#include <stdio.h>


typedef struct Htable* htable;


extern void htable_free(htable h);
extern int htable_insert(htable h, char *str);
extern htable htable_new(int capacity, int robst);
extern void htable_print(htable h, FILE *stream);
extern int htable_search(htable h, char *str);
extern int htable_isin(htable h, char* key);

#endif
