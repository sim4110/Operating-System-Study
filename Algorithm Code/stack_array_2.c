#include<stdio.h>

void isEmpty();
int isFull();
void push(int n);
void pop();

int stack_p = -1;
int stack[1000000];

int main(void) {

    push(2);
    push(4);
    push(13);
    push(1);
    pop();
    pop();
    pop();
    pop();

	return 0;
}

void isEmpty() {
	if (stack_p == -1) printf("1\n");
	else printf("0\n");
}

int isFull() {
	if (stack_p == 1000000) return 1;
	else return 0;
}

void push(int n){
	if (!isFull()) {
		stack[++stack_p] = n;
	}
//	else printf("error:stack is full...\n");
}
void pop() {
	if (stack_p == -1) printf("-1");
	else {
		printf("%d\n", stack[stack_p]);
		stack_p--;
	}
}