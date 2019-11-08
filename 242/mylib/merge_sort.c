#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000	

void merge(int* a, int* w, int len){
	//merges the 

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

void print_array(int* a, int len){
	//print areray evenly and nicely =D
	for (int i = 0; i < len; i++){
		printf("a[%3d] = %5d, of len: %3d\n", i, a[i], len);
	} 
}

int merge_sort_recursive(int* array, int* w , int len){

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

int main (int argnum, char **args ){
	FILE* file; 
	int array[MAX_SIZE]; 	
	int size = 0;


	if(NULL == (file = fopen(args[1], "r"))) {
		//open the file in the pointer file
		printf("file %s  was not able to be read", args[1]);
		return EXIT_FAILURE;
	} 

		
	while(size < MAX_SIZE && 1 == (fscanf(file,"%d", &array[size])))size++;
		//read the values form the file
	  
	mergesort(array, size);

	print_array(array, size);	


	return EXIT_SUCCESS;		
}



