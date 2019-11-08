#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void) {
// variable declarations 
	int i = 0;
	double j = 1.0;
	// a familiar "for loop" 
	for (i = 0; i < 10; i++) {
		printf("%d %f %f\n", i, j, sqrt(j));
		j *= 2;
	}
	return EXIT_SUCCESS; // defined in stdlib.h 
}
