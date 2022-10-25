/* insert the item in the last free space */
	}	
				/* do the old "double the capacity" trick */
	while(i < len/ 2 && j < len){
	printf("flxarray count: %3d\n", fa->count);
return result;
		if( a[i] < a[j] ) w[c++] = a[i++];
	};
			fa->capacity += fa->capacity;
	int working[size];
#include "flxarray.h"
	if (fa->count == fa->capacity) {
	result->capacity = 2;
	while( j < len) w[c++] = a[j++];
 
	
	
	
	
	
	
 //mergesort recursibly
/* free the memory associated with the flexarray */
} 
		// add items from working to array
#include "mylib.h"
	merge_sort_recursive(array + (len / 2), w, len - (len / 2)); //divide right side 
int mergesort(int* array, int size){
struct flxarrayrec { //why does it have rec at the en of the struct name?
	int *items;
#include <stdio.h>
void flxarray_append(flxarray fa, int num) {
		else w[c++] = a[j++];
	free(fa);
	fa->items[fa->count++] = num; 






















void merge(int* a, int* w, int len){
}
}
}
}
}
}
}
#include <stdlib.h>
	result->count = 0;
	result->items = emalloc(result->capacity * sizeof result->items[0]);
		//while there still elements in i
		printf("FA[%3d] = %5d\n", i, fa->items[i]);
void flxarray_print(flxarray fa) {
		//while there still elements in j
		//struc fot flxarrays
	merge_sort_recursive(array, working, size);
void flxarray_sort(flxarray fa) {
	//print areray evenly and nicely =D
	int i = 0, j = len / 2, c = 0;
			
	}
	/* mergesort would be good */
	int capacity;
	if(len < 2) return 0;
	mergesort(fa->items, fa->count);
	merge_sort_recursive(array, w, len / 2); // divide left side
	int count;
void flxarray_free(flxarray fa) {
			fa->items = erealloc(fa->items, fa->capacity * sizeof fa->items[0]);
		
		
	merge(array, w, len);
		}
		// fl
	for(int i = 0; i < fa->count; i++){
	//merges the two halfs 
	/* a "for" loop to print out each cell of f->items */
int merge_sort_recursive(int* array, int* w , int len){
	while( i < len / 2) w[c++] = a[i++];
	flxarray result = emalloc(sizeof *result);
	return EXIT_SUCCESS;
	return EXIT_SUCCESS;
	for(int i = 0; i < len; i++) array[i] = w[i];
flxarray flxarray_new() {
