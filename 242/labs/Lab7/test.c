/** Test for the cosc 242,  it includes reading from file and getting the average word size */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS	5
#define STRLEN 80

int aver_wlen(char* words[], int size){
	int total = 0;
	for(int i = 0; i < size; i++){
	
		total = total + strlen(words[i]);

	}
	printf("total: %d, size: %d\n", total, size);
	return total / size;


}

void print_big_w(char* word[], int size, int aver){
	for(int i = 0; i < size; i++){
		if(strlen(word[i]) > aver) printf("Bigly word: %s\n", word[i]);
	}
}


int main(void){
	char* words[MAX_WORDS];
	char word_buffer[STRLEN];
	int aver, count = 0;

	while(count < MAX_WORDS && 1 == scanf("%79s", word_buffer)){

		words[count] = malloc(strlen(word_buffer));
			//allocate memory and make wrod poit to it 
			
		strcpy(words[count], word_buffer); //copy word into the memory
			
		count++;
	} 



	for(int i = 0; i < count; i++){
		printf("%s ", words[i]);
	}
	printf("\n"); // make a new line

	aver = aver_wlen(words, count); 
	print_big_w(words, count, aver);	

//printf("\naverage: %d\n", aver);


	for(int i = 0; i < count; i++) free(words[i]);


}



