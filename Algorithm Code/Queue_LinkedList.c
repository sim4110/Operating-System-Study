//Linked List Circular Queue
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct Node{
    int data;
    struct Node*next;
}Node;

typedef struct{
    Node*front;
    Node*rear;
}Queue;

void initQueue(Queue*q);
void enQueue(Queue*q, int input);
void deQueue(Queue*q);

int isEmpty(Queue*q);

int main(void){
    Queue q;

    initQueue(&q);

    enQueue(&q, 2);
    enQueue(&q, 4);
    enQueue(&q, 13);
    enQueue(&q, 11);

    deQueue(&q);
    deQueue(&q);
    deQueue(&q);
    deQueue(&q);

    return 0;
}


void initQueue(Queue*q){
    q->front = NULL;
    q->rear = NULL;
}

void enQueue(Queue*q, int input){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = input;

    if(isEmpty(q)){
        q->front = newNode;
    }
    else{
        q->rear->next = newNode;
    }

    q->rear = newNode;
}

void deQueue(Queue*q){
    int output;

    if(!isEmpty(q)){
        Node*tmp = (Node*)malloc(sizeof(Node));
        tmp = q->front;
        output = tmp->data;
        printf("output : %d\n", output);

        q->front = tmp->next;

        free(tmp);
    }
    else printf("Queue is Empty\n");
}

int isEmpty(Queue*q){
    if(q->rear == NULL){
        return TRUE;
    }
    return FALSE;
}