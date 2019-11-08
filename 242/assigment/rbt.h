#ifndef RBT_H_
#define RBT	_H_

#include <stdio.h>

typedef struct rbt_node* rbt;


extern rbt rotate_left(rbt n);

extern rbt rotate_right(rbt n);

extern void rbt_free_tree(rbt t);

extern void rbt_print_inorder(rbt t);

extern void rbt_print_preorder(rbt t);

extern void rbt_printg(rbt t);

extern void rbt_print_node(rbt n);

extern rbt rbt_new_node(char* key);

extern rbt rbt_get(rbt t, char* key);

extern int rbt_search(rbt t, char* key);

extern rbt rbt_insert(rbt t, char* key);

extern rbt rbt_remove(rbt t, char* key);

#endif
