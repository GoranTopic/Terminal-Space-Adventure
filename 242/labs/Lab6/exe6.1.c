#include <stdio.h>
#include <stdlib.h>

int factorial(int num) {
	if(num == 1 || num == 0) return num;
	else{
		printf("%d\n", num);
		factorial(--num);
	}
	return EXIT_FAILURE;	
}



int main() {
	int num;


	while (1 == scanf("%d", &num)) {
		printf("%d\n", factorial(num));
	}
	return EXIT_SUCCESS;
}



