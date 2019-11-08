#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"


void print_array(int* a, int len){
	//print areray evenly and nicely =D
	printf("array len: %3d\n", len);
	
	for (int i = 0; i < len; i++){
		printf("a[%3d] = %5d\n", i, a[i]);
	} 
}




int main(void) {

	int capacity = 2;
	int itemcount = 0;
	int item;
	int *my_array = emalloc(capacity * sizeof my_array[0]);


	while (1 == scanf("%d", &item)) {
		if (itemcount == capacity) {
			capacity += capacity;
			my_array = erealloc(my_array, capacity * sizeof my_array[0]);
		}
		my_array[itemcount++] = item;
	}

/* do something useful (e.g. sorting) here */
	

	print_array(my_array, itemcount);

	free(my_array);
	return EXIT_SUCCESS;
}
