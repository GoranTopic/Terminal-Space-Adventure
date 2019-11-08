#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mylib.h"
#include "queue.h"
#include "graph.h"




int main(void){

	int num1, num2, vertexc;
 	graph g;

	
	/*if((file = openfile(args, 1, argc)) == NULL) return EXIT_FAILURE;*/

	if(1 != (scanf("%d", &vertexc)))return EXIT_FAILURE;
	
	g = graph_new(vertexc);

	while(2 == (scanf("%d %d", &num1, &num2))){
		/*reading from dictinary*/

		/*printf("num1 %d, num2 %d\n", num1, num2);*/
		graph_add_edge(g, num1, num2, 1);	
	}

	
	graph_print(g);


	graph_bfs(g, 1);
		
	graph_print_bfs(g);

	graph_free(g);

return EXIT_SUCCESS;
}



