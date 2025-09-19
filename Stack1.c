#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
typedef struct
{
    int items[MAX];
    int top;
}Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int top(Stack *s);
void display(Stack* s);
int main (){
    Stack *s = initialize();
    push (s, 5);
    push (s, 15);
    push (s, 25);
    display(s);
    pop(s);
    display(s);
    int top = peek(s);
    printf ("%d\n", top);
}
Stack* initialize(){
//Allocate memory for a Stack structure
//Initialize the top of the stack to -1 to indicate it's empty
//Return the pointer to the stack
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}
bool isFull(Stack* s){
    if (s->top == MAX - 1){
        return true;
    }
    return false;
}
bool isEmpty(Stack* s){
    if (s->top == -1){
        return true;
    }
    return false;
}
void push(Stack* s, int value){
//Check if the stack is full
//Increment the top
//Place the new value at the current top position
    if (isFull(s)){
        printf ("Stack is full\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}
int pop(Stack* s){
    int value;
//Check if the stack is empty
//Get the value at the current top of the stack
//Decrement the top
//Return the retrieved v
    if (isEmpty(s)){
        printf ("Stack is empty\n");
        return -1;
    }
    value = s->items[s->top];
    s->top--;
    return value;
}
int peek(Stack* s){
//Check if the stack is empty (top == -1)
//Return the value at the top of the stack
if (isEmpty(s))
{
     printf ("Stack is empty\n");
     return -1;
}
    return s->items[s->top];
}
int top(Stack *s){
    return s->top;
}
void display(Stack* s){
    if (isEmpty(s)){
        printf ("Stack is empty\n");
        return;
    }
    for (int i = s->top; i >= 0; i--)
    {
        printf ("%d \n", s->items[i]);
    }
    printf ("\n");
    
}