#include <stdio.h>
#include <limits.h>
#define CAP 100

typedef struct{
    int arr[CAP];
    int top;
}Stack;

void init(Stack *S){S->top=-1;}

int isEmpty(const Stack *S){return (S->top==-1);}
int isFull(const Stack *S){return (S->top == CAP-1);}

void push(Stack *S, int data){
    if(isFull(S)){
        printf("Overflow\n");
        return;
    }
    S->arr[++S->top] = data;
}

int pop(Stack *S){
    if(isEmpty(S)){
        printf("Underflow\n");
        return INT_MIN;
    }
    return (S->arr[S->top--]);
}

int peek(const Stack*S){
    return isEmpty(S) ? INT_MIN : S->arr[S->top];
}

