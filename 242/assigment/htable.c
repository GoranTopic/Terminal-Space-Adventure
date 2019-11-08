#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"
#include "flxarray.h"
#include "rbt.h"



typedef enum container_e {FLEX_ARRAY, RED_BLACK_TREE} container_t;

#define ISTREE(x) ((NULL == (x)) || (RED_BLACK_TREE == (x)->cont))

#define ISFLEX(x) ((NULL != (x)) && (FLEX_ARRAY == (x)->cont))


struct Htable {
		/*struc foro a new hash table, it has the capacity and the frequenct*/
	flxarray* keys;
	rbt* tree;
	container_t cont;
	int cap; /*capacity*/
	int count;
	int* freq; /* frequency*/
};



htable htable_new(int num, int robst){
	/*a fucctuion that crates a new hash table.*/
	int i;
	htable t =  emalloc(sizeof *t);

	t->cap = num; /*capacity*/
	t->count = 0; /*are this in the stack while the other ones in the heap?*/
	t->freq = emalloc(t->cap * sizeof t->freq[0]); 
	if(robst == 1) t->cont = RED_BLACK_TREE;
	else t->cont = FLEX_ARRAY;

	if(ISTREE(t)){
		t->tree = emalloc(t->cap * sizeof(rbt));

		for(i = 0; i < t->cap; i++) t->freq[i] = 0;	

	}else{

		t->keys = emalloc(t->cap * sizeof t->keys[0]); 	
		for(i = 0; i < t->cap; i++){
		/*set all values of frequency to their initial value (0)*/
			t->freq[i] = 0;	
			t->keys[i] = flxarray_new();
		}
	}
	return t;
}




void htable_free(htable t){
	/*free the resorces from the given hash table*/
	int i;
	for(i = 0; i < t->cap;i++){

		if(ISTREE(t)){
			if( t->tree[i] != NULL ) rbt_free_tree(t->tree[i]);
		
		}else{

			if( t->keys[i] != NULL ) flxarray_free(t->keys[i]);
		}
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
	unsigned int num, pos; /*hash number, position*/
	num = htable_word_to_int(word);	
	pos = num % h->cap; /*the position key will go to based on the word; */		
		

	if(ISTREE(h)){

		h->tree[pos] = rbt_insert(h->tree[pos], word);
		h->freq[pos]++;
		h->count++;
		return EXIT_SUCCESS;

	}else{

		flxarray_append(h->keys[pos], word);
		h->freq[pos]++;
		h->count++;
		return EXIT_SUCCESS; /*return freq + 1*/
	}
  	/*fprintf(stderr, "Hash table is full, aborting\n");*/
	return EXIT_FAILURE; /*hash table full, for loop reach capacity	*/

}


int htable_isin(htable h, char* key){
	/*seaches either a rbt or a flexarry, returns 1 if the word is found
	-1 otherwise*/
	unsigned int num, pos; /*hash number, position*/
	num = htable_word_to_int(key);	
	pos = num % h->cap;

	if(ISTREE(h)){

		return rbt_search(h->tree[pos], key);
		
	}else{

		return flxarray_search(h->keys[pos], key);
		
	}
	printf("This should not be printed in fuction hatable_isin\n");
	return EXIT_FAILURE;


}


void htable_print(htable t, FILE *stream){
	/*print the given hash table into a given stream */
	int i;
	fprintf(stream, "the count is: %d, the capacity is %d\n", t->count, t->cap);  
	
	for(i = 0; i < t->cap; i++){
		if(t->freq[i] > 0){ 
			fprintf(stream, "t[%d] --> ", i); 
			if(ISTREE(t)) rbt_print_inorder(t->tree[i]);
			else flxarray_print(t->keys[i]);
			printf("\n");
		}

	}



}
