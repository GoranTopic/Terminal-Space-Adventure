#ifndef ARRAY_OBJ_H_
#define ARRAY_OBJ_H_

typedef struct Objects_Array{
	/*object structure for managing and mantaining array of objects*/
	Object* objs;
	int count;
	int capacity;
} Obj_arr;

extern Obj_arr* make_obj_ar(int size);
extern void remove_obj_at(Obj_arr* array, int index);
extern void append_obj(Obj_arr* array, Object* obj);
extern void print_array(Obj_arr* array);

#endif
