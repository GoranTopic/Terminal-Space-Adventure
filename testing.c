/*
	 A program for managing my writting using bash script. 
	 It checks for a writting directory on the home folder and makes tres sub frolders 
	 one fro poems, stories, and journal 
	 for poems it they are named by number, and title.
	 for stories they sorted by dirs with is the name of the story, and pages cana be added
	 for jrl, it is also divided into difrent jrls and when selected it add to that jrl
	 by Goran Topic
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Point_Char {
		int x, y;
		char ch;
};
typedef struct Point_Char Pointch;


struct Points_Array { 
		//strcut for keeping track of pointeres
		Pointch* points;
		int count;
};
typedef struct Points_Array Points_ar;


struct Object {
		Pointch start; //starting point
		char title[50]; //name of obj
		char* drawing; //array of str that make out the obj
		int draw_c; // keep track of thenumber of line the drwaing 
		Points_ar points; // char points
		int speed; 
		int direction; //direction the obj move on
		bool alive; //is obj alive?
};
typedef struct Object Object;


Object* make_obj(char* title, char** model, int model_c, int speed, Pointch start){
	/* alloactes memory and creates a new array location*/
	Object* obj = malloc(sizeof(Object)); 


	strcpy(ship->title, "ship");
	

	return obj;
}





int main(void) {

	char model[3][7]  = { "  -/|", "<=[#]:",  "  -\\|"};
	int model_c = 3;

	Pointch start = { .x = 3, .y = 3, .ch = ' '};

	
Object* make_obj(char* title, char** model, int model_c, int speed, Pointch start){

	ship->speed = 3;
			

	for(int i = 0; i < 3; i++){
			printf("model[%d]: %s\n", i, model[i]);
	}
	
	printf("title: %s\n", ship->title);


	
	


}



