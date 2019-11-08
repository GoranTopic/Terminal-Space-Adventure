#include <stdio.h> /* for fprintf */
#include <stdlib.h> /* for size_t, malloc, realloc, exit */
#include <assert.h>
#include <ctype.h>
#include "mylib.h"


FILE* openfile(char** args, int file_num, int argnum){
	FILE* file;

	if(file_num >= argnum){
		printf("the file %d is bigger then number of args passed\n", file_num);
		return NULL;

	}
	if(NULL == (file = fopen(args[file_num], "r"))) {
		/*open the file in the pointer file*/
			printf("file %s was not able to be read\n", args[file_num]);
			return file;
	}
	return file;
}


void* emalloc(size_t s) {
	/* implementation of emalloc goes here */
	void* result = malloc(s);
	if (NULL == result) {
		fprintf(stderr, "Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	return result;
}



void* erealloc(void *p, size_t s) {
	void* result = realloc(p, s);
	if (NULL == result) {
		fprintf(stderr, "Memory reallocation failed!\n");
		exit(EXIT_FAILURE);
	}
	return result;
}





int getword(char *s, int limit, FILE *stream) {
	int c;
	char *w = s;
	
	assert(limit > 0 && s != NULL && stream != NULL);
		/* skip to the start of the word */
		while (!isalnum(c = getc(stream)) && EOF != c)
			;

		if (EOF == c) {
			return EOF;
		} else if (--limit > 0) { 
			/* reduce limit by 1 to allow for the \0 */
			*w++ = tolower(c);
		}

		while (--limit > 0) {
			
			if (isalnum(c = getc(stream))) {
				*w++ = tolower(c);
			} else if ('\'' == c) {
				limit++;
			} else {
				break;
			}
	
		}
	
		*w = '\0';
	
		return w - s;
}
