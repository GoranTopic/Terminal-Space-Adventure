#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "htable.h"
#include <string.h>

int main(void) {
	htable h = htable_new(22218143);
	int i = 0; 
	char searchw[256];
	char word[256];
	//printf("hey\n");
	while (getword(word, sizeof word, stdin) != EOF) {
		if(i++  == 100)strcpy(searchw, word);
		htable_insert(h, word);	
		
	}

	//printf("hello");
	htable_print(h, stdout);
	//printf(",");
	htable_free(h);
	//printf("world");
	
	printf("search freq of word %s: %d \n", searchw, htable_search(h, searchw));

	return EXIT_SUCCESS;
}
