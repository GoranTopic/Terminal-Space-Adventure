#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "rbt.h"
#include "mylib.h"


#define ISBLACK(x) ((NULL == (x)) || (BLACK == (x)->color))

#define ISRED(x) ((NULL != (x)) && (RED == (x)->color))

typedef enum { RED, BLACK } rbt_color;


struct rbt_node {	
/** Struct definition for a rbt_node*/
	char* key;
	rbt_color color;
	struct rbt_node* left;
	struct rbt_node* right;
	struct rbt_node* parent;

};



rbt rbt_new_node(char* key){
	/** make an node of the rbt with a given key*/
	
	rbt node = emalloc( sizeof *node );
 	node->key = emalloc( sizeof(key[0]) * (strlen(key)+1));
 	node->color = RED;
	strcpy(node->key, key);
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	return node;

}


rbt get_parent(rbt t, char* key, int* left_right){
	/** Is it the parent of the node we are looking for*/ 
	if(strcmp(t->key, key) == 0) return t; 
		/*check is t is root, return t is so	*/
	if(t->left != NULL){
		 if(strcmp(t->left->key, key) == 0){
				*left_right = 1;
				/*which son in the node we looking for*/
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
		/*if greater than, go left*/
	
	else if(strcmp(key, t->key) > 0) return get_parent(t->right, key, left_right);
		/*if less than, go righ*/

	printf("something, whent wrong with getting the parent\n");	
	return NULL;
}



int has_son(rbt node){
	
/** return 0 if node is leaf, 1 if it has left son
  	-1 if it has only right son, 2 if if it has two sons*/

	if(node->left != NULL){
		/*return 1 or 2*/
		if(node->right != NULL) return 2;
		else return 1;
	}else{
	 	if(node->right != NULL) return -1;
	 	else return 0;
	}
	printf("logic error, this should not be rpinted\n");
}



int free_node(rbt node){
	/** free the node and key*/
	free(node->key);
	free(node);
	return EXIT_SUCCESS;
}


void rbt_free_tree(rbt tree){
	/** frees a whole tree =D*/

	if(tree->left != NULL) rbt_free_tree(tree->left);
	
	if(tree->right != NULL) rbt_free_tree(tree->right);

	free_node(tree);
	
}


int remove_one_son(rbt doomed, rbt parent, int left_p){ 
	/** remove a node with only has one son */
	if(has_son(doomed) == 0){
 			
			(left_p == 1) ? (parent->left = NULL) : (parent->right = NULL); 
				/*set the parent pointer to NULL*/
			free_node(doomed);


	}else if(has_son(doomed) == 1){ /*left*/
			
		(left_p == 1) ? (parent->left = doomed->left) : (parent->right = doomed->left);
				
		free_node(doomed);
		
	}else if(has_son(doomed) == -1){ /*right*/
	 	
		(left_p == 1) ? (parent->left = doomed->right) : (parent->right = doomed->right);
				/*set the parent pointer to the left son*/
		free_node(doomed);	
	
	}else return EXIT_FAILURE;

	return EXIT_SUCCESS;
}



rbt get_successor(rbt node){
	/** get the left most values of the right sub tree */

	if(node->right != NULL){	
		rbt successor = node->right;

		while(successor->left != NULL){
			successor = successor->left;
		}
		return successor;
	}else if(node->left != NULL){

		rbt successor = node->left;
	
		while(successor->right != NULL){
			successor = successor->right;
		}
		return successor;	
	}else{
		fprintf(stderr, "Could not get successors, becuase node has no sons");
		return node;
	}
}


int is_root(rbt n){
	/** return 1 if it is root, 0 otherwise*/
	if(n->parent  == NULL) return 1;
	else return 0;

}

int get_height(rbt node){
	/** this fuction should return the height of a tree
	it recursibly enters the tree*/

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

	if(left_h > right_h) return ++left_h;
	else return ++right_h;

}

void swap_keys(rbt node1, rbt node2){
	/**Swap the keys of two nodes*/
	
	char temp[255];

	strcpy(temp, node1->key);
	/*get key to temp*/

	strcpy(node1->key, node2->key);
	
	
	strcpy(node2->key, temp);
 
}

int is_left_son(rbt son){
	/* returns true is the given node is the 
		left son of it's parent node*/
	rbt parent = son->parent;
	if(parent != NULL){
		if(son == parent->left)return 1;
		else return 0;
	}else{
		fprintf(stderr, "node is root, cannot check if it is left son\n");
		return 0;
	}

}



rbt rotate_right(rbt node){
	/** rotate the nodes right*/
	
	rbt new_n;
	
	if(node->left == NULL){
		fprintf(stderr, "cannot rotate right if node does not havel left son");
		return node;
	}else{



		new_n = node->left;

		if(new_n->right != NULL){
			node->left = new_n->right;
			new_n->right->parent = node;	
		} 
		else node->left = NULL;
		
		new_n->right = node;		
		if(is_root(node)){
			node->parent = new_n;
			new_n->parent = NULL;
		}else{
			new_n->parent = node->parent;
			if(is_left_son(node)) node->parent->left = new_n;
			else node->parent->right = new_n;
			node->parent = new_n;
		}

		return new_n;	
	}
	return node;
}


rbt rotate_left(rbt node){
	/** rotate the nodes right*/
	rbt root;
	
	if(node->right == NULL){
		fprintf(stderr, "cannot rotate left if node does not havel right son");
		return node;
	}else{
		
		root = node->right;

		if(root->left != NULL){ 
			node->right = root->left;
			root->left->parent = node;
		}
		else node->right = NULL;

		root->left = node;	
		if(is_root(node)){
			node->parent = root;
			root->parent = NULL;
		}else{
			root->parent = node->parent;
			if(is_left_son(node)) node->parent->left = root;
			else node->parent->right = root;
			node->parent = root;

		}

		return root;	
	}
	return node;
}



rbt rbt_remove(rbt t, char* key){
	/** searchs and removes a node from the rbt*/
	
	rbt root, parent, doomed, successor_p, successor;
	int is_left = 0;

	root = t;
	
	if(rbt_search(t, key) == 1) doomed = rbt_get(t, key);
	else{
			fprintf(stderr, "could not find key for removal\n");
	 		return t; 
	}
					
	if(is_root(doomed)){
		
		root = doomed;

		successor = get_successor(doomed);

		successor_p = get_parent(t, successor->key, &is_left);

		swap_keys(doomed, successor);

		remove_one_son(successor, successor_p, is_left);  	

		return root;
		
	}else{	
			/*check is key is in tree*/
		parent = get_parent(t, key, &is_left);
			/*get parent*/	
		if(is_left == 1) doomed = parent->left;
		else if(is_left == 2) doomed = parent->right;
		else doomed = parent;		/*get son*/
	} 
	
	if(has_son(doomed) == 2){
		/*if it has both sons*/
		
			successor = get_successor(doomed);
			
			successor_p = get_parent(t, successor->key, &is_left);
			
			swap_keys(doomed, successor); 
				
			remove_one_son(successor, successor_p, is_left);

	}else remove_one_son(doomed, parent, is_left);
		/*if it has one or no sons*/
	return t;
}


void rbt_print_inorder(rbt t){
	/**print a BST recursibly in order =D*/
	
	if(t->left != NULL) rbt_print_inorder(t->left);
		/*go left*/
	
	if(t != NULL) printf("%s, ", t->key);
		
	
	if(t->right != NULL)rbt_print_inorder(t->right);
		/*go right*/
}	


int rbt_search(rbt t, char* key){
		
	/** seaches recursibly the rbt for a key, return 1 if found
	0 otherwise*/
		
		if(strcmp(key, t->key) == 0) return 1;	
		
		else if(strcmp(key, t->key) < 0){
			if(t->left != NULL) return rbt_search(t->left, key);

		}else{
			if(t->right != NULL) return rbt_search(t->right, key);
		}

	return 0;
}


rbt rbt_get(rbt t, char* key){
	/** seaches recursibly the rbt for a key, return it if found*/
	
		if(strcmp(key, t->key) == 0){
			return t;	
		
		}else if(strcmp(key, t->key) < 0){
			if(t->left != NULL) return rbt_get(t->left, key);
			/*go left*/
		

		}else{
			if(t->right != NULL) return rbt_get(t->right, key);
			/*go right*/
		}

	fprintf(stderr, "something when wrong when trying to get node\n");
	return NULL;
}


rbt get_root(rbt node){
	/*Travel the root with it parent 
	  to reach the node with the parent NULL,
	  return that node*/
	rbt root = node;

	while(root->parent != NULL){
		root = root->parent;  
	}

	return root;
	
}


rbt fix_uncle_red(rbt son){
	/*Do the rotation for when the uncle of a node is red,
	  return the new node that is on top*/
	rbt p_node, grand_p, uncle;

	p_node = son->parent;
	grand_p = p_node->parent;	
	if(is_left_son(p_node)) uncle = grand_p->right;
	else uncle = grand_p->left;

	grand_p->color = RED;
	p_node->color = BLACK;
	uncle->color = BLACK;
return son;

}


int is_uncle_red(rbt son){
	/*returns true if the given node has an red uncle*/
	rbt p_node, grand_p, uncle;

	if(son->parent == NULL){ 
		fprintf(stderr,"is_uncle_red fuction call on root node\n");
		return 0;
	}else if(son->parent->parent == NULL){
		fprintf(stderr,"is_uncle_red fuction call on node with no granfather\n");
		return 0;
	}else{

		p_node = son->parent;
		grand_p = p_node->parent;
		
		if(is_left_son(p_node)) uncle = grand_p->right;
		else uncle = grand_p->left;

		if(uncle == NULL) return 0;
		else return ISRED(uncle);
	}
}


rbt black_uncle_roations(rbt son, rbt parent, rbt grandp){
	/*preforms a rotation with the given nodes, 
	handles the cases for when the red nodes are on the left or on the right, 
	or weather the last red is an innerchild or a outerchild */

	rbt grangran, root; 
	int is_leftchilds, is_innerchild, is_left_grandp, isroot = 0;

		if(is_root(grandp)) isroot = 1;
		else{
			if(is_left_son(grandp)) is_left_grandp = 1;
			else is_left_grandp = 0;
			grangran = grandp->parent;
		}	

		if(is_left_son(parent)){ 
			/*left childs*/
			is_leftchilds = 1;
			if(is_left_son(son)){
				/*is outtterchild*/
				is_innerchild = 0;
			}else{
				/*is inner child*/
				is_innerchild = 1;
			}
		}else{	
			/*right childs*/
			is_leftchilds = 0;
			if(is_left_son(son)){ 
				/*is inner child*/
				is_innerchild = 1;
			}else{
				/*is outerchild*/
				is_innerchild = 0;
			}
		}	
	
	if(is_innerchild){
		if(is_leftchilds){
			parent = rotate_left(parent);
			son = parent->left;
		}else{
			parent = rotate_right(parent);
			son = parent->right;
		}
	}

	parent->color = BLACK;
	grandp->color = RED;
	if(isroot == 0){
		if(is_left_grandp){
			if(is_leftchilds){ 
				grangran->left = rotate_right(grandp);
			}else{ 
				grangran->left = rotate_left(grandp);
			}
		}else{
			if(is_leftchilds) grangran->right = rotate_right(grandp);
			else grangran->right = rotate_left(grandp);
		}  
	}else{
		if(is_leftchilds) root = rotate_right(grandp);
		else root = rotate_left(grandp);

		return root;	
	} 
	return son;

}

rbt fix_uncle_black(rbt son){
	/**Fixes the cases when uncle is black, 
	it calles on black_uncle_roations() to handle the 
	difrentcases and make the roations
	return a rtb node*/
	rbt parent, grand_p;

	if(son->parent == NULL){ 
		fprintf(stderr,"fix_uncle_black fuction call on root node\n");
		return son;
	}else if(son->parent->parent == NULL){
		fprintf(stderr,"fix_uncle_black fuction call on node with no granfather\n");
		return son;
	}else{
		parent = son->parent;
		grand_p = parent->parent;
		
	}
	return black_uncle_roations(son, parent, grand_p);
}


int rb_check(rbt t){
	/*checks the tree for an ocurance of two red nodes next to each other.
	returns true if the changes where succesful*/ 	

	if(t == NULL) return 1;
	
	if(is_root(t)) t->color = BLACK; /*keep the root black*/
	
	
	if(ISRED(t) && ISRED(t->parent)){

		if(is_uncle_red(t)){ 
			/*uncle is red*/

			t = fix_uncle_red(t);

			return 0;

		}else{ 
		
			t = fix_uncle_black(t);
			
			return 0;
		}
	}

	rb_check(t->left);	

	rb_check(t->right);

	return 1;
	
}


rbt insertion(rbt t, rbt parent, char* key){

	if(t == NULL){	
		rbt node = rbt_new_node(key);
		if( parent == NULL){				
		 	node->parent = NULL;
		}else{	
		 	node->parent = parent;	
		}
		node->color = RED;	
		t = node;
		
		return t;
	
	}else if(strcmp(key, t->key) == 0){

		fprintf(stderr, "Node already in Binary search tree\n");
		return t;

	}else if(strcmp(key, t->key) < 0){
			/*the node we want to append is smaller, go left*/
			
		t->left = insertion(t->left, t, key);
		
	}else{ 
			/*node is bigger, thus go right*/
		t->right = insertion(t->right, t,  key);
		
	}

	return t;
	
}


rbt rbt_insert(rbt t, char* key){
	/**appends to node the the binary search tree return the new ponter to the rbt */
	
	rbt node;

	node = insertion(t, NULL, key);	

	while(rb_check(node) != 1){
		node =  get_root(node);
	}

	node =  get_root(node);
	
	return node;
	
}






