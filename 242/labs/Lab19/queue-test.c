#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mylib.h"
#include "queue.h"



int main(void){
	/*main fuction made for testing queue*/

	queue q = queue_new();
	
	enqueue(q, 23);
	enqueue(q, 34);
	enqueue(q, 54);
	enqueue(q, 123);
	enqueue(q, 456);
	enqueue(q, 678);
	enqueue(q, 910);
	queue_print(q);
	printf("%f dequeued\n", dequeue(q));
	queue_print(q);
	printf("%f dequeued\n", dequeue(q));
	queue_print(q);
	printf("%f reversed dequeued\n", rdequeue(q));
	queue_print(q);


	queue_free(q);

	return EXIT_SUCCESS;
}
