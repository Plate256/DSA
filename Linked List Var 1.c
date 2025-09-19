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
insertFirst(L, 5);
insertFirst(L, 10);
insertFirst(L, 15);
insertLast (L, 20);
display(L);
}

List* Initialize(){
    List *L1;
L1 = malloc(sizeof(List));

if (L1 == NULL){
    printf ("Allocation Failed");
    return NULL;
}
L1->head = NULL;
L1->count = 0;
    return L1;
}
void empty (List *list);
void insertFirst(List *list, int data){
    //Allocate memory for a new node
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        printf ("Allocation Failed");
        return;
    }
    //Set the data of the new node to the provided data
    newNode->data = data;
    //Set the next pointer of the new node to the current head of the list
    newNode->next = list->head;
    //Update the list's head pointer to point to the new node
    list->head = newNode;
    //Increment the list's count
    list->count++;
}
void insertLast(List *list, int data){
    Node *newNode = malloc (sizeof(Node)); //Allocate memory for a new node  
    newNode->data = data; //Set the data of the new node to the provided data
    newNode->next = NULL; //Set the next pointer of the new node to NULL
    if (list->head == NULL){
        list->head = newNode;//If the list's head is NULL (the list is empty), set the head to the new node
    }
   
    else{
        Node *current = list->head;  //If the list is not empty, create a “current” pointer and initialize it with the head            
   
    while (current->next != NULL){//Traverse the list until current->next is NULL
        current->next = newNode; //Set current->next to the new node
    }
    }
     list->count++; //Increment the list's count
}
void insertPos (List *list, int data, int index){
    //Index must be valid (less than list->count)
    if (index > list->count){
        printf ("Index is Invalid");
        return;
    }
//If index is 0, call insertFirst()
//If index is equal to list->count, call insertLast()
//Otherwise, allocate memory for a new Node
//Set the data of the new node
//Create a “current” pointer and initialize it to the head
//Iterate index - 1 times to find the node just before the insertion point
//Set the new node's next pointer to current->next
//Set current->next to the new node
//Increment the list's count
}



void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list){
    //Create a “current” pointer and initialize it to the head
    Node *current = list->head;
    //Begin a loop that continues as long as current is not NULL
    while (current != NULL){
        printf ("%d, ", current->data);
        current = current->next;
    }
    //Inside the loop, print the data from current 
    //Move current to current->next
    
}
