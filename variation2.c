#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;
void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main (){
    EPtr L = malloc(sizeof(Etype));
    initialize (L);
    insertPos(L, 8, 1);
    insertPos(L, 2, 0);
    insertPos(L, 3, 1);
    insertPos(L, 4, 1);
    deletePos(L, 1);
    locate (L,3);
    insertPos(L, 5, 1);
    insertPos(L, 6, 1);
    retrieve (L, 1);
    insertSorted(L,3);
    makeNULL(L);
    insertPos(L, 5, 0);
    insertPos(L, 6, 1);
}
void initialize(EPtr L){
    L->count = 0;
}
void insertPos(EPtr L, int data, int position){
    int valid = 1;
    if (position < 0 || position > L->count){
        printf ("Position is Invalid");
        printf ("\n");
        valid = 0;
    }
    if (L->count == MAX){
        printf ("List is full");
        valid = 0;
    }
    if (valid)
    {
    for (int i = L->count - 1; i >= position; i--){
        L->elem[i + 1] = L->elem[i];
    }
    L->elem[position] = data;
    L->count++;
    }
    display(L);
}
void deletePos(EPtr L, int position){
 int valid = 1;
    if (position < 0 || position > L->count){
     printf ("Position is Invalid");
     valid = 0;
 }
    if (MAX == L->count){
     printf ("List is Full");
     valid = 0;
 }  
    if (valid){
        for (int i = position; i <= L->count - 1; i++){
            L->elem[i] = L->elem[i + 1];
        }
    }
    L->count--;
    display(L);
}
int locate(EPtr L, int data){
    for (int i = 0; i < L->count; i++){
        if (data == L->elem[i]){
            printf ("\nElement is at %d", i);
            printf ("\n");
            return i;
        }
    }
    return -1;
}
int retrieve(EPtr L, int position){
    int valid = 1;
    if (position < 0 || position > L->count){
        printf ("Invalid Position");
        valid = 0;
    }
    if (valid){
        
        printf ("\nRetrieved %d at position %d", L->elem[position], position);
    }
    }
void insertSorted(EPtr L, int data){
    int pos = 0;
    while (pos < L->count && L->elem[pos] < data){
        pos++;
    }
    for (int i = L->count; i >= pos; i--){
        L->elem[i + 1] = L->elem[i];
    }
    L->elem[pos] = data;
    L->count++;
    display(L);
}
void display(EPtr L){
    printf ("\n");
for (int i = 0; i < L->count; i++)
    {
        printf ("%d, ", L->elem[i]);
    }
}
void makeNULL(EPtr L){
    L->count = 0;
}
