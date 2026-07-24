#include "bank.h"

// إنشاء عقدة جديدة 🧱
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

// تهيئة الطابور والمكدس ⚙️
void init_queue(Queue *q) {
    q->front = NULL; 
    q->rear = NULL; 
} 

void init_stack(Stack *s) {
    s->top = NULL; 
} 

// إضافة عميل لآخر الطابور 🎟️
void enqueue(Queue *q, Node *newNode) {
    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// سحب عميل من أول الطابور 🚪
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

// إضافة عميل لأعلى المكدس 🥞
void push(Stack *s, Node *newNode) {
    newNode->next = s->top;
    s->top = newNode;
}

// سحب عميل من أعلى المكدس 🔄
Node *pop(Stack *s) {
    if (s->top == NULL) {
        return NULL;
    } 

    Node *temp = s->top; 
    s->top = s->top->next; 
    return temp; 
}

// إرجاع عميل لمقدمة الطابور (عند التراجع) ↩️
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
