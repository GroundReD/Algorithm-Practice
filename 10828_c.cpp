//10828_c.cpp

#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct NODE {
	int value;
	NODE *next;
}node;

typedef struct STACK{
	NODE *top;
	int size;
}stack;

void push(stack *st, int n) {
	node *tmp = (node *)malloc(sizeof(node));
	tmp->value = n;

	if(st->size == 0) {
		st->top = tmp;
		st->size += 1;
	} else {
		tmp->next = st->top;
		st->top = tmp;
		st->size +=1;
	}
}

int pop(stack *st) {
	int n = 0;
	node *tmp;
	if(st->size == 0) {
		return -1;
	} else {
		tmp = st->top;
		n = tmp->value;
		st->top = tmp->next;
		st->size--;
		free(tmp);
		return n;
	}

}

int size (stack *st) {
	return st->size;
}

int empty(stack *st) {
	if(st->size == 0) {
		return 1;
	} else return 0;
}

int top (stack *st) {
	if(st->size == 0) {
		return -1;
	}

	return st->top->value;
}
int main() {
	
	stack st;
	int n;
	int i, value;
	char instruction[10];

	st.top = NULL; 
	st.size = 0;

	
	scanf("%d",&n);

	for(i = 0 ; i < n ; i++) {
		scanf("%s",instruction);
		fflush(stdin);
		if(!strcmp(instruction,"push")) {
			scanf("%d",&value);
			fflush(stdin);
			push(&st,value);

		} else if (!strcmp(instruction,"top")) {
			printf("%d\n",top(&st));
		} else if(!strcmp(instruction,"size")) {
			printf("%d\n",size(&st));
		} else if (!strcmp(instruction,"empty")){
			printf("%d\n",empty(&st));
		} else if (!strcmp(instruction,"pop")) {
			printf("%d\n",pop(&st));
		} else  continue;

	}
	


	return 0;
}