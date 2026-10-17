#include <stdio.h>
#define MAX 100

typedef struct{
    int data[MAX];
    int top;
}Stack;

void init(Stack *s) {s->top = -1;}
int isEmpty(Stack *s) {return s->top == -1;}
int isFull(Stack *s) {return s->top == MAX - 1;}

void push(Stack *s, int x){
    if(isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = x;
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s -> top--];
}

int peek(Stack *s){
    if(isEmpty(s)){
        return -1;
    }
    return s -> data[s -> top];
}

