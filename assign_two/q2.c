//Empty descending stack
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int *ArrPointer;
    int top;
    int size;
}Stack;

void createStack(Stack *stk, int sz) {
    if(sz <= 0) {
        printf("Enter valid size!!\n");
        return;
    }
    stk->size = sz;
    stk->top = sz;
    stk->ArrPointer = (int *)malloc(sizeof(int)*sz);
}
    
void push(Stack *stk, int element) {
    if(stk->top == -1) {
        printf("Stack overflow!!\n");
        return;
    }    
    if(stk->top == stk->size) {
        stk->top = stk->size-1;
    }
    
    stk->ArrPointer[stk->top] = element;
    stk->top = stk->top - 1;
}

int pop(Stack *stk) {
    if(stk->top == stk->size-1) {
        printf("Stack underflow!!\n");
        return -1;
    }
    int retval = stk->ArrPointer[stk->top];
    stk->top = stk->top + 1;
    return retval;
}

void print(Stack *stk) {
    if(stk->top == stk->size) {return;}
    for(int i = stk->top+1; i <stk->size ; i++) {
        printf("%d ", stk->ArrPointer[i]);
    }
    printf("\n");
}

int main()
{
    Stack stk;
    Stack *stkPtr = &stk;
    createStack(stkPtr, 5);
    push(stkPtr, 1);
    push(stkPtr, 2);
    push(stkPtr, 3);
    pop(stkPtr);
    //pop(stkPtr);

    print(stkPtr);
    return 0;
}
