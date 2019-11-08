#include <stdio.h>
#include <stdlib.h>

int main(void){

	double entry = 0.0;
	double total = 0.0;
	int num_entries = 0;

	while( 1 == scanf("%lg", &entry)){
	
		total += entry;
		num_entries++;
		printf("Current entry: %lg, Total: %lg, entry : %d\n", entry, total, num_entries);
	}

	return EXIT_SUCCESS;



}
