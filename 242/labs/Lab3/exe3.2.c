#include <stdio.h>
#include <stdlib.h>



int display_repeats(int* array, int size){
	int repeats[size - 1];//make an array with the size of the original -1
		

	for(int i = 0; i < size - 1; i++) repeats[i] = 0; //ste all the array to 0


	for(int i = 0; i < size; i++)repeats[array[i]]++; //magic

	
	for(int i = 0; i < size - 1; i++) printf("The number %d has been repeted %d times \n", i, repeats[i]); //print values that repeat
	

	return EXIT_SUCCESS;
}






int main(void) {
	int array_size = 0;
	int *my_dynamic_array;
	int i = 0;


	printf("Enter the size of the array: ");
	if( 1 != scanf("%d", &array_size)) array_size = 10;

	
	/* initialise the array to the appropriate size */
	my_dynamic_array = malloc(array_size * sizeof my_dynamic_array[0]);
	
	if (NULL == my_dynamic_array) {
		fprintf(stderr, "memory allocation failed!\n");
		return EXIT_FAILURE;
	}
	
	for (i = 0; i < array_size; i++) {
		my_dynamic_array[i] = rand() % array_size;
	}

	printf("What’s in the array:\n");

	for (i = 0; i < array_size; i++) {
		printf("%d ", my_dynamic_array[i]);
	}

	printf("\n");

	/* release the memory associated with the array */


	display_repeats(my_dynamic_array, array_size);
	
	free(my_dynamic_array);
	return EXIT_SUCCESS;

}

