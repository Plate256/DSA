#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
}List;
List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List  insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main (){
    List L;
    L = initialize (L);
    L = insertPos(L, 5, 0);
    L = insertPos(L, 15, 1);
    L = insertPos(L, 115, 2);
    L = insertPos(L, 1115, 3);
    L = deletePos(L, 1);
    L = insertSorted(L, 20);
    locate (L, 20);
}
List initialize(List L){
    L.elemPtr = malloc(sizeof(int)*LENGTH);
    L.count = 0;
    L.max = LENGTH;
    return L;
}
List insertPos(List L, int data, int position){
    if (position < 0 || position > L.count){
        printf ("Invalid Position");
        printf ("\n");
        return L;
    }
    if (L.max == L.count){
        L = resize(L);
    }
    for (int i = L.count - 1; i >= position; i--){
        L.elemPtr[i + 1] = L.elemPtr[i];
    }
    L.elemPtr[position] = data;
    L.count++;
    display(L);
    return L;
}
List deletePos(List L, int position){
    if (position < 0 || position > L.count){
        printf ("Invalid Position");
        printf ("\n");
        return L;
    }
    for (int i = position; i <= L.count - 1; i++){
        L.elemPtr[i] = L.elemPtr[i + 1];
    }
    L.count--;
    display(L);
    return L;
}
int locate(List L, int data){
    for (int i = 0; i <= L.count; i++){
        if (data == L.elemPtr[i]){
            printf ("Data %d found at position %d", data, i);
            return i;
        }
    }
    return -1;
}
List  insertSorted(List L, int data){
    int pos = 0;
    while (pos < L.count && L.elemPtr[pos] < data){
        pos++;
    }
    for (int i = L.count - 1; i >= pos; i--){
        L.elemPtr[i + 1] = L.elemPtr[i];
    }
    L.elemPtr[pos] = data;
    L.count++;
    display(L);
    return L;
}
void display(List L){
    for (int i = 0; i < L.count; i++){
        printf ("%d, ", L.elemPtr[i]);
    }
    printf ("\n");
}
List resize(List L){
    int newMax = L.max * 2;
    int *newArray = malloc (sizeof (int) * newMax);
    
    for (int i = 0; i < L.count; i++){
        newArray[i] = L.elemPtr[i];
    }
    L.max = newMax;
    L.elemPtr = newArray;
    return L;
}
