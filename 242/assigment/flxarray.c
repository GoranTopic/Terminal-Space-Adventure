#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flxarray.h"
#include "mylib.h"


struct flxarrayrec{ 
	/**why does it have rec at the en of the struct name?
	struc fot flxarrays*/
	int capacity;
	int count;
	char** items;
};

flxarray flxarray_new(){
	flxarray result = emalloc(sizeof *result);
	result->capacity = 2;
	result->count = 0;
	result->items = emalloc(result->capacity * sizeof result->items[0]);
return result;
}


void flxarray_append(flxarray fa, char* word) {
	
	if (fa->count == fa->capacity) {
				/* do the old "double the capacity" trick */
			fa->capacity += fa->capacity;
			fa->items = erealloc(fa->items, fa->capacity * sizeof fa->items[0]);
		}

	fa->items[fa->count] = emalloc(sizeof(char) * ( strlen(word) + 1)); 
	strcpy(fa->items[fa->count], word); 
	fa->count++;
/* insert the item in the last free space */
}


void flxarray_print(flxarray fa) {
	/* a "for" loop to print out each cell of f->items 
	 print areray evenly and nicely =D */
	
	int i;
	for(i = 0; i < fa->count; i++){
		printf("%5s, ", fa->items[i]);
	}
	printf("\n");
 
}

int flxarray_search(flxarray fa, char* key){
	/*searches the flex array for a instance of the key, if found return 1, else return 0*/
	
	int i;
	for(i = 0; i < fa->count; i++){
		
		if(strcmp(fa->items[i], key) == 0){
		
		return 1;
		} 
	}
	return 0;

}

void flxarray_free(flxarray fa) {
/* free the memory associated with the flexarray */
	int i;

	for(i = 0; i < fa->count; i++){
		free(fa->items[i]);
	}
	free(fa);

}

