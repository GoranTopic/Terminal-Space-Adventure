extern void list_append(List* list, Object* obj);
  /* Linked list for managing and storing objects */
extern void list_free(List* list);
    struct Linked_list_node* next;
#endif
extern void list_print(List* list);
typedef struct Linked_list_head {
} Node;
    struct Linked_list_node* prev;
    Object* obj; //object which is held in the node
extern Object* list_get_at(List* list, int index);
extern void node_free(Node* node);
#ifndef LINKED_LIST_OBJ_H_
#define LINKED_LIST_OBJ_H_
extern void list_remove_title(List* list, char* title);
extern List* list_make(void);







typedef struct Linked_list_node {
extern Object* list_get_title(List* list, char* title);
} List;
extern void list_remove_at(List* list, int index);
  Node* Last;
  int count;
  Node* first;
  /* a node for the linked list of objects*/
