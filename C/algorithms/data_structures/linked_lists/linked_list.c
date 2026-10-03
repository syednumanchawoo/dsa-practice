#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};



void push(struct Node **head, int data){
    struct Node *newNode = malloc(sizeof(struct Node));

    if(newNode == NULL)
        return;

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void print(struct Node *node){
    while(node != NULL){
        printf("%d ", node -> data);
        node = node ->next;
    }
}

void append(struct Node **head, int data){
    struct Node *new_node = malloc(sizeof(struct Node));
    struct Node *last = *head;

    new_node->data=data;
    new_node->next= NULL;

    if(*head == NULL){
        *head == new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }
    last -> next = new_node;
}
