#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include "mylib.h"
#include "rbt.h"



int main(void){
	
	rbt tree = rbt_new_node("key");	//rbt_print_node(node);
	

	//make a treei
	
	tree = rbt_insert(tree, "1");
	tree = rbt_insert(tree, "6");
		
	tree = rbt_insert(tree, "0");
	tree = rbt_insert(tree, "2");
	tree = rbt_insert(tree, "4");
	tree = rbt_insert(tree, "5");
	tree = rbt_insert(tree, "7");
	tree = rbt_insert(tree, "S");
	tree = rbt_insert(tree, "3");
	tree = rbt_insert(tree, "8");
	tree = rbt_insert(tree, "A");
	tree = rbt_insert(tree, "9");
	
	rbt_printg(tree);
		
	printf("is 1 in tree? : %d\n", rbt_search(tree, "1"));

	printf("removing node\n");

	rbt_remove(tree, "1");

	printf("is still 1 in the tree? : %d\n", rbt_search(tree, "1"));

	printf("getting node %p", rbt_get(tree, "A"));
	rbt_printg(tree);
	
		return EXIT_SUCCESS;
}
