    struct Linked_list_node* next;
    struct Linked_list_node* prev;
extern void list_remove_title(List* list, char* title);
#ifndef LINKED_LIST_OBJ_H_
extern void list_free(List* list);
typedef struct Linked_list_node {
extern void list_remove_at(List* list, int index);
extern void node_free(Node* node);
extern List* list_make(void);
} List;
#define LINKED_LIST_OBJ_H_
extern Object* list_get_at(List* list, int index);
} Node;
#endif
extern void list_print(List* list);
extern Object* list_get_title(List* list, char* title);
  /* Linked list for managing and storing objects */
typedef struct Linked_list_head {
extern void list_append(List* list, Object* obj);
  int count;
  Node* Last;







  /* a node for the linked list of objects*/
    Object* obj; //object which is held in the node
  Node* first;
