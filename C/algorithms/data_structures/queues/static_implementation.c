/*
Conventions: 1. front == rear == -1 -> EMPTY QUEUE
             2. rear points to last inserted element
*/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define CAP 4

typedef struct {
    int arr[CAP];
    int front;
    int rear;
}Queue;

void init(Queue *Q){
    Q->front = -1;
    Q->rear = -1;
}

bool isEmpty(const Queue *Q){
    return (Q->front == -1);
}

bool isFull(const Queue *Q){
    return ((Q->rear+1) % CAP == Q->front);
}

void enqueue(Queue *Q, int data){
    if(isEmpty(Q)){
        Q->arr[++Q->rear] = data;
        Q->front++;
        return;
    }

    if(isFull(Q)){
        printf("Overflow\n");
        return;
    }
    Q->rear = (Q->rear + 1) % CAP; 
    Q->arr[Q->rear] = data;
}

int dequeue(Queue *Q){
    if(isEmpty(Q)){
        printf("Underflow\n");
        return INT_MIN;
    }
    int temp = Q->arr[Q->front];

    if(Q->front == Q->rear){
        Q->front = -1;
        Q->rear = -1;
    }
    else{
        Q->front = (Q->front+1) % CAP;
    }
    return temp;
}

int peek(const Queue *Q){
    if(isEmpty(Q)){
        printf("Empty Queue\n");
        return INT_MIN;
    }

    return(Q->arr[Q->front]);
}

void display(const Queue *Q){
    if(isEmpty(Q)){
        printf("Empty Queue\n");
        return;
    }

    int i=Q->front;

    do{
        printf("%d ", Q->arr[i]);
        i = (i + 1) % CAP;
    }while(i != (Q->rear+1)%CAP);
    printf("\n");
}
