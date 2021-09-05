//Queue
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *ArrPointer;
    int sz;
    int front;
    int end;
}Queue;

void createQueue(Queue *q, int size) {
    if(size <= 0) {
        printf("Enter valid size!\n");
        return;
    }
    q->sz = size;
    q->front = -1;
    q->end = -1;
    q->ArrPointer = (int *)malloc(sizeof(int)*q->sz);
}    
    
void add_to_queue(Queue *q, int element) {
    if(q->end == q->sz-1) {//queue is full
        printf("Queue is full!!\n");
        return;
    }
    
    
    q->front = (q->front == -1) ? q->front + 1 : q->front;
    q->end = q->end + 1;
    q->ArrPointer[q->end] = element; 
    
}

int remove_from_queue(Queue *q) {
    if(q->front == -1){//queue is empty
        printf("Queue is empty!!\n");
        return -1;
    }
    
    q->front = q->front + 1;
    return q->ArrPointer[q->front - 1];
    
}

void print(Queue *q) {
    if(q->front == -1) {
        return;
    }
    
    for(int i = q->front; i <= q->end; i++) {
        printf("%d ", q->ArrPointer[i]);
    }
    printf("\n");
}

int main() {
    
    Queue q;
    Queue *qPtr = &q;
    createQueue(qPtr, 5);
    add_to_queue(qPtr, 1);
    add_to_queue(qPtr, 2);
    add_to_queue(qPtr, 3);
    add_to_queue(qPtr, 4);
    remove_from_queue(qPtr);
    remove_from_queue(qPtr);
    remove_from_queue(qPtr);
    //remove_from_queue(qPtr);
    add_to_queue(qPtr, 8);
    print(qPtr);
    
    return 0;
}
