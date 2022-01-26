#include <stdbool.h>
#ifndef OBJECTS_H_
#define OBJECTS_H_

typedef struct Char_Point {
    /* A point structure for saving the characters and cordinate of an object*/
    int x, y;
    char ch;
} Point_ch;

typedef struct Object {
     /*A Structure for managin and renddering objects*/
     Point_ch start; //starting point
     char* title; //name of obj
     char** model; //array of str that make out the obj
     int model_c; // keep track of the number of line the drawing 
     Point_ch* points; // char points
     int points_c; //count of the char points
     int speed;  // how a object moves
		 char* type; //the type of the objec, ship, enemy, wall, bullet...etc
		 int state; // the state on which the animation is at
     bool point_left; //direction the obj move on
     int life; // when it reaches 0 the obj is dead
		 void* parent_list;
} Object;

	/*objecte fuctions*/
extern Object* make_obj(char* title, char* model[], int model_c, int speed, Point_ch start, char* type);
extern void free_obj(Object* obj);  
extern void move_obj(Object* obj, int direction);
extern void kill_obj(Object* obj);
extern void print_obj(Object* obj);
extern void switch_direction(Object* obj);
extern void reposition_obj(Object* obj, Point_ch new_start);

	/*char pointer fuctions */
extern void print_point(Point_ch p);

#endif
