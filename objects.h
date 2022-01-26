     bool point_left; //direction the obj move on
extern void move_obj(Object* obj, int direction);
    char ch;
     int life; // when it reaches 0 the obj is dead
		 char* type; //the type of the objec, ship, enemy, wall, bullet...etc
} Point_ch;
     Point_ch* points; // char points
     char* title; //name of obj
#include <stdbool.h>
typedef struct Char_Point {
#endif
extern void kill_obj(Object* obj);
     int points_c; //count of the char points
extern void reposition_obj(Object* obj, Point_ch new_start);
	/*char pointer fuctions */





		 void* parent_list;
    int x, y;
     char** model; //array of str that make out the obj
#ifndef OBJECTS_H_
extern void print_point(Point_ch p);
     int speed;  // how a object moves
extern void free_obj(Object* obj);  
#define OBJECTS_H_
typedef struct Object {
     Point_ch start; //starting point
extern void print_obj(Object* obj);
} Object;
extern Object* make_obj(char* title, char* model[], int model_c, int speed, Point_ch start, char* type);
    /* A point structure for saving the characters and cordinate of an object*/
extern void switch_direction(Object* obj);
     int model_c; // keep track of the number of line the drawing 
	/*objecte fuctions*/
		 int state; // the state on which the animation is at
     /*A Structure for managin and renddering objects*/
