//STACK CODE
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int top;
	int capacity;
	int* data;
}Stacktype;

void init_stack(Stacktype* p) {
	p->top = -1;
	p->capacity = 1;
	p->data = (int*)malloc(sizeof(int));
}

int is_full(Stacktype* p) {
	return (p->top + 1 == p->capacity);
}

int is_empty(Stacktype* p) {
	return (p->top == -1);
}

void push(Stacktype* p, int item) {
	if (is_full(p)) {
		p->capacity *= 2;
		p->data = (int*)realloc(p->data, sizeof(int) * p->capacity);
	}
	p->data[++(p->top)] = item;
}

int pop(Stacktype* p) {
	if (is_empty(p)) {
		return;
	}
	else {
		return p->data[(p->top)--];
	}
}

int peek(Stacktype* p) {
	if (is_empty(p)) {
		return;
	}
	return p->data[p->top];
}
