#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "objects.h"
#include "array_obj.h"

/*
Array strcuture for objects, but it it only workes for 50 obj,
becuase reallocation is not working
	by Goran Topic
*/

Obj_arr* make_obj_ar(void){
	// make and array of Objects 
	Obj_arr* arr = malloc(sizeof(Obj_arr));
	arr->capacity = 5;
	arr->objs = calloc(arr->capacity, sizeof(Object));
	arr->count = 0;
	return arr;
} 

void remove_obj_at(Obj_arr* array, int index){
	// removes an obj from the array of objs 
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
	// appends a obj to the array of Objs 
	if(array->count >= array->capacity){
	//it it reaches capacity then get more
		array->capacity *= 2;
		array->objs =  realloc(array->objs, array->capacity);
	}	
	array->objs[array->count] = *obj;
	array->count++;
}

void print_array(Obj_arr* array){
	//print the array
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

