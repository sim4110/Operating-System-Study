//Array Queue
#include<stdio.h>
#define MAX 100

typedef struct{
    int data[MAX];
    int front, rear;
}Queue;

void initQueue(Queue*q);
void enQueue(Queue*q, int input);
void deQueue(Queue*q);
int isFull(Queue*q);
int isEmpty(Queue*q);

int main(void){
    Queue q;

    initQueue(&q);
    // printf("front : %d  rear: %d \n", q.front, q.rear);

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
    q->front = -1;
    q->rear = -1;
}

void enQueue(Queue*q, int input){
    if(!isFull(q)){
        q->rear++;
        q->data[q->rear]= input;
    }
    else printf("Queue is Full\n");
}

void deQueue(Queue*q){
    if(!isEmpty(q)){
        q->front++;
        int output = q->data[q->front];
        printf("output : %d\n", output);
    }
    else printf("Queue is Empty\n");
}

int isFull(Queue*q){
    if(q->rear == MAX-1){
        return 1;
    }
    return 0;
}

int isEmpty(Queue*q){
    if(q->rear == -1){
        return 1;
    }
    return 0;
}