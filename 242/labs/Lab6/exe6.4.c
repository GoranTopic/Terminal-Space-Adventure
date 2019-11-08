#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
	
	
	printf("There %s %d program argument%s:\n", 
							
							argc == 1 ? "is" : "are",
							argc,
							argc == 1 ? "" : "s");
	

	for (int i = 0; i < argc; i++) {
		printf(" %s\n", argv[i]);
	}
	return EXIT_SUCCESS;
}
