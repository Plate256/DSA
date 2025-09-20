#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int data;
    struct Node * next;
}Node;
typedef struct Stack
{
    Node* top;
}Stack;


Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

int main (){

}
Stack* initialize(){
    Stack *s = malloc (sizeof(Stack));
    s->top = NULL;
    return s;
}
bool isFull(Stack* s){
    return false;
}
bool isEmpty(Stack* s){
    if (s->top == NULL){
        return true;
    }
    return false;
}
void push(Stack* s, int value){
    Node *newNode = malloc (sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}
int pop(Stack* s){
    if (isEmpty);
    {
       printf ("Stack Is Empty");
        return -1;
    }
    Node *temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free (temp);
    return value;
    
}
int peek(Stack* s){
    if (isEmpty(s))
    {
        printf ("Stack is Empty\n");
        return -1;
    }
    return s->top->data;
}
void display(Stack* s){
    if (isEmpty(s))
    {
        printf ("Stack is Empty\n");
        return -1;
    }
    Node *trav = s->top;
    while (trav != NULL)
    {   
        printf ("%d -> ", trav->data);
        trav = trav->next;
    }
    
}