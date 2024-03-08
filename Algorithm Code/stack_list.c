#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node*list;
}Node;

typedef struct Stack{
    Node*top;
}Stack;

void push(Stack*s, int data);
void pop(Stack*s);

int main(void){
    Stack s;
    s.top =NULL;

    push(&s,2);
    push(&s,4);
    push(&s,13);
    push(&s,1);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    
    return 0;
}


void push(Stack*s, int num){
    Node*nextNode=(Node*)malloc(sizeof(Node));
    
    nextNode->data = num;
    nextNode->list = s->top;
    s->top = nextNode;
    return;
}

void pop(Stack*s){
    if(s->top ==NULL){
        printf("Stack is Empty\n");
        return;
    }
    Node*tmp = s->top;
    int num = tmp->data;
    printf("%d\n",num);

    s->top = tmp->list;
    free(tmp);
    return;
}
