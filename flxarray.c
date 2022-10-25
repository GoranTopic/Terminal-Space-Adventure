	int *items;
		//struc fot flxarrays
	int capacity;
		// add items from working to array
void flxarray_free(flxarray fa) {
	int i = 0, j = len / 2, c = 0;
#include <stdio.h>
	}	
	//print areray evenly and nicely =D
	int working[size];
	};
		printf("FA[%3d] = %5d\n", i, fa->items[i]);
	mergesort(fa->items, fa->count);
	free(fa);
	result->items = emalloc(result->capacity * sizeof result->items[0]);
int merge_sort_recursive(int* array, int* w , int len){
	}
	
	
	
	
	
	
	while( i < len / 2) w[c++] = a[i++];
	return EXIT_SUCCESS;
	return EXIT_SUCCESS;
		}
		
		
			fa->items = erealloc(fa->items, fa->capacity * sizeof fa->items[0]);
}
}
}
}
}
}
}
			
#include <stdlib.h>
	while(i < len/ 2 && j < len){
	if(len < 2) return 0;
	/* mergesort would be good */
#include "mylib.h"
			fa->capacity += fa->capacity;
	result->capacity = 2;
	merge(array, w, len);
	while( j < len) w[c++] = a[j++];
	flxarray result = emalloc(sizeof *result);
 //mergesort recursibly
		//while there still elements in j
void merge(int* a, int* w, int len){






















	result->count = 0;
	merge_sort_recursive(array, w, len / 2); // divide left side
	if (fa->count == fa->capacity) {
flxarray flxarray_new() {
/* insert the item in the last free space */
void flxarray_sort(flxarray fa) {
	for(int i = 0; i < len; i++) array[i] = w[i];
struct flxarrayrec { //why does it have rec at the en of the struct name?
	/* a "for" loop to print out each cell of f->items */
	merge_sort_recursive(array, working, size);
} 
#include "flxarray.h"
	//merges the two halfs 
	fa->items[fa->count++] = num; 
				/* do the old "double the capacity" trick */
	merge_sort_recursive(array + (len / 2), w, len - (len / 2)); //divide right side 
void flxarray_append(flxarray fa, int num) {
		//while there still elements in i
	for(int i = 0; i < fa->count; i++){
int mergesort(int* array, int size){
	int count;
 
		if( a[i] < a[j] ) w[c++] = a[i++];
		// fl
		else w[c++] = a[j++];
/* free the memory associated with the flexarray */
return result;
	printf("flxarray count: %3d\n", fa->count);
void flxarray_print(flxarray fa) {
