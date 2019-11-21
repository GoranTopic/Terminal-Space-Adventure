#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "objects.h"
#include "movement.h"
#include "enemies.h"
#include "array_obj.h"


int rand_close_mid_(int range){
	/* return a number which is more probable to be close the the middle of*/
		return range/2;
}


Object* random_enemy(int max_x, int max_y, Obj_arr* enemies){
		/*return an random enemiy from the enemy array*/
		time_t t;
		Object* new;
		Object* rand_obj;
		int rand_index;
		Point_ch start = {.x =0, max_y/2 };		


		srand((unsigned) time(&t));
		//printf("tim: %d\n", t);
		rand_index = rand() % (enemies->count-1);
				
		//printf("rand_objom index: %d\n", rand_index);
		rand_obj = &(enemies->objs[rand_index]);
		
		new = make_obj(rand_obj->title, rand_obj->model, rand_obj->model_c, rand_obj->speed, start, rand_obj->type);
		

	return new;
}

Obj_arr* load_enemies_ar(void){
		/* load the a list of random objects */

		Obj_arr* enemies_ar = make_obj_ar(50); 


		Point_ch start_point;
		Object* enemy;
		int model_c = 10;
		char* model[model_c];
		model[0] = malloc(sizeof(char) * 100);
		model[1] = malloc(sizeof(char) * 100);
		model[2] = malloc(sizeof(char) * 100);
		model[3] = malloc(sizeof(char) * 100);
		model[4] = malloc(sizeof(char) * 100);
		model[5] = malloc(sizeof(char) * 100);
		model[6] = malloc(sizeof(char) * 100);
		model[7] = malloc(sizeof(char) * 100);
		model[8] = malloc(sizeof(char) * 100);
		model[9] = malloc(sizeof(char) * 100);
		//might this be enought?
		char* title;
		char* type = "enemy";
		int speed;
		
		title = "sneaker";
		strcpy(model[0],"\\   \\");
		strcpy(model[1]," >--o=>");
		strcpy(model[2],"/   /");
		model_c = 3;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);

		
		title = "small nibler";
		strcpy(model[0], " \\");
		strcpy(model[1], " []>");
		strcpy(model[2], " /");
		model_c = 3;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);

		title = "rocketdler";
		strcpy(model[0], "  |\\");
		strcpy(model[1], ">=====>");
		strcpy(model[2], "  |/");
		model_c = 3;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);

		title = "grabler";
		strcpy(model[0], "   /~{");
		strcpy(model[1], "  /|");
		strcpy(model[2], ":=[]>");
		strcpy(model[3], "  \\|");
		strcpy(model[4], "   \\~{");
		model_c = 5;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);


		title = "vaginer";
		strcpy(model[0], "\\ \\    / /");
		strcpy(model[1], " \\_({})_/");
		model_c = 2;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);
 
		title = "nibbler";
		strcpy(model[0], ":<[o]>:");
		model_c = 1;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);

		title = "naggler";
		strcpy(model[0], "    |");
		strcpy(model[1], "   / \\ ");
		strcpy(model[2], "}<[o_*]>{");
		strcpy(model[3], "   \\ /");
		strcpy(model[4], "    |");
		model_c = 5;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);

		title = "splinfer";
		strcpy(model[0], ":=[o]>");
		model_c = 1;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);



		/*

		title = "o'er";
		strcpy(model[0], ":(😢)");
		model_c = 1;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);

		title = "wapitakgler";
		strcpy(model[0], "(ಠ⌣ಠ) =>");
		model_c = 1;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);

		title = "scrupler";
		strcpy(model[0], "ヽ༼ຈل͜ຈ༽ﾉ");
		model_c = 1;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);


		title = "nyan cat";
		strcpy(model[0], "~~~ ╔͎═͓═͙╗");
		strcpy(model[1], "~~~ ╚̨̈́═̈́﴾ ̥̂˖̫˖̥ ̂)");
		model_c = 2;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);


		title = "spidler";
		strcpy(model[0], "ᄽὁȍ ̪őὀᄿ");
		model_c = 1;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);

		title = "angriler";
		strcpy(model[0], "  =|\\");
		strcpy(model[1], ":[(😡)])>");
		strcpy(model[2], "  =|/ ");
		model_c = 3;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);


		title = "sadler";
		strcpy(model[0], "   {|\\");
		strcpy(model[1], " :=(😢)]>");
		strcpy(model[2], "   {|/");
		model_c = 3;
		speed = 1;
		start_point.x = 0;
		start_point.y = 0;
		start_point.ch = ' ';
		enemy =  make_obj(title, model, model_c, speed, start_point, type);
		switch_direction(enemy); //switch direction
		append_obj(enemies_ar, enemy);

		*/

	return enemies_ar;

}


