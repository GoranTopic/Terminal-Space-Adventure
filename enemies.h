#include "array_obj.h"
#ifndef ENEMIES_H_
#define ENEMIES_H_

/*
	 functions for defining and loading enemies
 */

extern Obj_arr* load_enemies_ar(void);
extern Object* random_enemy(int max_x, int max_y, Obj_arr* enemies);


#endif
