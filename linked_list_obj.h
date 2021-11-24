#endif
extern Object* list_get_title(List* list, char* title);
typedef struct Linked_list_node {
extern void node_free(Node* node);
    struct Linked_list_node* prev;
extern Object* list_get_at(List* list, int index);
extern void list_append(List* list, Object* obj);
#define LINKED_LIST_OBJ_H_
    Object* obj; //object which is held in the node
#ifndef LINKED_LIST_OBJ_H_
  /* a node for the linked list of objects*/
extern void list_print(List* list);
typedef struct Linked_list_head {
  Node* first;
    struct Linked_list_node* next;
extern void list_remove_title(List* list, char* title);
  int count;
extern void list_free(List* list);
extern List* list_make(void);
extern void list_remove_at(List* list, int index);
} Node;







  /* Linked list for managing and storing objects */
  Node* Last;
} List;
