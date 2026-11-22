#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define CAP 100

typedef struct{
    char arr[CAP];
    int top;
}Stack;

void init(Stack *S){S->top=-1;}

int isEmpty(const Stack *S){return (S->top==-1);}
int isFull(const Stack *S){return (S->top == CAP-1);}

void push(Stack *S, char data){
    if(isFull(S)){
        printf("Overflow\n");
        return;
    }
    S->arr[++S->top] = data;
}

char pop(Stack *S){
    if(isEmpty(S)){
        printf("Underflow\n");
        return '\0';
    }
    return (S->arr[S->top--]);
}

char peek(const Stack*S){
    return isEmpty(S) ? '\0' : S->arr[S->top];
}

int precedence(char op){
    if(op == '^') return 3;
    if(op == '*' || op == '/' || op == '%') return 2;
    if(op == '+' || op == '-') return 1;

    return 0;
}

void infix_to_postfix(const char *infix, char *postfix){
    Stack s;
    init(&s);
    int j=0;

    for(int i=0; infix[i] != '\0'; i++){
        unsigned char c = infix[i];

        if(isalnum(c)){
            postfix[j++] = c;
            continue;
        }

        if(isspace(c)){
            continue;
        }

        if(c == '('){
            push(&s, c);
            continue;
        }

        if(c == ')'){
            while (!isEmpty(&s) && peek(&s) != '('){
                postfix[j++] = pop(&s);
            }
            pop(&s);
            continue;
        }


        while(peek(&s) != '(' && precedence(c) <= precedence(peek(&s)) && c != '^'){
            postfix[j++] = pop(&s);
        }

    
        push(&s, c);
    }
    while(!isEmpty(&s)){
                postfix[j++] = pop(&s);
            }
    postfix[j] = '\0';
}
