#include <stdio.h> /* for fprintf */
#include <stdlib.h> /* for size_t, malloc, realloc, exit */
#include "mylib.h"
	

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
