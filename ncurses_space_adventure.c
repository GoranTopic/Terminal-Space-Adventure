/*
	 A program for managing my writting using bash script. 
	 It checks for a writting directory on the home folder and makes tres sub frolders 
	 one for poems, stories, and journal 
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

void render_obj(Object obj){
	/* render obj in the ncruses initilizer*/
	for(int i = 0; i < obj.point_c; i++){
				mvaddch(obj.points[i].y, obj.points[i].x, obj.points[i].ch); 
			}		
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



