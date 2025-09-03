#include <stdio.h>
#include <stdlib.h>
typedef struct
{
 int data;
 struct node *next;
}Node;
typedef struct
{
    Node *head;
    int count;
}List;

List* Initialize();
void empty (List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos (List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main (){

}

List* Initialize();
void empty (List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos (List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);
