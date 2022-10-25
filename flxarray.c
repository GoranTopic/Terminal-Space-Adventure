#include <stdio.h>
#include <stdlib.h>
#include "flxarray.h"
#include "mylib.h"


void merge(int* a, int* w, int len){
	//merges the two halfs 

	int i = 0, j = len / 2, c = 0;
	
	while(i < len/ 2 && j < len){
		if( a[i] < a[j] ) w[c++] = a[i++];
			
		else w[c++] = a[j++];
		
	}	
	
	while( i < len / 2) w[c++] = a[i++];
		//while there still elements in i

	while( j < len) w[c++] = a[j++];
		//while there still elements in j
} 


int merge_sort_recursive(int* array, int* w , int len){
 //mergesort recursibly
	if(len < 2) return 0;
	
	merge_sort_recursive(array, w, len / 2); // divide left side
	merge_sort_recursive(array + (len / 2), w, len - (len / 2)); //divide right side 
	
	merge(array, w, len);
	
	for(int i = 0; i < len; i++) array[i] = w[i];
		// add items from working to array
		
	return EXIT_SUCCESS;
}


int mergesort(int* array, int size){
	int working[size];
	merge_sort_recursive(array, working, size);
	return EXIT_SUCCESS;
}

struct flxarrayrec { //why does it have rec at the en of the struct name?
		//struc fot flxarrays
	int capacity;
	int count;
	int *items;
	};

flxarray flxarray_new() {
		// fl
	flxarray result = emalloc(sizeof *result);
	result->capacity = 2;
	result->count = 0;
	result->items = emalloc(result->capacity * sizeof result->items[0]);
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

