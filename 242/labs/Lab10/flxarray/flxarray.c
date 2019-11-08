#include <stdio.h>
#include <stdlib.h>
#include "flxarray.h"
#include "../mylib.h"
#include "mergesort.h"

struct Flxarray { 
		//struc fot flxarrays
	int capacity;
	int count;
	int *items;
};

flxarray flxarray_new() {
		//fl
	flxarray result = emalloc(sizeof *result);
	result->capacity = 2;
	result->count = 0;
	result->items = emalloc(result->capacity * sizeof(int));
return result;
}


void flxarray_append(flxarray fa, int num) {
	
	if (fa->count == fa->capacity) {
				/* do the old "double the capacity" trick */
			fa->capacity += fa->capacity;
			fa->items = erealloc(fa->items, fa->capacity * sizeof fa->items[0]);
		}

	fa->items[fa->count++] = num; 
/* insert the item in the last free space */
}


void flxarray_print(flxarray fa) {
	/* a "for" loop to print out each cell of f->items */
	//print areray evenly and nicely =D
	printf("flxarray count: %3d\n", fa->count);

	for(int i = 0; i < fa->count; i++){
		printf("FA[%3d] = %5d\n", i, fa->items[i]);
	}
 
}


void flxarray_sort(flxarray fa) {
	/* mergesort would be good */
	mergesort(fa->items, fa->count);
}


void flxarray_free(flxarray fa) {
/* free the memory associated with the flexarray */
	free(fa);

}

