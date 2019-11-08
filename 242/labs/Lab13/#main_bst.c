

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include "mylib.h"
#include "bst.h"



int main(void){
	
	bst node, tree;
	//bst_print_node(node);
	

	//make a treei
	
	tree = bst_insert(tree, "1");
	tree = bst_insert(tree, "6");
		
	tree = bst_insert(tree, "0");
	tree = bst_insert(tree, "2");
	tree = bst_insert(tree, "4");
	tree = bst_insert(tree, "5");
	tree = bst_insert(tree, "7");
	tree = bst_insert(tree, "S");
	tree = bst_insert(tree, "3");
	tree = bst_insert(tree, "8");
	tree = bst_insert(tree, "A");
	tree = bst_insert(tree, "9");
	
	bst_printg(tree);
	
	//printf("is 5 bigger the 6: %d\n", strcmp("5", "6"));
		
	printf("is 1 in tree? : %d\n", bst_search(tree, "1"));

	printf("removing node\n");

	bst_remove(tree, "1");

	printf("is still 1 in the tree? : %d\n", bst_search(tree, "1"));
	
	bst_printg(tree);
		return EXIT_SUCCESS;
}
