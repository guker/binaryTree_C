#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdio.h>
#include <stdlib.h>

#ifndef TREENODE_H
#define TREENODE_H
#endif

#define MAX_STACKSIZE 100
typedef treePTR element;
typedef struct stackType{
	element stack[MAX_STACKSIZE];
	int top;
}stackType;

void init_stack(stackType *s);
int is_sEmpty(stackType *s);
int is_sFull(stackType *s);
void push(stackType *s, element item);
element pop(stackType *s);
element peek(stackType *s);

void init_stack(stackType *s){
	s->top = -1;
}

int is_sEmpty(stackType *s){
	return (s->top == -1);
}


int is_sFull(stackType *s){
	return (s->top == MAX_STACKSIZE - 1);
}

void push(stackType *s, element item){
	if (is_sFull(s)){
		fprintf(stderr, "ERROR: Stack Overflow.\n");
		return;
	}
	else
		s->stack[++(s->top)] = item;
}

element pop(stackType *s){
	if (is_sEmpty(s)){
		fprintf(stderr, "ERROR: Stack Underflow.\n");
		exit(1);
	}
	else
		return (s->stack[(s->top)--]);
}

element peek(stackType *s){
	if (is_sEmpty(s)){
		fprintf(stderr, "ERROR: Stack Underflow.\n");
		exit(1);
	}
	else
		return (s->stack[(s->top)]);
}

#endif