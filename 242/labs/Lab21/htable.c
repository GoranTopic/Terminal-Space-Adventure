#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

struct Htable {
		/*struc foro a new hash table, it has the capacity and the frequenct*/ 
	char** keys; 
	int cap; /*capacity*/
	int count;
	int* freq; /*frequency*/
};


htable htable_new(int num){
	/*a fucctuion that crates a new hash table.*/
	int i;
	htable t =  emalloc(sizeof *t);
	t->cap = num; /*capacity*/ 
	t->count = 0; /*are this in the stack while the other ones in the heap?*/
	t->freq = emalloc(t->cap * sizeof t->freq[0]); 

	t->keys = emalloc(t->cap * sizeof t->keys[0]); 
	
	for(i = 0; i < t->cap; i++){
		/*set all values of frequency to their initial value (0)*/
		t->freq[i] = 0;	
		t->keys[i] = NULL;
	} 

return t;
}


void htable_free(htable t){
/*	free the resorces from the given hash table*/
	int i;
	for(i = 0; i < t->cap;i++){
		if( t->freq[i] > 0) free(t->keys[i]);

	}
	free(t->freq);
	free(t);
}


static unsigned int htable_word_to_int(char *word) {
	/*hash fuction for words*/
	unsigned int result = 0;
	
	while (*word != '\0') {
		result = (*word++ + 31 * result);
	}
	return result;
}



int htable_insert(htable h, char* word){
	/**insert a string into a hash table if hash table full, return 0 */
	unsigned num, pos; /*hash number, position*/
	int i;
	char* str;
	num = htable_word_to_int(word);	
	pos = num % h->cap; 
	str = emalloc(sizeof word[0] * strlen(word)); 		
	strcpy(str, word);	

	if(h->freq[pos] == 0){ /*if it is empty*/
		h->keys[pos] = str; /*insert*/
		
		return ++h->freq[pos]; /*return freq + 1*/
	
	}else if(strcmp(h->keys[pos], str) == 0){ /*it is the same string*/
		
		return ++h->freq[pos];
	
	}else{	 
		
  	/*printf("h->key[%d]:%s str: %s, freq: %d\n", pos, h->keys[pos], str, h->freq[pos]);*/
		for(i = 1; i < h->cap; i++){
			pos = (num + i) % h->cap;
						
  		/*printf("i: %d,  h->key[%d - %d ] :%s str: %s\n", i,  pos, h->cap, h->keys[pos], str);*/
			if(h->freq[pos] == 0){
				h->keys[pos] = str;
				
				return ++h->freq[pos];
				
			}else if(strcmp(h->keys[pos], str) == 0){
				return ++h->freq[pos];

			}
		} 
		return 0; /*hash table full, for loop reach capacity*/			
	}
}


/** print fuction of later use */
void htable_print(htable t, FILE *stream){
	/*print the given hash table*/ 
	int i;

	fprintf(stream, "the count is: %d, the capacity is %d\n", t->count, t->cap);  
	for(i = 0; i < t->cap; i++){
		fprintf(stream, "t[%d] -> %s, freq: %d\n", i, t->keys[i], t->freq[i]);

	} 

}

