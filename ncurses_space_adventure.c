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
#include <ncurses.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <sys/stat.h>


struct Char_point {
		/*structure for managing point, characters maped to it's postion and collition */
		int x, y;
		char ch;
};
typedef struct Char_point Char_point;


struct Object {
		Char_point start; //starting point
		char title[255]; //naem of obj
		char drawing[6][255]; //array of str that make out the obj
		int draw_c; // keep track of thenumber of line the drwaing 
		Char_point points[255]; // char points
		int point_c; //number of points
		int speed; 
		int direction; //direction the obj move on
		bool alive; //is obj alive?
};
typedef struct Object Object;





void print_point(Char_point p){
	/*print  a point to std*/
	printf("(y:%d, x:%d, %c)\n", p.y, p.x, p.ch);

}

void print_obj(Object obj){
		/*prints obj from a given obj to std*/
		printf("start point: ");
		print_point(obj.start);
		printf("\n");
		printf("title: %s \n", obj.title); 
 	  printf("alive: %d \n", obj.alive);
 	  printf("speed: %d \n", obj.speed);

		//draw object
		for(int line = 0; line < obj.draw_c; line++){
				printf("%s\n", obj.drawing[line]);
		}

		//print points 
		printf("Points:\n");
		for(int i = 0; i < obj.point_c; i++){
			print_point(obj.points[i]);
		}	
		printf("\n");
}

Object make_obj(int x_start, int y_start, 
								char drawing[3][7], int draw_c, int speed){
		/* takes the parametes need and returns an object */
		
		//initialize point 
		Char_point p1 = {.x = x_start, .y = y_start};

		//initialize object
		Object obj = { 
				.start = p1,
				.title = "ship", 	
				.alive = true, 
				.speed = speed,
				.draw_c =  draw_c,
		};
		
		//copy drawing string into the obj drawing 
		for(int i = 0; i < obj.draw_c; i++){
			strcpy(obj.drawing[i], drawing[i]);
		}
		
		int x_pos = obj.start.x; 	
		int y_pos = obj.start.y; 	
		obj.point_c = 0;
		int ch_c;
		char ch;
		bool begining_space = true;
		
		for(int line = 0; line < draw_c; line++){
				//for every make array of blank spaces for every char in drawing array
				ch_c = 0;
				begining_space = true;
				x_pos = obj.start.x; 	
				while(obj.drawing[line][ch_c] != '\0'){
						//for every ch in str
						ch = obj.drawing[line][ch_c];
						x_pos++;
						//begining_space work as a swith so the every str that start with space does not get added into points
						if(begining_space == true && ch != ' ') begining_space = false;
						if(begining_space == false) {		
								obj.points[obj.point_c].x = x_pos; 
								obj.points[obj.point_c].y = y_pos; 
								obj.points[obj.point_c].ch = ch;
								obj.point_c++;
						}
						ch_c++;
				}
				y_pos++;
		}

		return obj;
}                                                                      

void render_obj(Object obj){
	/* render obj in the ncruses initilizer*/
	for(int i = 0; i < obj.point_c; i++){
				mvaddch(obj.points[i].y, obj.points[i].x, obj.points[i].ch); 
			}		
}

void mv_obj(Object* obj, int direction){
		/* render obj in the ncruses initilizer*/
		int xdlta;
		int ydlta; 
		//traslate deegre into x and y changes
		switch(direction){
				case 0:
						ydlta =	-1;
						xdlta = 0;
						break;	
				case 45:
						ydlta =	-1;
						xdlta = 1;
						break;	
				case 90:
						ydlta =	0;
						xdlta = 1;
						break;	
				case 135:
						ydlta =	1;
						xdlta = 1;
						break;	
				case 180:
						ydlta =	1;
						xdlta = 0;
						break;	
				case 225:
						ydlta =	1;
						xdlta = -1;
						break;	
				case 270:
						ydlta =	0;
						xdlta = -1;
						break;	
				case 315:
						ydlta =	-1;
						xdlta = -1;
						break;	
				case 360:
						ydlta =	-1;
						xdlta = 0;
						break;	
				default:
						ydlta = 0;
						xdlta = 0;
		}


		//printf("it ran deltax: %d, y:%d, point[0]: ", xdlta, ydlta);
		//print_point(obj.points[0]);
		obj.start.y += ydlta;
		obj.start.x += xdlta;
		for(int i = 0; i < obj.point_c; i++){
				//add the dlta values to the obj points 
				obj.points[i].y =  obj.points[i].y + ydlta;
				obj.points[i].x = obj.points[i].x + xdlta;
		}		
		//print_point(obj.points[0]);
}


int ncurses_start(void){
		/* initialize an run ncurse*/
		
		//the user sturcture
		char ch;
		int i = 0;

		// ncruses initialation
		initscr();              //start cruses mode
		cbreak();               //be able to ctrl c break
		keypad(stdscr, TRUE);   // enable key pad		
		noecho();               //do not echo the input keys

		//get the minimun and max size of the screen
		int x_min = 0, y_min =0;
		int x_max, y_max;
		getmaxyx(stdscr, y_max, x_max); 
		
		
		/* draw cirlce around window */
		for(int x = 0; x < x_max; x++){
				mvaddch(y_min   , x, '#');
				mvaddch(y_max -1, x, '#');
		}  
		for(int y = 0; y < y_max; y++){
				mvaddch( y, x_min   , '#');
				mvaddch( y, x_max -1, '#');
		}

		char ship_drawing[3][7]  = { "  -/|", "<=[#]:",  "  -\\|"};
		int draw_c = 3;
		int direction;
		int ship_speed = 3;
		int ship_x = 3;
		int ship_y =2;
	
		Object ship = make_obj(ship_x, ship_y, ship_drawing,
										   							 draw_c, ship_speed);

		int x_cor = x_max/2;
		int y_cor = y_max/2;
		char buff_str[255] = "Imanalla World";

		while(ch != 'q'){

				ch = getch();

				mvprintw(y_cor - 1, x_cor + 1 , "     ");
				mvprintw(y_cor    , x_cor     , "      ");
				mvprintw(y_cor + 1, x_cor + 1 , "     ");

				if(ch == 's'){
						y_cor++;
						mv_obj(ship, 180);
				}else if(ch == 'w'){ 	
						y_cor--;				
						mv_obj(ship, 360);
				}else if(ch == 'a'){ 	
						x_cor--;				
						mv_obj(ship, 270);
				}else if(ch == 'd'){ 	
						x_cor++;				
						mv_obj(ship, 90);
				}else if(ch == ' '){
						for(int x = x_cor; x > 0; x--){
								//fire bullet
								mvaddch(y_cor, x    , '-');
								mvaddch(y_cor, x + 1, ' ');
								refresh();
						}	
				}				

				//move(y_cor, x_cor);

				//mvprintw(y_cor - 1, x_cor + 2,   "-/|");
				//mvprintw(y_cor    , x_cor    , "<=[#]:");
				//mvprintw(y_cor + 1, x_cor + 2,   "-\\|");

				render_obj(ship);
				refresh(); //refresh screen 
				//getstr(buff_str);
		}

		endwin(); //end sescion 
		return 0;
}


int main(void) {
	
		char ship_drawing[3][7]  = { "  -/|", "<=[#]:",  "  -\\|"};
		int draw_c = 3;
		int direction;
		int ship_speed = 3;
		int ship_x = 3;
		int ship_y =2;
	
		Object ship = make_obj(ship_x, ship_y, ship_drawing,
										   							 draw_c, ship_speed);
		print_obj(ship);

		mv_obj(&ship, 90);
		

		print_obj(ship);
		
		//render_obj(ship);

		//ncurses_start();

}



