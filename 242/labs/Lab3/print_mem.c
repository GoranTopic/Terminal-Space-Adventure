#include <stdio.h>
#include <stdlib.h>
 
int main(void) {

	double size, count = 0;
	int* rand_ptr;

	printf("Input the number of meme adresses you want to print\n");
	
	if( 1 != scanf("%lf", &size)) size = 100;

	while ( count < size){
		printf("The ptr %p has the decimanl value of %d\n", rand_ptr++, *rand_ptr);
			

	
	count++;
	}
		
 
	
	return EXIT_SUCCESS;
}

