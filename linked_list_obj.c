#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "objects.h"
#include "linked_list_obj.h"

/*
 	Libaray of definition of linked list for objects
	by Goran Topic
 */

List* list_make(void){
	/*  allocate a memory for the head of the list */
		List* list = malloc(sizeof(List));
		list->count =0;
		list->first = NULL;
		return list;
}

void node_free(Node* node){
	free_obj(node->obj);
	free(node);
}

void list_free(List* list){
	/* free up the memory used in the whole of the list*/
	Node* current = list->first;
	Node* prev = current;
	while(current->next != NULL){
		prev = current;
		current = current->next;
		node_free(prev);
	}
	node_free(current);
	free(list);
}

void list_append(List* list, Object* obj){
		/* adds and obj to the list */
		//make new node
		Node* new_node = malloc(sizeof(Node));
		new_node->next = NULL;
		new_node->obj = obj;
		if(list->count == 0){
				list->first = new_node;
		}else{
			Node* current = list->first;
			while(current->next != NULL) current = current->next;
			current->next = new_node;
		}
		list->count++;
}

void list_print(List* list){
		/* prints the contento of the list of objs */	
		if(list->first == NULL || list->count == 0){
				//link list is empty
				printf("ERROR: could not print empty link list\n");
				return;
		}
		Node* current = list->first;
		while(true) {
				printf(" %s \n", current->obj->title); //print title
				for(int line = 0; line < current->obj->model_c; line++)
						printf("%s\n", current->obj->model[line]);
				printf("\n");
				if(current->next != NULL) current = current->next;
				else break;
		}	
		printf("count: %d\n", list->count);
}

void list_remove_at(List* list, int index){
	/*removes an element from the list at the index position and frees it's memory*/
		if(index >= list->count){
			printf("ERROR: could not remove at index greater then count of elemesnts\n");
			return;
		}		
		
		Node* current = list->first;
		Node* prev = current;
		for(int i = 0; i < index; i++){
			prev = current;
			current = current->next;
		}
		
		if(prev != current) prev->next = current->next; //if is is not the first node
		else list->first = current->next; //if ti is the frist node 
		//eliminate remove the node from the list
		list->count--;

		node_free(current);
}


void list_remove_title(List* list, char* title){
		/*removes an element from the list at the if it matches the given title and frees it's memory*/
		if(list->first == NULL || list->count == 0){
				//link list is empty
				printf("ERROR: could find title obj to remove in empty link list\n");
				return;
		}
		Node* current = list->first;
		Node* prev = current;

		while(true){  
				if(strcmp(current->obj->title, title) == 0){
						printf("found: title: %s \n", current->obj->title);
						//node title found
						if(prev == current) list->first = current->next; //if ti is the frist node 
						else prev->next = current->next; //if is is not the first node 
						//eliminate remove the node from the list
						list->count--;
						node_free(current);
						return;
				}
				if(current->next != NULL){
						prev = current;
						current = current->next;
				}else break;
		}	
		printf("ERROR: title: %s could not be found\n", title);
}

Object* list_get_at(List* list, int index){
	/*removes an element from the list at the index position and frees it's memory*/
		if(index >= list->count){
			printf("ERROR: could not get obj at index greater then count of elemesnts\n");
			return NULL;
		}	
		
		Node* current = list->first;
		for(int i = 0; i < index; i++){
			current = current->next;
		}
		
		return current->obj;
}


Object* list_get_title(List* list, char* title){
		/*removes an element from the list at the if it matches the given title and frees it's memory*/
		if(list->first == NULL || list->count == 0){
				//link list is empty
				printf("ERROR: could find title obj to remove in empty link list\n");
				return NULL;
		}

		Node* current = list->first;

		while(true){  
				if(strcmp(current->obj->title, title) == 0) return current->obj;
				if(current->next != NULL) current = current->next;
				else break;
		}	
		printf("ERROR: title: %s could not be found\n", title);
}

