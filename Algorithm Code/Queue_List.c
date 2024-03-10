//Implementation via sList
#include<stdio.h>
#include<stdlib.h>
#define Error_value -1

typedef struct Queue{
    int value;
    struct Queue *next;
}Queue;

void Print(Queue *tail){
    if(!tail){
        return;
    }

    Queue *head = tail->next;
    printf("%d ", head -> value);
    Queue *current = head -> next;

    while(current !=head){
        printf("%d ",current -> value);
        current = current -> next;
    }
}

int Add(Queue **ptrTail, int value){
    Queue *temp = (Queue*)malloc(sizeof(Queue));

    if(!temp){
        printf("Memory Allocation Error\n");
        return 0;
    }

    Queue *tail = *ptrTail;

    if(!tail){
        temp -> value = value;
        temp -> next = temp;
        *ptrTail = temp;
    }
    else{
        temp -> value = value;
        temp -> next = tail -> next;
        tail -> next = temp;
        *ptrTail = temp;
    }
    return 1;
}
int Remove(Queue **ptrTail){
    Queue *tail = *ptrTail;
    Queue *delete;
    int value;

    if(!tail){
        return Error_value;
    }

    if(tail -> next == tail){
        value=tail->value;
        free(tail);
        *ptrTail = NULL;
        return value;
    }
    delete = tail -> next;
    value = delete->value;
    tail->next = delete -> next;
    free(delete);
    return value;
}

int main(){

    Queue *tail = NULL;
   
    Add(&tail, 1);
    Add(&tail, 2);
    Add(&tail, 3);
  
    for(int i=0; i<3; i++){
        Remove(&tail);
    }

    Print(tail);
    
    return 0;
}
