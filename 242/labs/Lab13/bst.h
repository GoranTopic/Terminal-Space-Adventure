#ifndef BST_H_
#define BST_H_
#include <stdio.h>

typedef struct bst_node* bst;


extern void bst_free(bst t);

extern void bst_print_inorder(bst t);

extern void bst_print_preorder(bst t);

extern void bst_printg(bst t);

extern void bst_print_node(bst n);

extern bst bst_new_node(char* key);

extern int bst_search(bst t, char* key);

extern bst bst_insert(bst t, char* key);

extern bst bst_remove(bst t, char* key);

#endif
