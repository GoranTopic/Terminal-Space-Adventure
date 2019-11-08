#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mylib.h"
#include "queue.h"

struct queue {

	double *items;
	int head;
	int cap; /*capaciaty*/
	int num_items;
};


queue queue_new(void){
	/*make a new structure of a queue*/
	queue q;
	q = emalloc(sizeof *q);
	q->cap = 2;
	q->head = 0;
	q->num_items = 0;
	q->items = emalloc(q->cap  * sizeof q->items[0]);	
	return q;
}

void enqueue(queue q, double item){
	if (q->num_items == q->cap) {
			/* do the old "double the capacity" trick */
			q->cap += q->cap;
			q->items = erealloc(q->items, q->cap * sizeof q->items[0]);
		}

	q->items[(q->head + q->num_items) % q->cap] = item;
	q->num_items++;

}

double dequeue(queue q){
	/**/
	double poped;
	if(q->num_items <= 0){
		fprintf(stderr, "Can not dequeue because queue has no items\n");
		return EXIT_FAILURE;
	} 
	poped = q->items[q->head];
	q->head++;
	/*q->num_items--;*/

return poped;
}

void queue_print(queue q){
	int i;
	for(i = q->head; i < q->num_items; i++){
		printf("[%f] <- ", q->items[i]);
	}
	printf("\n");

}
int queue_size(queue q){
	return q->num_items;
}

int queue_free(queue q){
 	free(q->items);
 	free(q);
	return EXIT_SUCCESS;

}


