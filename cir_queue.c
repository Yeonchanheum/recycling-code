#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int front;
	int rear;
	int capacity;
	int* data;
}Queuetype;

void init_queue(Queuetype* q, int size) {
	q->front = 0;
	q->rear = 0;
	q->capacity = size;
	q->data = (int*)malloc(sizeof(int) * q->capacity);
}


int is_full(Queuetype* q) {
	return (q->front == (q->rear + 1)% q->capacity);
}


int is_empty(Queuetype* q) {
	return (q->front == q->rear);
}


void enqueue(Queuetype* q, int item) {
	if (is_full(q)) 
		exit(1);

	q->rear = (q->rear + 1) % q->capacity;
	q->data[q->rear] = item;
}


int dequeue(Queuetype* q) {
	if (is_empty(q)) 
		exit(1);

	q->front = (q->front + 1) % q->capacity;
	return q->data[q->front];
}


int peek(Queuetype* q) {
	if (is_empty(q))
		exit(1);

	return q->data[q->front];
}
