#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <math.h>
#include "mylib.h"
#include "flxarray.h"
#include "htable.h" 

int main(int argnum, char** args) {
	
	int r = 0, iopts = 0, table_size = 3877, word_count = 0, option;
	float fill_time, search_time;
	htable h;
	FILE* file;
	clock_t start_t, end_t;
	char* longest_word = "Honorificabilitudinitatibus";
	char* word = emalloc(sizeof(char) * (strlen(longest_word) + 1));
	const char *optstring = "ihprs:";

	
	
	
	while ((option = getopt(argnum, args, optstring)) != -1){
		
		switch (option) {
			case 'r':
				/*Use the rubust method, rbt, in the hash table*/
				printf("robust on, using rbt\n");
				r = 1;
				break;

			case 'p':
				
				if((file = openfile(args, 1, argnum)) == NULL) return EXIT_FAILURE;
				h = htable_new(table_size, r);
				while(1 == (fscanf(file,"%s", word))) htable_insert(h, word);
	
				htable_print(h, stdout);
				return EXIT_SUCCESS;
			

			case 's':
				table_size = atoi(optarg);
				printf("Using table size of %d instead of default (3877) \n", table_size); 
				break;
			case 'i':
				iopts = 1;
				break;
			case 'h':
				printf(
					"SPELLCHEKER COSC242 Assigment 2017, \n"
					"Checks the spelling of the words in the document with given dictionary.\n"
					"Print out misspelled words\n"
					"Usage: spellchck [DICTIONARY] < [DOCUMENT] [OPTIONs]... \n");
				printf(
					"\n"
					"Startup:\n"
 					"-r,  --Robust      			 Uses a Red an Black tree to store the words, making fast at the cost memory.\n"
					"-h,  --Help     			    Print this help options.\n"
					"-s,  --Size    			    Take a argmuent as the new size for the has table.\n"
					"-p,  --Print   	   		    Prints the content of each container in the hash table.\n"
					"-i   --Information 			 Prints the word count, fill time and search time.\n\n");
				return EXIT_SUCCESS;

			default:
				
				fprintf(stderr, "Option not found use -h to see a list of options\n");
		}
	
	}



	if((file = openfile(args, 1, argnum)) == NULL) return EXIT_FAILURE;

	start_t = clock();
   	
	/*printf("start to insert into words into hash table, start_t = %ld\n", start_t);*/
	
	h = htable_new(table_size, r);

	
	while(1 == (fscanf(file,"%s", word))){
		/*reading from dictinary*/
		htable_insert(h, word);
	}

	end_t = clock();
   	fill_time = (end_t - start_t) / CLOCKS_PER_SEC;
	



	/*htable_print(h, stdout)*/;
	start_t = clock();
	while (getword(word, sizeof word, stdin) != EOF) {
		/*get words from document*/
		if( ! htable_isin(h, word)){
			printf("word: %s was not found in dic\n", word);
		 	word_count++;
 		}

	}
	end_t = clock();
	search_time = (end_t - start_t) / CLOCKS_PER_SEC;
	
	if(iopts) fprintf(stderr, "Fill time : %f\n" 
					 "Search time : %f\n"
					 "Unknown words : %d\n"
					 , fill_time, search_time, word_count);
	
	htable_free(h);
	free(word);
	
	return EXIT_SUCCESS;
}
