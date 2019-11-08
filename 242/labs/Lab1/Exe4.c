#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int is_prime(int num){
	for(int i = 2; i < num; i++){
		if( num % i == 0) return 0;
	}  
	return 1;

}




int main(void){
	int target = 100000000;
	int inicial = 1;

	for( int i = inicial; i < target; i++){
		if(is_prime(i)) printf("The number %d is prime \n",i);
		

	}

	return EXIT_SUCCESS;

}
