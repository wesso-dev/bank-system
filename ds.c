#include "bank.h"


Node *createNode(int id, const char *name, const char *problem) {
    Node *newNode = (Node *) malloc(sizeof(Node)); 
    
    if (newNode == NULL) {
        printf("فشل حجز الذاكرة!\n");
        return NULL;
    }

    newNode->id = id; 
    strcpy(newNode->name, name); 
    strcpy(newNode->problem, problem); 
    newNode->next = NULL; 
    
    return newNode; 
}


void init_queue(Queue *q) {
    q->front = NULL; 
    q->rear = NULL; 
} 

void init_stack(Stack *s) {
    s->top = NULL; 
    s->count = 0; //  تهيئة عداد العناصر داخل المكدس
} 


void enqueue(Queue *q, Node *newNode) {
    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}


Node *dequeue(Queue *q) {
    if (q->front == NULL) {
        return NULL;
    } 

    Node *temp = q->front; 
    q->front = q->front->next; 

    if (q->front == NULL) {
        q->rear = NULL;
    } 

    return temp; 
}


void push(Stack *s, Node *newNode) {
    if (newNode == NULL) return;

    newNode->next = s->top;
    s->top = newNode;
    s->count++; // زيادة العداد


    if (s->count > 20) {
        Node *current = s->top;
        
        
        while (current->next != NULL && current->next->next != NULL) {
            current = current->next;
        }

        if (current->next != NULL) {
            Node *oldestNode = current->next;
            current->next = NULL;
            free(oldestNode); //  تحرير الذاكرة
            s->count = 20;
    
        }
    }
}


Node *pop(Stack *s) {
    if (s->top == NULL) {
        return NULL;
    } 

    Node *temp = s->top; 
    s->top = s->top->next; 
    temp->next = NULL; 
    s->count--;        // تقليل العداد عند السحب
    
    return temp; 
}


void enqueue_at_front(Queue *q, Node *newNode) {
    if (q->front == NULL) {
        q->front = newNode; 
        q->rear = newNode; 
        newNode->next = NULL;
    } else {
        newNode->next = q->front; 
        q->front = newNode; 
    }
}
