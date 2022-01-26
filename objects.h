		 char* type; //the type of the objec, ship, enemy, wall, bullet...etc
#define OBJECTS_H_
     bool point_left; //direction the obj move on
		 int state; // the state on which the animation is at
extern void kill_obj(Object* obj);
extern Object* make_obj(char* title, char* model[], int model_c, int speed, Point_ch start, char* type);
typedef struct Char_Point {





     int model_c; // keep track of the number of line the drawing 
	/*char pointer fuctions */
typedef struct Object {
extern void switch_direction(Object* obj);
extern void move_obj(Object* obj, int direction);
extern void print_point(Point_ch p);
} Object;
    char ch;
     /*A Structure for managin and renddering objects*/
	/*objecte fuctions*/
     char** model; //array of str that make out the obj
} Point_ch;
    /* A point structure for saving the characters and cordinate of an object*/
#include <stdbool.h>
     int points_c; //count of the char points
extern void print_obj(Object* obj);
#ifndef OBJECTS_H_
     char* title; //name of obj
#endif
    int x, y;
extern void free_obj(Object* obj);  
extern void reposition_obj(Object* obj, Point_ch new_start);
     int speed;  // how a object moves
     Point_ch* points; // char points
		 void* parent_list;
     Point_ch start; //starting point
     int life; // when it reaches 0 the obj is dead
