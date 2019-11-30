#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <math.h>
#include "objects.h"
#include "movement.h"
#include "linked_list_obj.h"
#include "array_obj.h"
#include "enemies.h"
#include "portaudio.h"

#ifdef __APPLE__
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#elif __linux
#include <AL/al.h>
#include <AL/alc.h>
#endif

/*
	space game using c and Ncursesfor the terminal
 
	by Goran Topic

*/


#define NUMTHRDS 4
pthread_t callThd[NUMTHRDS]; 
pthread_mutex_t mutex;



void load_ships(void){
/* loads models for the ships */

	char* model[]  = {  "  -/|",
	                		"<=[#]:",
		                	"  -\\|"
									 };
	Point_ch start = { .x = 3, .y = 3, .ch = ' '};
	Object* start_ship =  make_obj("start_ship", model, 3, 1, start, "ship");



	char* model2[]  = {" |\\=",
		           			 "C==[X]",
		          			 " |/="};
	Point_ch start2 = { .x = 8, .y = 5, .ch = ' '};
	Object* mauler =  make_obj("mauler", model2, 3, 1, start2, "ship");


	char* model3[]  = {"<=-=-==:",
		           			 "  [H]D",
		          			 "<=-=-==:"};
	Point_ch start3 = { .x = 15, .y = 5, .ch = ' '};
	Object* floater =  make_obj("floater", model3, 3, 1, start3, "ship");
	

	char* model4[]  = {"  /\\",
		           			 "-<[+]:",
		          			 "  \\/"};
	Point_ch start4 = { .x = 7, .y = 5, .ch = ' '};
	Object* quicky =  make_obj("quicky", model4, 3, 1, start4, "ship");


	char* model5[]  = {"  { |",
		           			 " <=[o][:",
		          			 "  { |"};
	Point_ch start5 = { .x = 15, .y = 5, .ch = ' '};
	Object* falco =  make_obj("falco", model5, 3, 1, start5, "ship");

	List* list = list_make();

	list_append(list, start_ship);
	list_append(list, mauler);
	list_append(list, floater);
	list_append(list, quicky);
	list_append(list, falco);


	//list_print(list);
	//list_remove_at(list, 3);
	//list_remove_title(list, "start_ship");
	//list_print(list);
	//print_obj(*(list_get_at(list, 0)));
	//print_obj(*(list_get_title(list, "falco")));
	list_free(list);
}

void clear_screen(void){
		/* rewrites the screen before rendeing the objects so that it deletes the old space*/

    //get the minimun and max size of the screen
    int x_min = 0;
		int y_min =0;
    int x_max, y_max;
    getmaxyx(stdscr, y_max, x_max);

		//draw cirlce around window 
		for(int y = y_min;  y < y_max; y++)
			for(int x = x_min; x < x_max; x++)	
				if(x == x_min || x == x_max -1 || y == y_min || y == y_max -1)
						mvaddch(y, x, '*');
				else
						mvaddch(y, x, ' ');
}

void render_obj(Object* obj){
  /*render obj in the ncruses initilizer*/
		for(int i = 0; i < obj->points_c; i++)
			mvaddch(obj->points[i].y, obj->points[i].x, obj->points[i].ch);
}

void render_obj_list(List* list){
		/* for every member of the list, it rendes it into the screen */
		if(list->first == NULL || list->count == 0){
				//link list is empty
				printf("ERROR: could not render empty link list\n");
				return;
		}
		Node* current = list->first;
		while(true) {
				for(int line = 0; line < current->obj->model_c; line++)
						render_obj(current->obj);
								if(current->next != NULL) current = current->next;
								else break;
		}
}


void move_objs(List* list){
	/*moves the objects acording the theri type */ 
	if(list->first == NULL || list->count == 0){
				//link list is empty
				printf("ERROR: could not move objects of an empty list\n");
				return;
		}
		Node* current = list->first;
		while(true) {
				for(int line = 0; line < current->obj->model_c; line++)
						move_by_type(current->obj);
								if(current->next != NULL) current = current->next;
								else break;
		}
}

void remove_the_dead(List* list){
		/*removes from the list any obj which is dead*/ 
		if(list->first == NULL || list->count == 0){
				//link list is empty
				printf("ERROR: could not move objects of an empty list\n");
				return;
		}

		Node* current = list->first;
		Node* prev = current;
		Node* doomed = current;	
		while(true){
				if(current->obj->life <= 0){
						//node title found
						if(prev == current) list->first = current->next; 
						else prev->next = current->next; //if is is not the first node 
						//eliminate remove the node from the list
						doomed = current;
						current = prev;
						node_free(doomed);
						list->count--;
				}
				if(current->next != NULL){
						prev = current;
						current = current->next;
				}else break;
		}
}


bool are_collited(Object* obj1, Object* obj2){
 /* return true if objects have a point in comon,
	or return false if they don't or are the same object */
	if(obj1 == obj2) return false; //check if they are the same object
	for(int i1 = 0; i1 < obj1->points_c; i1++)
			for(int i2 = 0; i2 < obj2->points_c; i2++)
				if(obj1->points[i1].x == obj2->points[i2].x
					 && obj1->points[i1].y == obj2->points[i2].y){
					//printf("x1: %d, x2: %d, y1: %d, y2: %d\n",
					//		obj1->points[i1].x, obj2->points[i2].x,
					// 		obj1->points[i1].y, obj2->points[i2].x);
					return true;
				}
	return false;
}


void collide_action(Object* obj1, Object* obj2){
		/*take action arcding to the type of object which collied*/
		bool has_ship = strcmp(obj1->type, "ship") == 0 ||
				strcmp(obj2->type, "ship") == 0;
		bool has_bullet = strcmp(obj1->type, "bullet") == 0 ||
				strcmp(obj2->type, "bullet") == 0;
		bool has_player = strcmp(obj1->type, "player") == 0 ||
				strcmp(obj2->type, "player") == 0;
		bool has_enemy = strcmp(obj1->type, "enemy") == 0 ||
				strcmp(obj2->type, "enemy") == 0;

		if(has_ship && has_bullet){
				//collition with ship and bullet
				obj1->life = 0;
				obj2->life = 0;
		}else if(has_ship && has_player){
				//collition with ship and player
				//obj1->life = 0;
				//obj2->life = 0;
		}else if(has_player && has_bullet){
				//collition with a bullet and player
				//obj1->life = 0;
				//obj2->life = 0;
		}else if(has_enemy && has_bullet){
				//collition with a bullet and player
				obj1->life = 0;
				obj2->life = 0;
		}else if(has_ship){
				//collition with ship and ship
				obj1->life = 0;
				obj2->life = 0;
		}else if(has_bullet){
				//collition with two bullets
				obj1->life = 0;
				obj2->life = 0;
		}else if(has_player){
				//collition two players
		}	
}

void collition_check(List* list){
		/*
			 check if there is an objs which have the same points
			 if ti does then it executes and action based on it's type
		 */

		int i_max = list->count; 
		Node* cur_node1 = list->first;
		Node* cur_node2 = list->first;

		while(true){
				if(are_collited(cur_node1->obj, cur_node2->obj)){
						collide_action(cur_node1->obj, cur_node2->obj);
						break;
				}
				if(cur_node1->next == NULL){
						break;
				}else if(cur_node2->next == NULL){
						cur_node2 = list->first;
						cur_node1 = cur_node1->next;
				}else{
						cur_node2 = cur_node2->next;
				}
		}
}

void fire(Object* obj){
	/* makes object fire a bullet which spans from the the ship */
		List* list = obj->parent_list;

		if(strcmp(obj->type, "player") == 0){
				char* model[]  = {"-"};
				Point_ch start = { .x = obj->start.x, .y = obj->start.y, .ch = ' '};
				Object* bullet =  make_obj("fire1", model, 1, 1, start, "bullet");
				list_append(list, bullet);
				Point_ch start2 = { .x = obj->start.x, .y = obj->start.y+2, .ch = ' '};
				bullet =  make_obj("fire1", model, 1, 1, start2, "bullet");
				list_append(list, bullet);
		}else if(strcmp(obj->type, "ship") == 0){
				char* model[]  = {"-"};
				Point_ch start = { .x = obj->start.x - 1 , .y = obj->start.y + 1 , .ch = ' '};
				Object* bullet =  make_obj("fire1", model, 1, 1, start, "bullet");
				list_append(list, bullet);
		}
}

void* player_movement(void* vargp){
		
		List* list = (List*)vargp;
		Object* ship = list_get_title(list, "ship");

    char ch;
		while(true){
				ch = getch();
				
				//lock mutex
				pthread_mutex_lock(&mutex); 
				if(ch == 2 || ch == 'w'){
						move_obj(ship, 180);
				}else if(ch == 3){
						move_obj(ship, 360);
				}else if(ch == 4){
						move_obj(ship, 270);
				}else if(ch == 5){
						move_obj(ship, 90);
				}else if(ch == ' '){
						fire(ship);
				}else if(ch == KEY_LEFT){
						move_obj(ship, 180);
				}else if(ch == 'q'){
						//exit game
				}
				//unlock mutex
				pthread_mutex_unlock (&mutex);
		}
	return NULL;
}



#ifdef WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>   // for nanosleep
#else
#include <unistd.h> // for usleep
#endif
void sleep_ms(int milliseconds) // cross-platform sleep function
{
#ifdef WIN32
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    usleep(milliseconds * 1000);
#endif
}





ALCdevice  * openal_output_device;
ALCcontext * openal_output_context;

ALuint internal_buffer;
ALuint streaming_source[1];

int al_check_error(const char * given_label) {

    ALenum al_error;
    al_error = alGetError();

    if(AL_NO_ERROR != al_error) {

        printf("ERROR - %s  (%s)\n", alGetString(al_error), given_label);
        return al_error;
    }
    return 0;
}

void MM_init_al() {

    const char * defname = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);

    openal_output_device  = alcOpenDevice(defname);
    openal_output_context = alcCreateContext(openal_output_device, NULL);
    alcMakeContextCurrent(openal_output_context);

    // setup buffer and source

    alGenBuffers(1, & internal_buffer);
    al_check_error("failed call to alGenBuffers");
}

void MM_exit_al() {

    ALenum errorCode = 0;

    // Stop the sources
    alSourceStopv(1, & streaming_source[0]);        //      streaming_source
    int ii;
    for (ii = 0; ii < 1; ++ii) {
        alSourcei(streaming_source[ii], AL_BUFFER, 0);
    }
    // Clean-up
    alDeleteSources(1, &streaming_source[0]);
    alDeleteBuffers(16, &streaming_source[0]);
    errorCode = alGetError();
    alcMakeContextCurrent(NULL);
    errorCode = alGetError();
    alcDestroyContext(openal_output_context);
    alcCloseDevice(openal_output_device);
}

void MM_render_one_buffer() {


		MM_init_al();

    /* Fill buffer with Sine-Wave */
    // float freq = 440.f;
    float freq = 100.f;
    float incr_freq = 0.2f;

    float seconds = 0.5;
    // unsigned sample_rate = 22050;
    unsigned sample_rate = 44100;
    double my_pi = 3.14159;
    size_t buf_size = seconds * sample_rate;

    // allocate PCM audio buffer        
    short * samples = malloc(sizeof(short) * buf_size);

		//printf("\nhere is freq %f\n", freq);
    int i=0;
		//add frequncy to buffer
    for(; i<buf_size; ++i) {
        samples[i] = 32760 * sin( (2.f * my_pi * freq)/sample_rate * i );
        freq += incr_freq;
        //incr_freq += incr_freq;
       	//freq *= factor_freq;
    }

    /* upload buffer to OpenAL */
    alBufferData( internal_buffer, AL_FORMAT_MONO16, samples, buf_size, sample_rate);
    al_check_error("populating alBufferData");

    free(samples);

    /* Set-up sound source and play buffer */
    ALuint src = 0;
    //alGenSources(1, &src);
    //alSourcei(src, AL_BUFFER, internal_buffer);
    alGenSources(1, & streaming_source[0]);
    alSourcei(streaming_source[0], AL_BUFFER, internal_buffer);
    

		//alSourcePlay(src);
    alSourcePlay(streaming_source[0]);

    // ---------------------

    ALenum current_playing_state;
    alGetSourcei(streaming_source[0], AL_SOURCE_STATE, & current_playing_state);
    al_check_error("alGetSourcei AL_SOURCE_STATE");

    while (AL_PLAYING == current_playing_state) {

        //printf("still playing ... so sleep\n");
        //sleep(1);   // should use a thread sleep NOT sleep() for a more responsive finish

        alGetSourcei(streaming_source[0], AL_SOURCE_STATE, & current_playing_state);
        al_check_error("alGetSourcei AL_SOURCE_STATE");
    }

    //printf("end of playing\n");

    MM_exit_al();
}   //MM_render_one_buffer



void make_sound(void){


		pthread_t sound_thread;
		pthread_create(&sound_thread, NULL, MM_render_one_buffer, NULL);

}



int ncurses_start(void){
		//initialize an run ncurse

		//the user sturcture
		char ch;
		int i = 0;

		// ncruses initialation
		initscr();              //start cruses mode
		cbreak();               //be able to ctrl c break
		keypad(stdscr, TRUE);   // enable key pad   
		noecho();               //do not echo the input keys
		curs_set(0);            //hide cursor

		//get the minimun and max size of the screen
		int x_min = 0, y_min =0;
		int x_max, y_max;
		getmaxyx(stdscr, y_max, x_max);
		int x_half = x_max/2;
		int y_half = y_max/2;
		
		char* model[]  = { 
				"  -/|",
				"<=[#]:",
				"  -\\|"
		};
		Point_ch start = { .x = 70, .y = 8, .ch = ' '};
		Object* ship =  make_obj("ship", model, 3, 1, start, "player");

		char* model2[]  = {
				" |\\=",
				"C==[X]",
				" |/="
		};
		Point_ch start2 = { .x = 8, .y = 5, .ch = ' '};
		Object* mauler =  make_obj("mauler", model2, 3, 1, start2, "ship");

		char* model5[]  = {
				"  { |",
				" <=[o][",
				"  { |"
		};
		Point_ch start5 = { .x = 80, .y = 5, .ch = ' '};
		Object* falco =  make_obj("falco", model5, 3, 1, start5, "ship");

		char* model4[]  = {
				"  /\\",
				"-<[+]:",
				"  \\/"
		};
		Point_ch start4 = { .x = 100, .y = 100, .ch = ' '};
		Object* quicky =  make_obj("quicky", model4, 3, 1, start4, "ship");

		List* list = list_make();
		list_append(list, ship);
		list_append(list, mauler);
		list_append(list, quicky);
		list_append(list, falco);
		


		Point_ch new_start = { .x = 30, .y = 14, .ch = ' '};
		reposition_obj(list_get_title(list, "quicky"), new_start);
				


		//initialize mutex for making chnages in th elist of objs
		pthread_mutex_init(&mutex, NULL); 
		//make new thread which is listing for player inputs
		pthread_t thread_id;
		pthread_create(&thread_id, NULL, player_movement, list);


		// create enemy
		Obj_arr* enemies = load_enemies_ar();
		//list_append(list, random_enemy(0,y_max, enemies));

	
		int timer  = 0;
		while(true){
				
				sleep_ms(70);

				//lock mutex
				pthread_mutex_lock(&mutex); 
				
				collition_check(list);
				remove_the_dead(list);						
				if(timer % 10 == 0) fire(quicky);
				if(timer % 40 ==0){
						make_sound();
						list_append(list, random_enemy(0,y_max, enemies));
				}
				move_objs(list);
				
				//unlock mutex
				pthread_mutex_unlock (&mutex);

				clear_screen();
				
				render_obj_list(list);
				
				refresh(); //refresh screen 
	
				if(timer > 10000) timer = 0;
				else timer++;

		}
		endwin(); //end sescion 
		return 0;
}


int main(void) {

		ncurses_start();

}
