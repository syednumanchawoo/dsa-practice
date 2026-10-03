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

void delete(struct Node **head, int key){
    // If list is empty
    if(*head == NULL){
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = temp;
    // If head node contains key
    if(temp -> data == key){
        *head = temp ->next;
        free(temp);
        return;
    }
    
    while(temp != NULL  && temp -> data != key){
        prev = temp;
        temp = temp -> next;
        
    }
    // If key is not found
    if (temp == NULL) return;
    prev -> next = temp -> next;
    free(temp);
}

void free_Linked_List(struct Node **head){
    if(*head == NULL){
        return;
    }
    struct Node *current = *head;
    struct Node *temp;
    
    do{
        temp = current ->next;
        free(current);
        current = temp;
    }while(temp != NULL);
    *head = NULL;
}
