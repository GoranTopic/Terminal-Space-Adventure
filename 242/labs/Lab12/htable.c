#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

struct Htable {
		//struc foro a new hash table, it has the capacity and the frequenct 
	char** keys; 
	int cap; //capacity
	int count;
	int* freq; // frequency
};


htable htable_new(int num){
	//a fucctuion that crates a new hash table.
	htable t =  emalloc(sizeof *t);
	t->cap = num; //capacity 
	t->count = 0; //are this in the stack while the other ones in the heap?
	t->freq = emalloc(t->cap * sizeof t->freq[0]); 

	t->keys = emalloc(t->cap * sizeof t->keys[0]); 
		
	for(int i = 0; i < t->cap; i++){
		//set all values of frequency to their initial value (0)
		t->freq[i] = 0;	
		t->keys[i] = NULL;
	} 

return t;
}


void htable_free(htable t){
	//free the resorces from the given hash table
	for(int i = 0; i < t->cap;i++){
		if( t->freq[i] > 0) free(t->keys[i]);

	}
	free(t->freq);
	free(t);
}


static unsigned int htable_word_to_int(char *word) {
	//hash fuction for words
	unsigned int result = 0;
	
	while (*word != '\0') {
		result = (*word++ + 31 * result);
	}
	return result;
}



int htable_insert(htable h, char* word){
	/**insert a string into a hash table if hash table full, return 0 */
	unsigned int num, pos; //hash number, position
	num = htable_word_to_int(word);	
	pos = num % h->cap; 
	char* str = emalloc(sizeof(char) * (strlen(word) + 1)); 		
	strcpy(str, word);	

	if(h->freq[pos] == 0){ //if it is empty
		h->keys[pos] = str; //insert
		
		return ++h->freq[pos]; //return freq + 1
	
	}else if(strcmp(h->keys[pos], str) == 0){ //it is the same string
		
		return ++h->freq[pos];
	
	}else{	 
		
		for(int i = 1; i < h->cap; i++){
			pos = (num + i) % h->cap;
						
			if(h->freq[pos] == 0){
				h->keys[pos] = str;
				
				return ++h->freq[pos];
				
			}else if(strcmp(h->keys[pos], str) == 0){
				return ++h->freq[pos];

			}
		}
  	fprintf(stderr, "Hash tablke full, aborting");
		return EXIT_FAILURE;// hash table full, for loop reach capacity			
	}
}


/** print fuction of later use */
void htable_print(htable t, FILE *stream){
	//print the given hash table 
	fprintf(stream, "the count is: %d, the capacity is %d\n", t->count, t->cap);  
	for(int i = 0; i < t->cap; i++){
		if(t->freq[i] > 0) fprintf(stream, "t[%d] -> %s, freq: %d\n", i, t->keys[i], t->freq[i]);

	} 

}

int htable_search(htable h, char* str){
	/** search the hash table for a string */
	int i = 0, collitions = 0; //number of collitions
	unsigned int num, pos; //hash number, position
	num = htable_word_to_int(str);
	printf("hashed to :%d\n", num);	
	pos = num % h->cap; 
	
	printf("looking for str: %s\n", str);
	while(h->freq[pos] > 0 && i < h->cap){
		
		printf("i : %d, str %s, keys %s\n", i, str, h->keys[pos]);
		if(strcmp(h->keys[pos], str) == 0){
			printf("hello"); 
			return 	h->freq[pos];
		}
		 
		pos = (num + (++i)) % h->cap;
		collitions++;
	}
	
	fprintf(stderr, "String is not in hash table");
	return EXIT_FAILURE;

}
