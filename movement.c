#include "movement.h"
#include "objects.h"
#include <string.h>

void move_by_type(Object* obj){
		/* it moves an objecst based on type */
		if(strcmp(obj->title, "mauler") == 0){
				if(obj->state < 80 ){
						move_obj(obj, 90);
				}else if(obj->state > 80){
						move_obj(obj, 270);
				}else if(obj->state == 160){
						obj->state = 0;
				}
				obj->state++;
		}else if(strcmp(obj->title, "falco") == 0){
				if(obj->state < 80 ){
						move_obj(obj, 270);
				}else if(obj->state > 80){
						move_obj(obj, 90);
				}else if(obj->state == 160){
						obj->state = 0;
				}
				obj->state++;
	
		}else if(strcmp(obj->type, "ship -del me") == 0){
				if(obj->state < 80 ){
						move_obj(obj, 270);
				}else if(obj->state > 80){
						move_obj(obj, 90);
				}else if(obj->state == 160){
						obj->state = 0;
				}
				obj->state++;

		}else if(strcmp(obj->type, "enemy") == 0){
				if(obj->state % 10 == 0){
						move_obj(obj, 90);
				}else if(obj->state > 100){
						obj->state = 0;
				}
				obj->state++;



		
		}else if(strcmp(obj->type, "bullet") == 0){
				//printf("it moved\n");
				move_obj(obj, 270);
				obj->life = obj->life - 2;
		}
		obj->state++;
}

