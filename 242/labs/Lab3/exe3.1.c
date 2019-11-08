#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
	int i = 5;
	int *p;
	
	int size;
		
	printf("i is %d, the address of i is %p\n", i, &i);
	
	p = &i; // p is now storing the address of i 
	
	printf("p is %p, what’s stored at p is %d\n", p, *p);

	*p = 6; /* make the value at memory location p 6 */
	
	printf("what’s stored at p is %d, i is also %d\n", *p, i);
	printf("\nNow printing the adresses of the elemets in the array\n");

	printf("what size would you like the array to be?\n");
	if( 1 != scanf("%d", &size)) size = 10;
 
	
	int array[size];
	for(int i = 0; i < size; i++){
		printf("For the position %d of array the address is %p\n", i, &array[i]);


	}
	return EXIT_SUCCESS;
}

