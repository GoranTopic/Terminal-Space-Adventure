#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
	an Object library 	
	 
	by Goran Topic
 */

struct Char_Point {
		/* A point structure for saving the characters and cordinate of an object*/
		int x, y;
		char ch;
};
typedef struct Char_Point Point_ch;


struct Object {
		/*A Structure for managin and renddering objects*/
		Point_ch start; //starting point
		char* title; //name of obj
		char** model; //array of str that make out the obj
		int model_c; // keep track of the number of line the drwaing 
		Point_ch* points; // char points
		int points_c; //count of the char points
		int speed;  // how a object moves
		int direction; //direction the obj move on
		bool alive; //is obj alive?
};
typedef struct Object Object;


struct Objects_Array{
	/*object structure for managing and mantaining array of objects*/ 
	Object* objs;
	int count;
	int capacity;
};
typedef struct Objects_Array Obj_arr;


struct Linked_list_node {
	/* a node for the linked list of objects*/

		Object* obj; //object which is held in the node
		
		struct Linked_list_node* next;
		struct Linked_list_node* prev;

};
typedef struct Linked_list_node Node;


struct Linked_list_head {
	/* Linked list for managing and storing objects */

	Node* first;
	Node* Last;
	int count;

};
typedef struct Linked_list_head List;

void print_point(Point_ch p){
  /*print  a point to std*/
  printf("(y:%d, x:%d, %c)\n", p.y, p.x, p.ch);

}

void print_obj(Object obj){
    /*prints obj from a given obj to std*/
    printf("title: %s \n", obj.title); 
    printf("alive: %d \n", obj.alive);
    printf("speed: %d \n", obj.speed);

    //print model object
    for(int line = 0; line < obj.model_c; line++){
        printf("%s\n", obj.model[line]);
    }

    //print points 
    printf("Points:\n");
    for(int i = 0; i < obj.points_c; i++){
      print_point(obj.points[i]);
    } 
    printf("\n");
}


Object* make_obj(char* title, char* model[], int model_c, int speed, Point_ch start){
	/* alloactes memory and initliizes new object */
	bool cutoff_space;
	int point_c = 0;
 
	//alloc mem for struct
	Object* obj = malloc(sizeof(Object));

	//copy model's count of strings
	obj->model_c = model_c;

	//cpy speed
	obj->speed = speed;

	//set diection
	obj->direction = 0;

	//set alive;
	obj->alive = true;

	//alloc mem to store model's strs
	obj->model = malloc(model_c * sizeof(char*)); 

	//alloc mem and store title of the obj
	obj->title = malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(obj->title, title); // copy title to obj
		
	//get the number of points need to store the char points
	//and copy the model's string into the obj's model mem
	obj->points_c= 0;
	for(int i = 0; i < model_c; i++){	
		obj->model[i] = malloc(sizeof(char) * (strlen(model[i]) +1) );
		strcpy(obj->model[i], model[i]);
		obj->points_c += strlen(obj->model[i]);
	}	
	

	//alloc mem for the need points
	obj->points = malloc(obj->points_c * sizeof(Point_ch));
	


	//make a char point for every char in string array, and store it in obj's mem
	//excluding any space at the begining of the string
	for(int y = 0; y < model_c; y++){
			cutoff_space = false;
			for(int x = 0; x < strlen(model[y]); x++){
				if(model[y][x] != ' ') cutoff_space = true;
				if(cutoff_space){
					obj->points[point_c].x = start.x + x;
					obj->points[point_c].y = start.y + y;
					obj->points[point_c].ch = model[y][x];
					point_c++;
				}
			}
	}
	//update the point_c as to not count the cutoff_spaces
	obj->points_c = point_c; 

	return obj;
}

void free_obj(Object* obj){
	/*realses allocated memory*/

	//free array of char points
	free(obj->points);
	

	//relase model's strs 
	for(int i = 0; i < obj->model_c; i++){	
		free(obj->model[i]);
	}

	//free obj title 
	free(obj->title);

	//free model array
	free(obj->model);	

	//free obj structure
	free(obj);

}


void move_obj(Object* obj, int direction){
    /* changes the corinate of the obj towards the direction passed*/
    int xdlta;
    int ydlta;
    //traslate deegre into x and y changes
    switch(direction){
        case 0:
            ydlta = -1;
            xdlta = 0;
            break;
        case 45:
            ydlta = -1;
            xdlta = 1;
            break;
        case 90:
            ydlta = 0;
            xdlta = 1;
            break;
        case 135:
            ydlta = 1;
            xdlta = 1;
            break;
        case 180:
            ydlta = 1;
            xdlta = 0;
            break;
        case 225:
            ydlta = 1;
            xdlta = -1;
            break;
        case 270:
            ydlta = 0;
            xdlta = -1;
            break;
        case 315:
            ydlta = -1;
            xdlta = -1;
            break;
        case 360:
            ydlta = -1;
            xdlta = 0;
            break;
        default:
            ydlta = 0;
            xdlta = 0;
    }

    for(int i = 0; i < obj->points_c; i++){
        //add the dlta values to the obj points 
        obj->points[i].y =  obj->points[i].y + ydlta;
        obj->points[i].x = obj->points[i].x + xdlta;
    }
}

void kill_obj(Object* obj){
	/* sets obj as dead*/
	obj->alive =	false;
}

Obj_arr* make_obj_ar(void){
	/* make and array of Objects */

	Obj_arr* arr = malloc(sizeof(Obj_arr));
	arr->capacity = 5;
	arr->objs = calloc(arr->capacity, sizeof(Object));
	arr->count = 0;
	
	return arr;
} 



void remove_obj_at(Obj_arr* array, int index){
	/* removes an obj from the array of objs */


		if(index >= array->count){
			// index greater
			printf("ERROR: Could not remove index higher than count\n");
			return;
		}else if ( index == array->count - 1){
			//remove last element 
			//free_obj( &(array->objs[array->count -1]));
			array->count--;
			return;
		}else{

				Object last = array->objs[array->count - 1];
				array->objs[index] = last;
				//free_obj( &(array->objs[array->count - 1]) );
				array->count--;
				
		}

}

void append_obj(Obj_arr* array, Object* obj){
	/* appends a obj to the array of Objs */
	
	
	if(array->count >= array->capacity){
	//it it reaches capacity then get more
		array->capacity *= 2;
		array->objs =  realloc(array->objs, array->capacity);
	}	
	
	array->objs[array->count] = *obj;
	array->count++;
}



void print_array(Obj_arr* array){
	/*print the array*/

		for(int i = 0; i < array->count; i++){
				//print model object
				printf(" %s \n", array->objs[i].title);
				for(int line = 0; line < array->objs[i].model_c; line++){
						printf("%s\n", array->objs[i].model[line]);
				}
				printf("\n");
		}

		printf("count: %d\n", array->count);



}


List* make_list(void){
	/*  allocate a memory for the head of the list */
		List* list = malloc(sizeof(List));
		list->count =0;
		list->first = NULL;
		return list;
}

void free_node(Node* node){
	free_obj(node->obj);
	free(node);
}

void append_list(List* list, Object* obj){
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

void print_list(List* list){
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

		free_node(current);
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
						free_node(current);
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



int main(void) {
	
	char* model[]  = {  "  -/|",
	                		"<=[#]:",
		                	"  -\\|"};
	Point_ch start = { .x = 3, .y = 3, .ch = ' '};
	Object* start_ship =  make_obj("start_ship", model, 3, 1, start);


	char* model2[]  = {" |\\=",
		           			 "C==[X]",
		          			 " |/="};
	Point_ch start2 = { .x = 8, .y = 5, .ch = ' '};
	Object* mauler =  make_obj("mauler", model2, 3, 1, start);


	char* model3[]  = {"<=-=-==:",
		           			 "  [H]D",
		          			 "<=-=-==:"};
	Point_ch start3 = { .x = 15, .y = 5, .ch = ' '};
	Object* floater =  make_obj("floater", model3, 3, 1, start);
	

	char* model4[]  = {"  /\\",
		           			 "-<[+]:",
		          			 "  \\/"};
	Point_ch start4 = { .x = 15, .y = 5, .ch = ' '};
	Object* quicky =  make_obj("quicky", model4, 3, 1, start);


	char* model5[]  = {"  { |",
		           			 " <=[o][:",
		          			 "  { |"};
	Point_ch start5 = { .x = 15, .y = 5, .ch = ' '};
	Object* falco =  make_obj("falco", model5, 3, 1, start);

	List* list = make_list();


	append_list(list, start_ship);
	append_list(list, mauler);
	append_list(list, floater);
	append_list(list, quicky);
	append_list(list, falco);

	print_list(list);

	//list_remove_at(list, 0);
	list_remove_title(list, "start_ship");
	 
	
	print_list(list);

	print_obj(*(list_get_at(list, 0)));
	//it crashes when it reallocates mememory 


}
