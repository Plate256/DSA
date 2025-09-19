#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10
typedef struct
{
    int *elemPtr;
    int count;
    int max;
}List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);


int main (){
    List L;
    initialize (&L);
    insertPos(&L, 5, 0);
    insertPos(&L, 15, 1);
    insertPos(&L, 115, 2);
    insertPos(&L, 1115, 3);
    insertSorted(&L, 50);
}
void initialize(List *L){
    L->elemPtr = malloc (sizeof (int) * LENGTH);
    L->max = LENGTH;
    L->count = 0;
}
void insertPos(List *L, int data, int position){
    int valid = 1;
    if (position < 0 || position > L->count){
        printf ("Invalid Position");
        printf ("\n");
        valid = 0;
    }
    if (L->max == L->count){
        resize(L);
    }
    for (int i = L->count - 1; i >= position; i--){
        L->elemPtr[i + 1] = L->elemPtr[i];
    }
    L->elemPtr[position] = data;
    L->count++;
    display(L);
}
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data){
    int pos = 0;
    while (pos < L->count && L->elemPtr[pos] < data){
        pos++;
    }
    for (int i = L->count - 1;i >= pos; i--){
        L->elemPtr[i + 1] = L->elemPtr[i];
    }
    L->elemPtr[pos] = data;
    L->count++;
    display(L);
}
void display(List *L){
    for (int i = 0; i <= L->count - 1; i++){
        printf ("%d, ", L->elemPtr[i]);
    }
    printf ("\n");
}
void resize(List *L){
    int newMax = L->max * 2;
    int *newArray = malloc (sizeof (int) * newMax);
    for (int i = 0; i < L->count; i++){
        newArray[i] = L->elemPtr[i];
    }
    free (L->elemPtr);
    L->max = newMax;
    L->elemPtr = newArray;
}
void makeNULL(List *L){
    L->count = 0;
}


