#include <stdio.h>
#include <stdlib.h>
typedef struct node
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
    List *L = Initialize();
    insertFirst (L, 5);
    insertFirst (L, 50);
    insertFirst (L, 500);
    insertLast (L, 20);
    display(L);
}

List* Initialize(){
    List *L1;
L1 = malloc(sizeof(List));

if (L1 == NULL){
    printf ("WA NIGANAAA !!!");
    return NULL;
}
L1->head = NULL;
L1->count = 0;
    return L1;
}
void empty (List *list);
void insertFirst(List *list, int data){
    Node *newnode = malloc (sizeof(Node));
    newnode->data = data;
    newnode->next = list->head;
    list->head = newnode;
    list->count++;
};
void insertLast(List *list, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL){
        list->head = newNode;
    }else
    {
        Node *current = list->head;
        while (current->next != NULL)
        {
            current->next = newNode;
        }
    }
    list ->count++;
}
void insertPos (List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list){
    Node* current = list->head;

    while (current != NULL)
    {
        printf ("%d -> ", current->data);
        current = current->next;
    }
    
}
