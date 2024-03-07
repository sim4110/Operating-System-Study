//Array
#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define Error_Value -1;

typedef struct{
    int front;
    int back;
    int size;
    int data[MAX];
}Queue;

void Initialize(Queue *que){
    que -> front =0;
    que -> back =0;
    que -> size =0;
}

void Add(Queue *que, int value){
    if(que -> size >= 100){
        printf("Queue is Full\n");
        return;
    }
    else{
        que -> size++;
        que -> data[que -> back] =value;
        que -> back = (que -> back+1)%(MAX-1);
    }
}
int Remove(Queue *que){
    int value;
    if(que -> size <=0){
        printf("Queue is Empty\n");
        return Error_Value;
    }
    else{
        que -> size--;
        value = que -> data[que -> front];
        que -> front = (que -> front+1)%(MAX-1);
    }
    return value;
}

int Front(Queue *que){
    return que->data[que->front];
}

int Back(Queue *que){
    return que->data[que->back-1];
}

int RemoveBack(Queue *que){
    int value;
    if(que -> size <=0){
        printf("Queue is Empty\n");
    }
    else{
        que ->size--;
        value = que->data[que->back-1];
        que->back = (que->back -1)%(MAX-1);
    }
    return value;
}

int Queue_IS_Empty(Queue *que){
    return que->size==0;
}

int Que_Size(Queue *que){
    return que->size;
}

//Test Code
int main()
{
    Queue que;

    Initialize(&que);

    Add(&que, 1);
    Add(&que, 2);
    Add(&que, 3);
    Add(&que, 4);
    Add(&que, 5);
    Remove(&que);
    RemoveBack(&que);

    Que_Size(&que);
    printf("Queue Size: %d\n", Que_Size(&que));

    
    printf("Front: %d\n", Front(&que));

    
    printf("Back: %d\n", Back(&que));

    return 0;

}