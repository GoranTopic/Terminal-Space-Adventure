#include <stdio.h>
#include <stdlib.h>
#include "flxarray.h"
int main(void) {

	int item; // items that are read an append to the flxarray
	
	flxarray my_flxarray = flxarray_new();

	while (1 == scanf("%d", &item)) {
		flxarray_append(my_flxarray, item);
	}



	flxarray_sort(my_flxarray);

	flxarray_print(my_flxarray);
	flxarray_free(my_flxarray);
	return EXIT_SUCCESS;
}
