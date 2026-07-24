#ifndef BANK_H
#define BANK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. تعريف هياكل البيانات (Structs) 🏗️
typedef struct Node {
    int id;
    char name[50];
    char problem[100];
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

typedef struct Stack {
    Node *top;
    int count;
} Stack;

// 2. الإعلان عن دوال هياكل البيانات 📜
Node *createNode(int id, const char *name, const char *problem);
void init_queue(Queue *q);
void init_stack(Stack *s);
void enqueue(Queue *q, Node *newNode);
Node *dequeue(Queue *q);
void push(Stack *s, Node *newNode);
Node *pop(Stack *s);
void enqueue_at_front(Queue *q, Node *newNode);
void saveCustomerToFile(int id, const char *name, const char *problem);
void searchByIdInFile(int searchId);
void searchByNameInFile(const char *searchName);
#endif
