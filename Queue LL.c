#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
typedef struct Queue
{
    Node* front;
    Node* rear;
}Queue;


Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main (){

}

Queue* initialize(){
    Queue *q = malloc (sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
bool isFull(Queue* q){
    return false;    
}
bool isEmpty(Queue* q){
    if (q->front == NULL)
    {
        return true;
    }
    return false;
}
void enqueue(Queue* q, int value){
    Node *newNode = malloc (sizeof(Queue));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q))
    {
        q->front = newNode;
        q->rear = newNode;
    }else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
int dequeue(Queue* q){
    if (isEmpty(q))
    {
        printf ("Queue is Empty\n");
        return -1;
    }
    Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (isEmpty(q)){
        q->rear == NULL;
    }
    free (temp);
    return value;
}
int front(Queue* q);
void display(Queue* q){
    if (isEmpty(q))
    {
        printf ("Queue is Empty\n");
        return;
    }
    Node *trav = q->front;
    while (trav != NULL)
    {
        printf ("%d ->,", trav->data);
        trav = trav->next;
    }
    printf ("\n");
}