#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include "mylib.h"
#include "rbt.h"



int main(int argnum, char** args){

 //char* node = "T";
	FILE* file;
	char* word = emalloc(sizeof(char) * (30 + 1));
	 
	rbt tree = rbt_new_node(" ");	//rbt_print_node(node);

	file = openfile(args, 1, argnum);
	
	while(1 == (fscanf(file,"%s", word))){
		/*reading from dictinary*/
		tree = rbt_insert(tree, word);
	}

/*
	tree = rbt_insert(tree, "l");
	tree = rbt_insert(tree, "i");
	tree = rbt_insert(tree, "f");
	tree = rbt_insert(tree, "j");
	tree = rbt_insert(tree, "g");
	tree = rbt_insert(tree, "k");
	tree = rbt_insert(tree, "d");
	tree = rbt_insert(tree, "a");
	tree = rbt_insert(tree, "e");
	tree = rbt_insert(tree, "b");
	tree = rbt_insert(tree, "c");
		//make a treei
	
	tree = rbt_insert(tree, "X");
	tree = rbt_insert(tree, "H");
	tree = rbt_insert(tree, "A");

	tree = rbt_insert(tree, "3");
	tree = rbt_insert(tree, "c");
	tree = rbt_insert(tree, "6");
	tree = rbt_insert(tree, "t");
	tree = rbt_insert(tree, "0");
	tree = rbt_insert(tree, "2");
	tree = rbt_insert(tree, "4");
	tree = rbt_insert(tree, "5");
	tree = rbt_insert(tree, "7");
	tree = rbt_insert(tree, "S");
	tree = rbt_insert(tree, "3");
	tree = rbt_insert(tree, "8");
	tree = rbt_insert(tree, "A");
	tree = rbt_insert(tree, "Q");
	tree = rbt_insert(tree, "W");
	tree = rbt_insert(tree, "&");
	tree = rbt_insert(tree, "$");
	tree = rbt_insert(tree, "@");
	tree = rbt_insert(tree, "%");
	tree = rbt_insert(tree, "#");
*/

	//rbt_printg(tree);
		
	//printf("is %s  in tree? : %d\n", node, rbt_search(tree, node));

	//printf("removing node %s\n", node);

	//rbt_remove(tree, node);

	//printf("is still %s in the tree? : %d\n",node , rbt_search(tree, R 2)node));


	//printf("getting node %p\n", rbt_get(tree, node));

	
	//rbt_printg(tree);
		
	//rbt_free_tree(tree);	

	return EXIT_SUCCESS;
	
}
