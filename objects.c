#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "objects.h"
#include "linked_list_obj.h"

/*
	an Object library 	
	by Goran Topic
 */

void print_point(Point_ch p){
  /*print  a point to std*/
  printf("(y:%d, x:%d, %c)\n", p.y, p.x, p.ch);

}

void print_obj(Object* obj){
    /*prints obj from a given obj to std*/
    printf("title: %s \n", obj->title); 
    printf("life: %d \n", obj->life);
    printf("speed: %d \n", obj->speed);

    //print model object
    for(int line = 0; line < obj->model_c; line++){
        printf("%s\n", obj->model[line]);
    }

    //print points 
    printf("Points:\n");
    for(int i = 0; i < obj->points_c; i++){
      print_point(obj->points[i]);
    } 
    printf("\n");
}


Object* make_obj(char* title, char* model[], int model_c, int speed, Point_ch start, char* type){
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
	obj->point_left = true;

	//define pointer to parent list
	obj->parent_list = NULL;
	
	//set life, while above 0, obj is alive
	obj->life = 100;

	//save the starting point 
	obj->start.x = start.x;
	obj->start.y = start.y;
	obj->start.ch = start.ch;

	//alloc mem to store model's strs
	obj->model = malloc(model_c * sizeof(char*)); 

	//alloc mem and store title of the obj
	obj->title = malloc(sizeof(char) * (strlen(title) + 1));
	obj->type  = malloc(sizeof(char) * (strlen(type) + 1));
	strcpy(obj->title, title); // copy title to obj
	strcpy(obj->type, type); // copy type to obj

	obj->state = 0; // the state on which the movement is at
		
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

		//change the starting point
		obj->start.y += ydlta; 	 
		obj->start.x += xdlta; 	 
			
    for(int i = 0; i < obj->points_c; i++){
        //add the dlta values to the obj points 
        obj->points[i].y =  obj->points[i].y + ydlta;
        obj->points[i].x = obj->points[i].x + xdlta;
    }
}


void reposition_obj(Object* obj, Point_ch new_start){
		/*
			 overwites and reposistion the char points in
			 the object basen on the new starting point 
		 */ 

		bool cutoff_space;
		int point_c = 0;

		obj->start.x = new_start.x;
		obj->start.y = new_start.y;

		//make a char point for every char in string array, and store it in obj's mem
		//excluding any space at the begining of the string
		for(int y = 0; y < obj->model_c; y++){
				cutoff_space = false;
				for(int x = 0; x < strlen(obj->model[y]); x++){
						if(obj->model[y][x] != ' ') cutoff_space = true;
						if(cutoff_space){
								obj->points[point_c].x = new_start.x + x;
								obj->points[point_c].y = new_start.y + y;
								point_c++;
						}
				}
		}
}



void switch_direction(Object* obj){
		/*
			 changes the direction in which an objec is meant to be
			 true for point left, false for pointing right
		 */
		if(obj->point_left) obj->point_left = false;
		else obj->point_left = true;

}

void kill_obj(Object* obj){
	/* sets obj as dead*/
	obj->life =	0;
}
