#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bst.h"
#include "mylib.h"


struct bst_node {
	/** Struct definition for a bst_node*/
	char* key;
	struct bst_node* left;
	struct bst_node* right;

};

	


bst bst_new_node(char* key){
	/** make an node of the bst with a given key*/
	
	bst node = emalloc( sizeof *node ); //confused on how this works scince we are assigning 
 	node->key = emalloc( sizeof(key[0]) * (strlen(key)+1));
	strcpy(node->key, key);
	node->left = NULL;
	node->right = NULL;
	return node;

}


bst get_parent(bst t, char* key, int* left_right){
	
/** is it the parent of the node we are looking for*/ 
	if(strcmp(t->key, key) == 0) return t; // t is root	

	if(t->left != NULL){
		 if(strcmp(t->left->key, key) == 0){
				*left_right = 1;//which son in the node we looking for
			 	return t;
			}
	}
	if(t->right != NULL){
			if(strcmp(t->right->key, key) == 0){
				*left_right = 2;
			 	return t;
			}
	}
	

	if(strcmp(key, t->key) < 0) return get_parent(t->left, key, left_right);
		//if greater than, go left
	
	else if(strcmp(key, t->key) > 0) return get_parent(t->right, key, left_right);
		//if less than, go right

	printf("something, whent wrong with getting the parent\n");	
}





int has_son(bst node){
	
/** return 0 if node is leaf,
		1 if it has left son
  	-1 if it has right son 
		2 if if it has two sons*/

	if(node->left != NULL){
		//return 1 or 2
		if(node->right != NULL) return 2;
		else return 1;
	}else{
	 	if(node->right != NULL) return -1;
	 	else return 0;
	}
	printf("logic error, this should not be rpinted\n");
}




int free_node(bst node){
	
/** free the node and key*/
	free(node->key);
	free(node);
}



int remove_one_son(bst doomed, bst parent, int left_p){ 
/** remove a node with only has one son */
	if(has_son(doomed) == 0){
 			
			(left_p == 1) ? (parent->left = NULL) : (parent->right = NULL); 
				//set the parent pointer to NULL
			free_node(doomed);


	}else if(has_son(doomed) == 1){ //left
			
		(left_p == 1) ? (parent->left = doomed->left) : (parent->right = doomed->left);
				
		free_node(doomed);
		
	}else if(has_son(doomed) == -1){ //right
	 	
		(left_p == 1) ? (parent->left = doomed->right) : (parent->right = doomed->right);
				//se the parent pointer to the left son
		free_node(doomed);	
	
	}else return EXIT_FAILURE;

	return EXIT_SUCCESS;
}


bst successr(bst node){
	printf("node: %s, node->left %p\n", node->key, node->left );
	if(node->left == NULL) return node;
	else successr(node->left);	
}

bst get_successor(bst node){
	
/** get the left most values of the right sub tree */
		
	return successr(node->right); 


}



int get_height(bst node){
		
/** this fuction should return the height of a tree*/
		int left_h = 0, right_h = 0;

	if(node == NULL) return -1;
	else{

		if(node->left != NULL){
			 left_h = get_height(node->left);		
		}

		if(node->right != NULL){

			 right_h = get_height(node->right);
		}
	}
	//printf("left_h: %d, right_h: %d\n", left_h, right_h);
	if(left_h > right_h) return ++left_h;
	else return ++right_h;

}

void swap_keys(bst node1, bst node2){
	char temp[255];

	strcpy(temp, node1->key);
	//get key to temp

	strcpy(node1->key, node2->key);
	
	
	strcpy(node2->key, temp);
 
}



bst bst_remove(bst t, char* key){

/** removes a node from the bst*/
	bst parent, doomed, successor_p, successor;
	int lr_d = 0;
//check is key is in tree
		 	//printf("search start for %s \n", key);
	if(bst_search(t, key) == 0){
		//return if the key is not in the tree
		fprintf(stderr, "could not find key for removal\n");
 		return t; 
	}
		
	parent = get_parent(t, key, &lr_d);
		//get parent	

	if(lr_d == 1) doomed = parent->left;
	else if(lr_d == 2) doomed = parent->right;
	else doomed = parent;		//get son

	//printf("parent: %p , parent->key:%s, doomed->key %s, left_right: %d\n", parent, parent->key, doomed->key, lr_d);
	 
	
	if(has_son(doomed) == 2){
		//if it has both sons
			//printf("successor: %s\n", get_successor(doomed)->key);
				successor = get_successor(doomed);
				successor_p = get_parent(t, successor->key, &lr_d);
				swap_keys(doomed, successor); 
				
				remove_one_son(successor, successor_p, lr_d);

				


	}else remove_one_son(doomed, parent, lr_d);
		//if it has one or no sons
}


void bst_print_inorder(bst t){
	
/**print a BST recursibly in orther =D*/
	
	if(t->left != NULL) bst_print_inorder(t->left);
			//go left
		

	bst_print_node(t);
		
	
	if(t->right != NULL) bst_print_inorder(t->right);
			//go right
	
}



void bst_print_preorder(bst t){
	
/**print a BST recursibly =D*/

	if(t != NULL) bst_print_node(t);

	if(t->left != NULL) bst_print_preorder(t->left);
			//go left	
	
	if(t->right != NULL) bst_print_preorder(t->right);
			//go right
	
}

void bst_print_node(bst node){
	
//print single node
	int spaces = 5;	
 	
	
	
	printf("\n   key:%s\n", node->key);
	printf("  /        \\ \n");

	if(node->left == NULL) printf("%p", node->left);
	else printf("%s", node->left->key);
  
	printf("%*c", spaces, ' ');
	
	if(node->right == NULL) printf("%p\n\n", node->right);
	else printf("%s\n\n", node->right->key);
  


}



int bst_search(bst t, char* key){
		
	/** seaches recursibly the bst for a key, return 1 if found*/
//QUESTION: whe i change the return type to bst, it give core dump segemetation, why does it not work when returning a pointer?

	//printf("\nt->key %s, key %s\n", t->key, key);
	//printf("strcmp = %d\n", strcmp(key, t->key));	
	
	if(strcmp(key, t->key) == 0){
			return 1;	
		
		}else if(strcmp(key, t->key) < 0){
			if(t->left != NULL) return bst_search(t->left, key);
			//go left
		

		}else{
			if(t->right != NULL) return bst_search(t->right, key);
			//go right
		}

	return 0;
}




bst bst_get(bst t, char* key){
		
	/** seaches recursibly the bst for a key, return 1 if found*/
//QUESTION: whe i change the return type to bst, it give core dump segemetation, why does it not work when returning a pointer?

	printf("\nt->key %s, key %s\n", t->key, key);
	printf("strcmp = %d\n", strcmp(key, t->key));	
	
	
		if(strcmp(key, t->key) == 0){
			return t;	
		
		}else if(strcmp(key, t->key) < 0){
			if(t->left != NULL) return bst_get(t->left, key);
			//go left
		

		}else{
			if(t->right != NULL) return bst_get(t->right, key);
			//go right
		}


	return NULL;
}


/**

	printf("key: %s\n ", key);	
	if(t->key != NULL){
			printf("so far so good");
		 printf("t->Key: %s\n", t->key);
	}
 if(strcmp(t->key, key) == 0){
		printf("is equal");
		 return t;		 
		//if found
	
	}else if(strcmp(t->key, key) > 0){

		printf("smaller");
		if(t->left != NULL)  bst_search(t->left, key);
			//if smaller go left
	
	}else{
		printf("greater");
		if(t->right != NULL) bst_search(t->right, key);
			//if greater go right
	}

}

*/

bst bst_insert(bst t, char* key){
	
/**append to node the the binary search tree return the new ponter to the bst */
		

	if(t == NULL){
		bst node = bst_new_node(key);	
		t = node;
		return t;
	
	}else if(strcmp(key, t->key) == 0){

		fprintf(stderr, "node already in Binary search treei\n");
		return t;

	}else if(strcmp(key, t->key) < 0){
			//the node we want to append is smaller, thus go left
		t->left = bst_insert(t->left, key);
		
	}else{ //node is bigger, thus go right
		t->right = bst_insert(t->right, key);
		
	}

	return t;

}


int _print_t(bst tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%3s)", tree->key);

    int left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}

void bst_printg(bst tree)
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}






