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


// AI version for reference

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define CAP 100

typedef struct {
    char arr[CAP];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }
bool is_empty(const Stack *s) { return s->top == -1; }
bool is_full(const Stack *s) { return s->top == CAP - 1; }

bool push(Stack *s, char data) {
    if (is_full(s)) return false;
    s->arr[++s->top] = data;
    return true;
}

char pop(Stack *s) {
    if (is_empty(s)) return '\0';
    return s->arr[s->top--];
}

char peek(const Stack *s) {
    return is_empty(s) ? '\0' : s->arr[s->top];
}

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': case '%': return 2;
        case '+': case '-': return 1;
        default:  return 0;
    }
}

bool is_right_associative(char op) {
    return op == '^';
}

bool infix_to_postfix(const char *infix, char *postfix, size_t out_size) {
    if (out_size == 0) return false;

    Stack s;
    init(&s);
    size_t j = 0;

    for (size_t i = 0; infix[i] != '\0'; i++) {
        unsigned char uc = (unsigned char)infix[i];
        char c = (char)uc;

        if (isspace(uc)) {
            continue;
        } else if (isalnum(uc)) {
            if (j + 1 >= out_size) return false;
            postfix[j++] = c;
        } else if (c == '(') {
            if (!push(&s, c)) return false;
        } else if (c == ')') {
            while (!is_empty(&s) && peek(&s) != '(') {
                if (j + 1 >= out_size) return false;
                postfix[j++] = pop(&s);
            }
            if (is_empty(&s)) return false;  // unmatched ')'
            pop(&s);                         // discard '('
        } else if (is_operator(c)) {
            while (!is_empty(&s) && peek(&s) != '(' &&
                   (precedence(peek(&s)) > precedence(c) ||
                   (precedence(peek(&s)) == precedence(c) && !is_right_associative(c)))) {
                if (j + 1 >= out_size) return false;
                postfix[j++] = pop(&s);
            }
            if (!push(&s, c)) return false;
        } else {
            return false;  // invalid character
        }
    }

    while (!is_empty(&s)) {
        char top = pop(&s);
        if (top == '(') return false;  // unmatched '('
        if (j + 1 >= out_size) return false;
        postfix[j++] = top;
    }

    postfix[j] = '\0';
    return true;
}

int main(void) {
    const char *tests[] = {
        "A - B + (C * D ^ E ^ F)",
        "A - B * C + D",
        "(A + B) * (C - D) / E ^ F ^ G",
        "A + B)"  // invalid: unmatched ')'
    };

    char postfix[CAP];
    size_t count = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < count; i++) {
        if (infix_to_postfix(tests[i], postfix, sizeof(postfix))) {
            printf("%-32s -> %s\n", tests[i], postfix);
        } else {
            printf("%-32s -> Invalid expression\n", tests[i]);
        }
    }

    return 0;
}
