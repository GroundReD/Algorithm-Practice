// 10845_c.cpp

#include <cstdio>
#include <cstdlib>
#include <cstring>


typedef struct NODE 
{
	int value;
	NODE *next;
}Node;

typedef struct QUEUE{
	NODE *front;
	NODE *back;
	int size;
}Queue;

void push(Queue *q, int value) {

	Node *tmp = (Node *) malloc(sizeof(Node));
	tmp->value = value;

	if(q->size == 0) {
		q->front = tmp;
		q->back = tmp;
		q->size+=1;
	} else {
		q->back->next = tmp;
		q->back = tmp;
		q->size += 1;
	}
}

int pop (Queue *q) {
	Node *tmp;
	int n;
	if(q->size == 0) {
		return -1;
	} else {
		tmp = q->front;
		n = tmp->value;
		q->front = q->front->next;
		q->size -= 1;

		free(tmp);

		return n;
	}
}

int size (Queue *q) {
	return q->size;
}

int empty(Queue *q) {
	if( q->size == 0) {
		return 1;
	} else  return 0;
}

int front(Queue *q) {
	if(q->size == 0) {
		return -1;
	} else {
		return q->front->value;
	}
}

int back(Queue *q) {
	if(q->size == 0) {
		return -1;
	} else return q->back->value;
}

int main() {	

	Queue q;
	int n, value,i;
	char instruction[10];

	q.size = 0;

	scanf("%d", &n);

	for(i=0 ; i<n ;i++) {
		scanf("%s",instruction);
		fflush(stdin);
		if(!strcmp(instruction,"push")) {
			scanf("%d",&value);
			push(&q, value);

		} else if(!strcmp(instruction,"pop")) {
			printf("%d\n", pop(&q));

		} else if(!strcmp(instruction,"size")) {
			printf("%d\n", size(&q));
		} else if(!strcmp(instruction,"empty")) {
			printf("%d\n", empty(&q));
		} else if(!strcmp(instruction,"front")) {
			printf("%d\n", front(&q));
		} else if(!strcmp(instruction,"back")) {
			printf("%d\n", back(&q));
	 	} else continue;
	}



	return 0;
}