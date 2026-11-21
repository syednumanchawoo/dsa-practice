#include <stdio.h>
#include <stdlib.h>

struct SNode{
    int data;
    struct SNode *next;
};

typedef struct {
    struct SNode *top;
} Stack;

void push(Stack *S, int value) {
    struct SNode *n = malloc(sizeof(*n));
    if (n == NULL) {
        printf("Overflow (malloc failed)\n");
        return;
    }
    n->data = value;
    n->next = S->top;
    S->top = n;
}

int pop(Stack *S){
    if (S->top == NULL){
        printf("Underflow\n");
        return INT_MIN;
    }

    struct SNode *temp = S->top;
    int value = temp->data;
    S->top = S->top->next;
    free(temp);
    return value;
}
