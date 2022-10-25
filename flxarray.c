void flxarray_free(flxarray fa) {
/* free the memory associated with the flexarray */
	while( j < len) w[c++] = a[j++];
		if( a[i] < a[j] ) w[c++] = a[i++];
	result->count = 0;
struct flxarrayrec { //why does it have rec at the en of the struct name?
flxarray flxarray_new() {
	int *items;
	flxarray result = emalloc(sizeof *result);
	int working[size];
		//while there still elements in j
void flxarray_append(flxarray fa, int num) {
#include <stdlib.h>
		//struc fot flxarrays
	//print areray evenly and nicely =D
int mergesort(int* array, int size){
 
 //mergesort recursibly
			fa->capacity += fa->capacity;
	int capacity;
	printf("flxarray count: %3d\n", fa->count);
	if (fa->count == fa->capacity) {
#include <stdio.h>
		// fl
	result->capacity = 2;
	merge_sort_recursive(array, working, size);
/* insert the item in the last free space */
	};
	while( i < len / 2) w[c++] = a[i++];
	}
void merge(int* a, int* w, int len){
	for(int i = 0; i < len; i++) array[i] = w[i];
	result->items = emalloc(result->capacity * sizeof result->items[0]);
		}
	for(int i = 0; i < fa->count; i++){
	while(i < len/ 2 && j < len){
		printf("FA[%3d] = %5d\n", i, fa->items[i]);
	int i = 0, j = len / 2, c = 0;
	merge_sort_recursive(array, w, len / 2); // divide left side






















	return EXIT_SUCCESS;
	return EXIT_SUCCESS;
	merge_sort_recursive(array + (len / 2), w, len - (len / 2)); //divide right side 
		else w[c++] = a[j++];
	if(len < 2) return 0;
	//merges the two halfs 
return result;
#include "flxarray.h"
} 
	fa->items[fa->count++] = num; 
			fa->items = erealloc(fa->items, fa->capacity * sizeof fa->items[0]);
		//while there still elements in i
	
	
	
	
	
	
	int count;
		// add items from working to array
	mergesort(fa->items, fa->count);
				/* do the old "double the capacity" trick */
		
		
	free(fa);
	}	
	merge(array, w, len);
void flxarray_sort(flxarray fa) {
			
void flxarray_print(flxarray fa) {
int merge_sort_recursive(int* array, int* w , int len){
	/* a "for" loop to print out each cell of f->items */
}
}
}
}
}
}
}
	/* mergesort would be good */
#include "mylib.h"
