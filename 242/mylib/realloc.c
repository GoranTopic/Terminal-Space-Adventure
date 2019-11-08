#include <stdio.h>	
#include <stdlib.h>


static void print_array(int* a, int size){
	//print the array
	for(int i = 0; i < size; i++) printf("%d\n", a[i]);
}



int* scan_int_flxarray(int* return_size){
	//scan_dynamic_array

	int capacity = 2, count = 0, intiger;
	int* array = malloc(capacity * sizeof array[0]);
	
	if( NULL == array){
		//memory full error
		fprintf(stderr, "Memory allocation failed\nMemory full maybe\n");
		exit(EXIT_FAILURE);
	}

	while( 1 == scanf("%d", &intiger)){
		
		if(capacity == count){ 
				// if capacity has been reached remalloc more memory
		
			capacity += capacity; 		
			array = realloc(array, capacity * sizeof array[0]);
		}
		
		if( NULL == array){
				//memory full error
			fprintf(stderr, "Memory reallocation failed\nMemory full maybe\n");
			exit(EXIT_FAILURE);
		}
			
		array[count++] = intiger;	
			//assign value to array
	} 
 *return_size = count;	
return array;

}



int main(void){
	int size = 10;
	int* my_array = scan_int_flxarray(&size);

	print_array(my_array, size);
	free(my_array);


	return EXIT_SUCCESS;
}



