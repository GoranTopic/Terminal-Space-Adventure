/** Data reading from file, reading into obj Datum */


#include <stdio.h>
#include <stdlib.h>


struct ocean_datum {
	int x;/* grid-reference east-west*/

	int y;/* grid-reference north-south*/

	double conc; /* concentration of O_2 in mL/L found at grid-ref (x,y) */
};


void print_ocean_datum(struct ocean_datum* o) {
	/* We need to dereference the struct ocean_datum pointer to print it out,
	which is why we write (*o).x rather than just o.x. Unfortunately,
	*o.x doesn’t work, since the "." operator has higher precedence than the
	dereference.
	o->x is shorthand for (*o).x and is a very common idiom.
	*/
	printf("%d %d %.4f\n", (*o).x, o->y, o->conc);
}


int read_ocean_datum(struct ocean_datum* o) {
	return 3 == scanf("%d %d %lg", &o->x, &o->y, &o->conc);
}


int main(void) {
	struct ocean_datum my_datum;
	while (read_ocean_datum(&my_datum)) {
		print_ocean_datum(&my_datum);
	}
	return EXIT_SUCCESS;
}
