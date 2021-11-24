#ifndef LINKED_LIST_OBJ_H_
#define LINKED_LIST_OBJ_H_

typedef struct Linked_list_node {
  /* a node for the linked list of objects*/
    Object* obj; //object which is held in the node
    struct Linked_list_node* next;
    struct Linked_list_node* prev;

} Node;

typedef struct Linked_list_head {
  /* Linked list for managing and storing objects */
  Node* first;
  Node* Last;
  int count;
} List;


extern void node_free(Node* node);

extern List* list_make(void);
extern void list_free(List* list);
extern void list_append(List* list, Object* obj);
extern void list_print(List* list);
extern void list_remove_at(List* list, int index);
extern void list_remove_title(List* list, char* title);
extern Object* list_get_at(List* list, int index);
extern Object* list_get_title(List* list, char* title);

#endif
