//Circular queue
#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue {
    int sz; 
    int front;
    int end;
    int *ArrPointer;
    
}CircularQueue;

void createCircularQueue(CircularQueue *q, int size) {
    if(size <= 0) {
        printf("Enter valid size!!\n");
    }
    q->sz = size + 1;
    q->ArrPointer = (int *)malloc(sizeof(int)*q->sz);
    q->front = 0;//no element is stored at the location of front hence we need 1 extra space 
    q->end = 0;
}
    
void add_to_queue(CircularQueue *q, int element) {
    //condtion for queue is full
    if(q->front == (q->end+1)%q->sz) {
        printf("Circular queue is full!!\n");
        return;
    }
    //no need to move front pointer in case of CircularQueue when adding the first element
    q->end = (q->end + 1)%q->sz;
    q->ArrPointer[q->end] = element;
}

int remove_from_queue(CircularQueue *q) {
    //condition for queue is empty
    if(q->front == q->end) {
        printf("Circular queue is empty!!\n");
        return -1;
    }
    //delete using front pointer
    q->front = (q->front + 1)%q->sz;
    return q->ArrPointer[q->front];
}

void print(CircularQueue *q) {
    if(q->end == q->front) {
        return;
    }
    int i = (q->front+1)%q->sz;//start from front+1
    while(1) {
        if(i != q->end) {
            printf("%d ", q->ArrPointer[i]);
            i = (i+1)%q->sz;
        }
        else {
            printf("%d", q->ArrPointer[i]);
            return;
        }
    }
}

int main()
{
    CircularQueue cq;
    CircularQueue *cqPtr = &cq;
    
    createCircularQueue(cqPtr, 3);
    add_to_queue(cqPtr, 1);
    add_to_queue(cqPtr, 2);
    add_to_queue(cqPtr, 3);
    //add_to_queue(cqPtr, 4);
    remove_from_queue(cqPtr);
    //remove_from_queue(cqPtr);
    //remove_from_queue(cqPtr);
    print(cqPtr);

    return 0;
}
