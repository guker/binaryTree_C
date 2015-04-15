#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdio.h>
#include <stdlib.h>

#ifndef TREENODE_H
#define TREENODE_H
#endif

#define MAX_QUEUESIZE 100

typedef treePTR element;
typedef struct QType{
	element queue[MAX_QUEUESIZE];
	int head;
	int tail;
}QType;

void init_Q(QType *q);
int is_qEmpty(QType *q);
int is_qFull(QType *q);
void enqueue(QType *q, element item);
element dequeue(QType *q);

//----------------------------

void init_Q(QType *q){
	q->head = q->tail = 0;
}

int is_qEmpty(QType *q){
	return (q->head == q->tail);
}

int is_qFull(QType *q){
	return (q->head == (q->tail+1) % MAX_QUEUESIZE);
}

void enqueue(QType *q, element item){
	if (is_qFull(q)){
		fprintf(stderr, "ERROR: The queue is Full.");
		return;
	}
	q->tail = (q->tail + 1) % MAX_QUEUESIZE;
	q->queue[q->tail] = item;
}

element dequeue(QType *q){
	if (is_qEmpty(q)){
		fprintf(stderr, "ERROR: The queue is Empty.");
		exit(1);
	}
	q->head = (q->head + 1) % MAX_QUEUESIZE;
	return q->queue[q->head];
}

#endif