#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"
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

/** End of mergesort fuctions */
