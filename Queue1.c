#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
typedef struct
{
    int items[MAX];
    int count;
}List;

typedef struct
{
    List list;
    int front;
    int rear;
}Queue;


Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main (){
    Queue *q = initialize();
    enqueue(q, 5);
    enqueue(q, 15);
    enqueue(q, 25);
    dequeue(q);
    
}
Queue* initialize(){
    Queue *q = malloc (sizeof(Queue));
    q->list.count = 0;
    q->rear = -1;
    q->front = -1;
    return q;
}
bool isFull(Queue* q){
    if (q->list.count == MAX){
        return true;
    }
    return false;
}
bool isEmpty(Queue* q){
    if (q->list.count == 0){
        return true;
    }
    return false;
}
void enqueue(Queue* q, int value){
   if (isFull(q)){
       printf ("Is Full");
       return;
   }
   if (isEmpty(q)){
       q->rear = 0;
       q->front = 0;
   }else{
       q->rear = (q->rear + 1) % MAX;
   }
   q->list.items[q->rear] = value;
   q->list.count++;
   display(q);
}
int dequeue(Queue* q){
    if (isEmpty(q)){
        printf ("Queue is Empty\n");
        return -1;
    }
    int val = q->list.items[q->front];
    if (isFull(q)){
        q->rear = -1;
        q->front = -1;
    }else{
      q->front = (q->front + 1) % MAX;  
    }
    q->list.count--;
    return val;
    display(q);
}
int front(Queue* q);
void display(Queue* q){
    if (isEmpty(q)){
        printf ("Queue is Empty");
        return;
    }
    int i = q->front;
    int count = 0;
    while (count < q->list.count){
        printf ("%d ,", q->list.items[i]);
        i = (i + 1) % MAX;
        count++;
    }
    printf ("\n");
}