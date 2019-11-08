#include <stdio.h>
#include <stdlib.h>
#define ARRAY_MAX 10
void insertion_sort(int *array, int size) {
	int  key; 
	


}


int main(void) {
	int my_array[ARRAY_MAX];
	int i, count = 0;
	
	while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
		count++;
	}
	
	insertion_sort(my_array, count);
	
	for (i = 0; i < count; i++) {
		printf("%d\n", my_array[i]); //print sorted array
	}

 
	return EXIT_SUCCESS;
}
