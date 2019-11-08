#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mylib.h"
#include "queue.h"

typedef struct q_item *q_item;

struct q_item {
	double item;
	q_item next;
};

struct queue {

	q_item first;
	q_item last;
	int len; /*length*/
};


queue queue_new(void){
	/*make a new structure of a queue*/
	queue q;
	q = emalloc(sizeof *q);
	q->first = NULL;
	q->last = NULL;
	q->len = 0;	
	return q;
}

void enqueue(queue q, double item){
	q_item current;
	current = emalloc(sizeof *current);
	current->item = item;
	current->next = NULL;
	if(q->first == NULL){
		q->first = current;
		q->last = current;

	}else{
		q->last->next = current;
		q->last = current;
	}
	q->len++;
}

double dequeue(queue q){
	/**/
	double popped;
	popped = 0;
	if(q->first == NULL){
		fprintf(stderr, "there are not items on the queue to dequeue\n");
		return EXIT_FAILURE;
	}else{
		q_item tmp;
		tmp = q->first;
		popped = q->first->item;
		q->first = q->first->next;
		free(tmp);
		q->len--;
	}
return popped;
}
double rdequeue(queue q){
	/*it dequeue in the reverse of the queue taking thing off the last*/
	double popped;
	q_item current, temp;
	current = q->first;
	popped = (double)q->last->item;
	temp = q->last;
	
	if(q->last == NULL){
		fprintf(stderr, "there are not items on the queue to reverse dequeue\n");
		return EXIT_FAILURE;
	}
	
	while(current->next != q->last){
		/*find the previous last item in the queue*/
		current = current->next;
		printf("current %f \n", current->item);
	}
	printf("temp %f\n", temp->item);	
	printf("popped %f\n", popped);
	free(temp);
	printf("popped %f\n", popped);
	current->next = NULL;
	printf("popped %f\n", popped);
	q->last = current;	
	printf("popped %f\n", popped);
	q->len--;
	printf("popped %f\n", popped);
	return popped;
}

void queue_print(queue q){
	q_item current;
	current = q->first;

	while(current != NULL){
		printf(" %f ->", current->item);
		current = current->next;
	}	
	printf("\n");
}
int queue_size(queue q){
	return q->len;
}

int free_qitems(q_item item){
	if(item->next != NULL) free_qitems(item->next);
	free(item);
	return 1;
}

int queue_free(queue q){
 
	free_qitems(q->first);
	free(q);
	return EXIT_SUCCESS;

}


