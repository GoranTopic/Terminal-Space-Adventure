/** reading and sorting datum with insertionsort  */

#include <stdio.h>
#include <stdlib.h>
#define OCEAN_MAX 41981

struct ocean_datum {
	int x;/* grid-reference east-west*/
	int y;/* grid-reference north-south*/
	double conc; /* concentration of O_2 in mL/L found at grid-ref (x,y) */
};




void print_ocean_datum(struct ocean_datum *o) {
	printf("x: %d y: %d conc: %.4f\n", o->x, o->y, o->conc);
}


int read_ocean_datum(struct ocean_datum *o) {
	return 3 == scanf("%d %d %lg", &o->x, &o->y, &o->conc);
}

int is_less_datum(struct ocean_datum* od1, struct ocean_datum* od2){
	//compares the oxigen concetration of two ocean data objects
	if(od1->conc > od2->conc) return 1;
	else return 0;
}


void sort_ocean_data(struct ocean_datum* data, int size){
	//use selection sort to sort the array of ocean_data
	
	for (int i = 0; i < size; i++) {
		 //get the first instance as teh smallest
		struct ocean_datum* smallest = &data[i];
		struct ocean_datum temp;

		for(int j = i + 1; j < size; j++){ 
			//check other values to find the smallest
			if( 1 == is_less_datum(smallest, &data[j])) smallest = &data[j];				
		}

		//swap current values with smallest found
		temp = data[i];
		data[i] = *smallest;
		*smallest = temp;
	}	
}


int main(void) {
	struct ocean_datum ocean_data[OCEAN_MAX];
	int num_items;
	int i;
	num_items = 0;
	while (num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])) {
		num_items++;
	}


/* sort the data here */


sort_ocean_data(ocean_data, OCEAN_MAX);


/* print out the array of structs */

	for (i = 0; i < num_items; i++) {
		print_ocean_datum(&ocean_data[i]);
	}
return EXIT_SUCCESS;
}
